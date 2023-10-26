# ET_Lobo
ETロボコンの走行体(LEGO SPIKE)をSpike-rtの環境で動かすサンプル.

## 各サンプルの機能概要

### brightness_measure
- カラーセンサーで輝度を測定してディスプレイに表示する．
### pid_controller
- 走行体をPID制御でライントレースさせる．
- PWM値指定によりモーターを駆動する．
### go_straight
- 走行体を```pup_motor_set_speed()```で直進させる．

## その他
- モータに負荷(走行体の車重)がかかる状態で```pup_motor_set_speed()```を使用すると，モータの回転速度が安定しない現象を確認している．
    - ライントレースサンプルにはPWM値を指定する関数```pup_motor_set_power()```を使用している．
- ETロボコン用環境(RasPike)について、詳しくは[こちら](https://github.com/ETrobocon/RasPike)．
- 走行体は、[組立図](https://drive.google.com/file/d/17FyQBsuuXrV4BK-96fgQJy-Ou4NvqLi7/view?usp=sharing)を元に組み立てた．
- プログラム作成の際にはETロボコン2022のサンプルコースを使用した．