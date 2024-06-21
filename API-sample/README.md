# API_sample
## 概要
- APIの挙動を確認するために作成したサンプル
    - (*)が付いたサンプルはサンプルはログの出力あり
- [syslog_bluetooth](./syslog_bluetooth/)以外のsyslogはHub上部のUSB経由

## 各サンプルの概要と使用する主なAPI

### template
新規プロジェクト作成用のテンプレート．<br>
使用方法は下記の[プロジェクト作成用スクリプト](#プロジェクト作成用スクリプト)を参照．<br>
このフォルダ自体は編集しないことを推奨．<br>

### battery1.c　(*)
バッテリーの電流・電圧を取得して表示する．
- ```hub_battery_get_current()```
- ```hub_battery_get_voltage()```
### bluetooth1.c
シリアルインターフェスドライバを使用したサンプル．<br>
bluetooth経由で文字列の送受信を行う．</br>
コンソールは[Pybricks](https://pybricks.com/)のコンソールを使用する．</br>
Hubの電源投入後にPybricksのBluetoothボタンをクリックし，接続する．</br>
（Hubが接続待ち状態のときには「READY」を表示し，接続が完了したらスマイルマークを表示する）
- ```serial_opn_por()```
- ```serial_rea_dat()```
- ```serial_wri_dat()```
### button1.c　(*)
押したボタンをディスプレイに表示する．
- ```hub_button_is_pressed()```
### color1.c　(*)
カラーセンサーでhsv値とrgb値を取得し、読み取ったhsv値、rgb値、及び色の種類を表示する．
- ```pup_color_sensor_get_device()```
- ```pup_color_sensor_hsv()```
- ```pup_color_sensor_color()```
- ```pup_color_sensor_rgb()```
### color2.c
カラーセンサーの各ライトを指定した輝度で点灯する．
- ```pup_color_sensor_light_set()```
### color3.c　(*)
カラーセンサーで反射光の輝度を測定し、ディスプレイとログに出力する．
- ```pup_color_sensor_reflection()```
- ```hub_display_number()```
### color4.c
カラーセンサーで周囲の明るさを測定し、明るさに応じて超音波センサのライトを点灯する．
- ```pup_color_sensor_ambient()```
### color5.c　(*)
カラーセンサーが取得する色を指定し、取得した色を表示する．
- ```pup_color_sensor_detectable_colors()```
### dc_motor1
モーターをDCモーターとして活用する．
- ```pybricks_c_common_dcmotor_make_new()```
- ```pybricks_c_common_dcmotor_duty()```
- ```pybricks_c_common_dcmotor_stop()```
- ```pybricks_c_common_dcmotor_brake()```
### force1.c　(*)
フォースセンサが接触を検知したら、フォースセンサが押されている力(N)を表示する．
- ```pup_force_sensor_get_device()```
- ```pup_force_sensor_touched()```
- ```pup_force_sensor_force()```
- ```pup_force_sensor_distance()```
### imu1.c
IMUが検知した角速度の方向をディスプレイに表示する．
- ```hub_imu_get_angular_velocity()```
### imu2.c
IMUが検知した温度をディスプレイに表示する．
- ```hub_imu_get_temperature()```
### imu3.c　(*)
IMUが検知した加速度を出力する．
- ```hub_imu_get_acceleration()```
### led1.c
ディスプレイに指定した文字や図形を表示する．ピクセルと輝度を指定して点灯する．while文を一周するごとにハブ内蔵ライトの色を切り替える．
- ```hub_display_orientation()```
- ```hub_display_off()```
- ```hub_light_on_color()```
- ```hub_display_number()```
- ```hub_display_text_scroll()```
- ```hub_display_text()```
- ```hub_display_image()```
- ```hub_display_pixel()```
### led2.c
hub_display_char()で文字を出力する．
- ```hub_display_char()```
### led3.c
ハブ内蔵ライトのhsv値を指定して点灯する．
- ```hub_light_on_hsv()```
### motor1.c　(*)
ハブのボタンでモーターを操作する．
- ```pup_motor_get_device()```
- ```pup_motor_set_speed()```
- ```pup_motor_stop()```
- ```pup_motor_brake()```
- ```pup_motor_hold()```
- ```pup_motor_get_speed()```
### motor2.c　(*)
モーターが動かされたらエンコーダー値を取得して出力する．180°以上回るとエンコーダー値をリセットする．
- ```pup_motor_get_count()```
- ```pup_motor_reset_count()```
### motor3.c
モーターがストロールしているのを検知したらモーターをと止める．止まった状態でセンターボタンが押されたらduty値を元に戻す．
- ```pup_motor_set_duty_limit()```
- ```pup_motor_is_stalled()```
- ```pup_motor_restore_duty_limit()```
- ```pup_color_sensor_light_on()```
- ```pup_color_sensor_light_off()```
### motor4.c
フォースセンサが押された力に応じてモータを駆動する．

### speaker1.c
Hub内蔵スピーカを使用する．<br>
引数に``SOUND_MANUAL_STOP``を使用しているため，スピーカ駆動中にモータ操作が可能．<br>
``SOUND_MANUAL_STOP``の代わりに数値を入れることで，駆動時間を指定する事も可能．<br>
- ```hub_speaker_play_tone()```
- ```hub_speaker_stop()```

### ultrasonic1.c　(*)
超音波センサが物体を検知したら、物体までの距離に応じて超音波センサの各ライトを点灯する．物体までの距離(mm)を表示する．
- ```pup_ultrasonic_sensor_get_device()```
- ```pup_ultrasonic_sensor_distance()```
- ```pup_ultrasonic_sensor_light_on()```
- ```pup_ultrasonic_sensor_light_set()```
- ```pup_ultrasonic_sensor_light_off()```
### ultrasonic2.c
超音波を検出したらライトを点灯する．
- ```pup_ultrasonic_sensor_presence()```
- ```pup_ultrasonic_sensor_light_on()```

### multitask1.c
複数タスクの生成・扱い方の確認や，優先度ベーススケジューリングの確認など．</br>
タスクは優先度順に実行される．</br>
同一優先度内ではFIFO順．</br>
遅延操作にdly_tsk()を使用すると自タスクが待ち状態に入ってしまうため，実行状態を保持したまま時間経過を待つ関数busy_wait()を実装し，使用する．</br>
busy_wait()にはシステム時刻（get_tim()で取得）を使用．</br>
- ```CRE_TSK()```
- ```get_tim()```

### multitask2.c
周期関数の使用方法の確認など．</br>
高優先度の周期関数を使用してモータの回転方向を切り替える．</br>
遅延操作はmultitask1と同様にbusy_wait()を使用．</br>
- ```CRE_CYC()```

### multitask3.c　（同期・通信機能）
セマフォの使用方法の確認など．</br>
2タスク間でセマフォを共有し，モータを制御する．</br>
セマフォを獲得しているタスクがモータを制御する．</br>
- ```CRE_SEM()```

### multitask4.c　（同期・通信機能）
イベントフラグによる事象通知の方法の確認．</br>
ボタンの押下状態に応じてビットを立て，事象を通知する．</br>
- ```CRE_FLG()```

### multitask5.c　（同期・通信機能）
データキューによるタスク間通信方法の確認．</br>
左ボタンor右ボタンを押したときに，データキューにデータを送信する．</br>
データ受信側は受信データに応じてモータ出力を行う</br>
- ```CRE_DTQ()```

### syslog_bluetooth.c　(*)
``syslog()``をBluetooth経由で出力するサンプル．<br>
プログラムの内容は[button1.c](#button1c)と同じ．<br>
Chromeで[Pybricks](https://code.pybricks.com/)(Web IDE)を立ち上げて使用する．<br>
syslogをBluetooth経由で出力するには，cdlファイルに以下の変更を行う．<br>
- syslog_bluetooth.cdl
    ```
    <変更前>
    /* シリアルインタフェースドライバとの結合 */
    cSerialPort        = SerialPortUSB1.eSerialPort;
    cnSerialPortManage = SerialPortUSB1.enSerialPortManage;
    <変更後>
    cSerialPort        = SerialPortBluetooth1.eSerialPort;
    cnSerialPortManage = SerialPortBluetooth1.enSerialPortManage;
    ```

## プロジェクト作成用スクリプト
- スクリプト名：create.sh
- 使用方法
    ```
    cd spike-rt-sample/API-sample
    ./create.sh [NEW-PROJECT-NAME]
    ```
    - プロジェクト名に使用できる文字は，アルファベット(大・小)，数字，``-``，``_``とする
    - プロジェクト名の先頭と終端はアルファベットまたは数字にする