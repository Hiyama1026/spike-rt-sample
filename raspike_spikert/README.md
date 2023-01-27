# RasPike互換モジュール

このプロジェクトはRasPikeで使用されるLEGO SPIKEで実行するエージェント
プログラムをSPIKE-RTに移植したものである．

## オリジナルのエージェントプログラム

https://github.com/ETrobocon/RasPike/blob/master/spike/raspike_etrobo.py

<<<<<<< HEAD
# ビルド及び実行

## アプリケーションのビルド

```
$ cd <spike-rtのフォルダ>
$ cd spike-rt-sample/raspike_spikert
$ make
```
=======
## 使用方法
- 本プログラムの実行ファイルをdfuモードでHUBに書き込む．
- raspberry側で制御アプリケーションを実行する．
>>>>>>> 3207652ea549d4cbec861a2eeba5aa02ba343c39

## ハブへのセンサー・モータの接続

FポートとDポートはオリジナルのRasPikeの接続から入れ替える．

- Raspberry PiとSPIKEの接続
	- アームモータ   : A
	- 右モータ       : B
	- 左モータ       : E
	- カラーセンサー : C
	- 超音波センサー : F -> D
	- serial通信     : D -> F

## 不具合の回避
以下の変更を行い，実行中にHUBの電源が落ちないように設定する．
- `spike-rt\external\libpybricks\lib\pbio\platform\prime_hub_spike-rt`の18行目を下記のように変更する．
```
#define PBSYS_CONFIG_BLUETOOTH_ADVERTISE_WHILE_USER_PROGRAM_RUNNING (0)
```


## 実行

オリジナルと同様に起動するとserialを使用してRaspberry Piと通信を開始する．
コンソール出力は，USB経由の仮想COMポートに出力される．


# 処理内容

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

# 設計メモ

- 送信するカラーコードはEV3のカラーコードに合わせた．
	- BROWNは H=40, S=100, V=35 で指定した．
	- LEGO公式APIのカラーコードに合わせた色配列```detect_color_for_lego_official[]```も用意した．
- ```notify_sensor_task()```におけるジャイロ出力のキャリブレーション処理(コマンドID:7)については，キャリブレーション処理のAPIが未実装のため常に0を返すようにしている．
- 本プログラムの作成時点で```hub_light_on_color()```が正常に動作しない不具合が発生しているため，```detect_com_fail()```が呼び出されてもセンターボタンのLEDが点灯しないかもしれない．
- 本プログラムの作成時点で```pup_motor_setup()```の3つ目の引数に```true```を入れてもエンコーダー値がリセットされない不具合が発生しているため，682行目，693行目，及び704行目に```pup_motor_reset_count()```を記述している．
- フロー制御を有効にしていると，raspberryから17や19のデータを受信したときに不具合を起こすことが確認されたため，フロー制御を無効化している(722行目)．
- モーターのPWM値を指定するAPIが公式に追加されていないため，```pup_motor_set_duty_limit()```によりPWM値を指定している．

# 検証を通して分かったこと

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
