# ET_Lobo
ETロボコンの走行体(LEGO SPIKE)をSpike-rtの環境で動かすサンプルです。

## 各サンプルの機能概要
### basic_LT
- 走行体をP制御でライントレースさせる。
- RasPike環境用に用意されたサンプル([sample_c5](https://github.com/ETrobocon/RasPike/tree/master/sdk/workspace/sample_c5))を参考にして作成した。
### basic_LT2
- 走行体をP制御でライントレースさせる。
- basic_LTを```pup_motor_set_speed()```で制御するように書き換えたもの。
- 改良中。
### brightness_measure
- カラーセンサーで輝度を測定してディスプレイに表示する。
### pid_controller_LT
- 走行体をPID制御でライントレースさせる。
### pid_controller_LT2
- 走行体をPID制御でライントレースさせる。
- pid_controller_LTを```pup_motor_set_speed()```で制御するように書き換えたもの。
- 改良中。
### switch_edge_LT
- 走行中に走行エッジを切り替える。
- エンコーダー値を取得し, 左車輪が3回転したら走行エッジを左から右に切り替える。
- ハブに輝度のターゲット値を表示する。
### go_straight
- 走行体を```pup_motor_set_speed()```で直進させる。
### dc_motor_straight
- 走行体をDCモーターで直進させる。
- DCモーターで制御するための関数の動作・挙動の確認に使用した。

## その他
- ETロボコン用環境(RasPike)について、詳しくは[こちら](https://github.com/ETrobocon/RasPike)。
- 走行体は、[組立図](https://drive.google.com/file/d/17FyQBsuuXrV4BK-96fgQJy-Ou4NvqLi7/view?usp=sharing)を元に組み立てました。
- プログラム作成の際にはETロボコン2022のサンプルコースを使用しました。