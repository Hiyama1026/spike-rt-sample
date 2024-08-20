# spike-rt版エージェントプログラム

## 概要
- このプロジェクトはRasPikeで使用されるLEGO SPIKEで実行するエージェントプログラムをSPIKE-RTで実現したものである
- RasPikeの環境構築手順における．SPIKE環境構築の「[PCからSPIKE用プログラムの転送](https://github.com/ETrobocon/RasPike/wiki/spike_setup#pc%E3%81%8B%E3%82%89spike%E7%94%A8%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%A0%E3%81%AE%E8%BB%A2%E9%80%81)」で書き込むプログラムをspike-rtのCプログラムに置き換える
- このプログラムを使用することにより，レスポンスの向上を行う事が可能

## オリジナルのエージェントプログラム
- https://github.com/ETrobocon/RasPike/blob/master/spike/raspike_etrobo.py

## 前提
- spike-rtの環境構築が完了していること
	- [Wiki](https://github.com/Hiyama1026/spike-rt-sample/wiki)などを参照


# 使用方法
- 下記のRasPike開発環境の手順に従い，「全体の流れ」の``2. Raspberry Pi側の環境を構築します。（Raspberry Pi環境構築）``まで実施
	- [https://github.com/ETrobocon/RasPike/wiki/RasPike_install](https://github.com/ETrobocon/RasPike/wiki/RasPike_install)

- RasPike開発環境の手順の「全体の流れ」の[3. SPIKE側の環境を構築します。（SPIKE環境構築）](https://github.com/ETrobocon/RasPike/wiki/spike_setup)**の代わりに以下を実施**
	- spike-rt版エージェントプログラムをビルド
	```
	$ cd ~/spike-rt/spike-rt-sample/raspike_spikert
	$ make
	```
	- HubをDFUモードにする
    	- DFUモード参考：https://www.youtube.com/watch?v=XJ7rltuf3Jc
	- Hubにプログラムを書き込む
    ```
    make deploy-win     # WSL2の場合
    make deploy-lin     # Ubuntu(ネイティブ)の場合
    ```
- RasPike開発環境の手順の「全体の流れ」の``4. Raspberry Piと、SPIKEを接続させます。（Raspberry PiとSPIKEの接続）``を実施
	- **ただし，以下の変更を行う**
	- FポートとDポートはオリジナルのRasPikeの接続から入れ替える．
		- Raspberry PiとSPIKEの接続
			```
			アームモータ   : A
			右モータ       : B
			左モータ       : E
			カラーセンサー : C
			超音波センサー : F -> D		# 変更
			serial通信     : D -> F		# 変更
			```
- 以降はRasPike開発環境の手順の「全体の流れ」に従う


# 実行

- オリジナルのRasPikeと同様に起動するとserialを使用してRaspberry Piと通信を開始する
- コンソール出力は，USB経由の仮想COMポートに出力される（[Tera Term等で見る](https://github.com/Hiyama1026/spike-rt-sample/wiki)事ができる）


# 参考1：spike-rt版エージェントプログラムの性能
- 応答時間の計測を実施
	- カラーセンサが黒を検知したらモータを停止するプログラムを実行
	- 実際にカラーセンサが黒を検知してから，モータが停止するまでの時間を計測
		- 計測回数は1000回
	- エージェントプログラムに本プログラム(spike-rt)を使用したもの「RasPike-RT」と呼ぶ

<br>

- 結果：平均値・最悪値共にRasPike-RTの方が優れた結果に
	| --- | 応答時間の最悪値(最大値) | 応答時間の平均値 |
	|:--:|:--:|:--:|
	|**RasPike**|61.9 ms|34.7 ms|
	|**RasPike-RT**|53.7 ms|27.3 ms|

# 参考2：処理内容

## 受信処理 : Raspberry Pi -> SPIKE 

- データを受信するとパケット解析を開始

- void receiver_task(intptr_t exinf)
	- 受信タスク
	- オリジナル関数 async def receiver():

## 送信処理 : SPIKE -> Raspberry Pi 

- 10msec毎に送信
- 100msec毎に送信

- void notify_sensor_task(intptr_t exinf)
	- 送信タスク
	- オリジナル関数 sync def notifySensorValues():

# 参考3：設計メモ

- 送信するカラーコードはEV3のカラーコードに合わせた．
	- BROWNは H=40, S=100, V=35 で指定した．
	- LEGO公式APIのカラーコードに合わせた色配列```detect_color_for_lego_official[]```も用意した．
- ```notify_sensor_task()```におけるジャイロ出力のキャリブレーション処理(コマンドID:7)については，キャリブレーション処理のAPIが未実装のため常に0を返すようにしている．
- 本プログラムの作成時点で```hub_light_on_color()```が正常に動作しない不具合が発生しているため，```detect_com_fail()```が呼び出されてもセンターボタンのLEDが点灯しないかもしれない．
- 本プログラムの作成時点で```pup_motor_setup()```の3つ目の引数に```true```を入れてもエンコーダー値がリセットされない不具合が発生しているため，680行目，691行目，及び702行目に```pup_motor_reset_count()```を記述している．
- フロー制御を有効にしていると，raspberryから17や19のデータを受信したときに不具合を起こすことが確認されたため，フロー制御を無効化している(725行目)．
- モーターのPWM値を指定するAPIが公式に追加されていないため，```pup_motor_set_duty_limit()```によりPWM値を指定している．

# 参考4：検証を通して分かったこと

- RasPike環境を用いたときとSpike-RTを使用したときで，カラーセンサーが返すReflect値が異なる．
	- どちらも機能的にはReflect値を出力しているような振る舞いをする．
	- 検証方法
		- 白と黒を印刷した紙を用意する．
		- カラーセンサーを紙面から1.5cm離した所で固定し，Reflect値を計測する．
		- 出力はどちらもraspberry側のアプリケーションプログラムでprint()により行う．
	- 検証結果
		- RasPike：白 = 95，黒 = 13
		- Spike-RT：白 = 53　黒 = 5
- RasPike環境を用いたときとSpike-RTを使用したときで，カラーセンサーが返すAmbient値が異なる．
	- どちらも機能的にはAmbient値を出力しているような振る舞いをする．
	- 検証方法
		- カラーセンサーを2つ用意して，1つを光源用にし，もう1つをAmbient値の測定用にする．
		- 2つのカラーセンサーを向かい合わせるようにして固定する．
		- 出力はどちらもraspberry側のアプリケーションプログラムでprint()により行う．
	- 計測値の計算方法
		- raspberry上でAmbient値を取得・出力するアプリケーションを実行し，適当な時間が経過した後に実行を止める.
		- 最後に出力された値から順にさかのぼり、30個の数値を抽出する.
		- 抽出した数値の(最大値+最小値)/2で計算する.
	- 検証結果は下記の表のようになった．

| 光源との距離(cm) | RasPikeでの測定値 | Spike-RTでの測定値 |
|:--:|:--:|:--:|
|1|25|83|
|2|24|83|
|3|24|82|
|4|24|82|
|5|24|55|
|6|25|44|
|7|25|35|
|8|25|28|
|9|25|24|
|10|21|20|
|11|19|18|
|12|16|15|
|13|15|14|
|光源OFFのとき|2|2|

## 不具合の回避(spike-rt v0.2.0では改善済み)
- **spike-rt v0.2.0では改善されている為，実施する必要はない**
- 以下の変更を行い，実行中にHUBの電源が落ちないように設定する．
	- [spike-rt/external/libpybricks/lib/pbio/platform/prime_hub_spike-rt/pbsysconfig.h](https://github.com/spike-rt/pybricks-micropython/blob/31d98c66dde2d935c30d2ae68c0c81c9de8831ca/lib/pbio/platform/prime_hub_spike-rt/pbsysconfig.h)の`PBSYS_CONFIG_BLUETOOTH_ADVERTISE_WHILE_USER_PROGRAM_RUNNING`を0に変更する．
	```
	#define PBSYS_CONFIG_BLUETOOTH_ADVERTISE_WHILE_USER_PROGRAM_RUNNING (0)
	```