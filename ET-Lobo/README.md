# ET_Lobo
ETロボコンの走行体(LEGO SPIKE)をSpike-rtの環境で動かすサンプル.<br>
Raspberrt Piは使用しない．<br>

## 各サンプルの機能概要

### brightness_measure
- カラーセンサーで輝度を測定してディスプレイに表示する．
### pid_controller
- 走行体をPID制御でライントレースさせる．
- PWM値指定によりモーターを駆動する．
### go_straight
- 走行体を```pup_motor_set_speed()```で直進させる．

## 使用方法
- ディレクトリを移動してビルド
    ```
    cd spike-rt-sample/ET-Lobo/[PROJECT-NAME]
    make
    ```
- HubをDFUモードにする
    - DFUモード参考：https://www.youtube.com/watch?v=XJ7rltuf3Jc
- Hubにプログラムを書き込む
    ```
    make deploy-win     # WSL2の場合
    make deploy-lin     # Ubuntu(ネイティブ)の場合
    ```

## その他
- モータに負荷(走行体の車重)がかかる状態で```pup_motor_set_speed()```を使用すると，モータの回転速度が安定しない現象を確認している．
    - ライントレースサンプルにはPWM値を指定する関数```pup_motor_set_power()```を使用している．
- ETロボコン用環境(RasPike)について、詳しくは[こちら](https://github.com/ETrobocon/RasPike)．