# API_sample
## 概要
APIの挙動を確認するために作成したサンプルです。<br>注意：(*)が付いたサンプルはサンプルはログの出力が必要です。

## 各サンプルの概要と使用する主なAPI
### battery1.c　(*)
バッテリーの電流・電圧を取得して表示する。
- ```hub_battery_get_current()```
- ```hub_battery_get_voltage()```
### button1.c
押したボタンをディスプレイに表示する。
- ```hub_button_is_pressed()```
### color1.c　(*)
カラーセンサーでhsv値とrgb値を取得し、読み取ったhsv値、rgb値、及び色の種類を表示する。
- ```pup_color_sensor_get_device()```
- ```pup_color_sensor_hsv()```
- ```pup_color_sensor_color()```
- ```pup_color_sensor_rgb()```
### color2.c
カラーセンサーの各ライトを指定した輝度で点灯する。
- ```pup_color_sensor_light_set()```
### color3.c　(*)
カラーセンサーで反射光の輝度を測定し、ディスプレイとログに出力する。
- ```pup_color_sensor_reflection()```
- ```hub_display_number()```
### color4.c
カラーセンサーで周囲の明るさを測定し、明るさに応じて超音波センサのライトを点灯する。
- ```pup_color_sensor_ambient()```
### color5.c　(*)
カラーセンサーが取得する色を指定し、取得した色を表示する。
- ```pup_color_sensor_detectable_colors()```
### dc_motor1
モーターをDCモーターとして活用する。
- ```pybricks_c_common_dcmotor_make_new()```
- ```pybricks_c_common_dcmotor_duty()```
- ```pybricks_c_common_dcmotor_stop()```
- ```pybricks_c_common_dcmotor_brake()```
### force1.c　(*)
フォースセンサが接触を検知したら、フォースセンサが押されている力(N)を表示する。
- ```pup_force_sensor_get_device()```
- ```pup_force_sensor_touched()```
- ```pup_force_sensor_force()```
- ```pup_force_sensor_distance()```
### led1.c
ディスプレイに指定した文字や図形を表示する。ピクセルと輝度を指定して点灯する。while文を一周するごとにハブ内蔵ライトの色を切り替える。
- ```hub_display_orientation()```
- ```hub_display_off()```
- ```hub_light_on_color()```
- ```hub_display_number()```
- ```hub_display_text()```
- ```hub_display_image()```
- ```hub_display_pixel()```
### led2.c
hub_display_char()で文字を出力する。
- ```hub_display_char()```
### led3.c
ハブ内蔵ライトのhsv値を指定して点灯する。
- ```hub_light_on_hsv()```
### motor1.c　(*)
ハブのボタンでモーターを操作する。
- ```pup_motor_get_device()```
- ```pup_motor_set_speed()```
- ```pup_motor_stop()```
- ```pup_motor_brake()```
- ```pup_motor_hold()```
- ```pup_motor_get_speed()```
### motor2.c　(*)
モーターが動かされたらエンコーダー値を取得して出力する。180°以上回るとエンコーダー値をリセットする。
- ```pup_motor_get_count()```
- ```pup_motor_reset_count()```
### motor3.c　(*)
回転しているモーターが止められていることを検知したら、Duty値を上げて回ろうとする。Duty値を表示する。
- ```pup_motor_set_duty_limit()```
- ```pup_motor_is_stalled()```
- ```pup_color_sensor_light_on()```
- ```pup_color_sensor_light_off()```
### motor4.c
メインタスクから関数呼び出しでモーターを駆動する。
### ultrasonic1.c　(*)
超音波センサが物体を検知したら、物体までの距離に応じて超音波センサの各ライトを点灯する。物体までの距離(mm)を表示する。
- ```pup_ultrasonic_sensor_get_device()```
- ```pup_ultrasonic_sensor_distance()```
- ```pup_ultrasonic_sensor_light_on()```
- ```pup_ultrasonic_sensor_light_set()```
- ```pup_ultrasonic_sensor_light_off()```
### ultrasonic2.c
超音波を検出したらライトを点灯する。
- ```pup_ultrasonic_sensor_light_on()```