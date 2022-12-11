# Pybricks and Spyke-rt API

## motor
### Initialize a motor 
| Pybricks | Spike-rt |
|:---|:---|
| ```motor = Motor(Port.A)``` | ```pup_motor_t *motor;```<br>```motor = pup_motor_get_device(PBIO_PORT_ID_A);```<br>ポート ID で指定されたモータへの PUP モータデバイスポインタを取得する．|


### Measuring 
| Pybricks | Spike-rt |
|:---|:---|
|```speed()```<br>引数：<br>戻り値:回転速度 [°/秒]|```pup_motor_get_speed(motor)```<br>引数:motor PUP モータデバイスポインタ<br>戻り値: 回転速度 [°/秒] (int)|
|```angle()```<br>エンコーダの値を取得する(絶対角).<br>引数：<br>戻り値：motor エンコーダの値 [°]|```pup_motor_get_count(motor)```<br>エンコーダの値を取得する(絶対角)<br>引数:motor PUP モータデバイスポインタ<br>戻り値：motor エンコーダの値 [°] (絶対角)|
|```reset_angle(num)```<br>累積回転角を任意の値に設定<br>角度を指定しない場合は絶対角度を使用(モーターがサポートしている場合)<br>引数：num リセット後にセットしたいエンコーダー値(int)<br>戻り値： | ```pup_motor_reset_count(motor)```<br>エンコーダ値を 0 にリセットする<br>引数：motor PUP モータデバイスポインタ<br>戻り値：PBIO_SUCCESS またはエラー番号 |
|×<br>後述のrun_until_stalled()が似たような機能を持つ.|```pup_motor_is_stalled(motor)```<br>モータがストールしているか調べる<br>引数: motor PUP モータデバイスポインタ<br>戻り値 ture or false|


### Stopping
| Pybricks | Spike-rt |
|:---|:---|
|```stop()```<br>モーターを停止し,解放する.<br>引数：<br>戻り値：|```pup_motor_stop(motor)```<br>モーターを停止し,解放する.<br>引数:motor UP モータデバイスポインタ<br>戻り値：PBIO_SUCCESS またはエラー番号|
|```hold()```<br>モーターを停止し,現在の角度を保持する.<br>引数：<br>戻り値：|```pup_motor_hold(motor)```<br>モータを止めて角度を維持する.<br>引数:motor UP モータデバイスポインタ<br>戻り値: PBIO_SUCCESS またはエラー番号|
|```brake()```<br>摩擦に加え,電気的にブレーキをかける.<br>引数：<br>戻り値：|```pup_motor_brake(motor)```<br>ブレーキをかけてモータを止める.<br>引数: motor UP モータデバイスポインタ<br>戻り値: PBIO_SUCCESS またはエラー番号|


### Action
| Pybricks | Spike-rt |
|:---|:---|
|```run(speed)```<br>モーターを指定した速度で回転.<br>引数：speed モータの回転速度 [°/秒].<br>戻り値：|```pup_motor_set_speed(motor, speed)```<br>モーターを指定した速度で回転.<br>引数：motor PUP モータデバイスポインタ, speed モータの回転速度 [°/秒].<br>戻り値：PBIO_SUCCESS またはエラー番号.|
|```run_time(speed, time)```<br>指定された時間だけ指定された速度で回る.<br>時間が過ぎたら停止する.<br>プログラムが完全終了するまで待つ.<br>引数:speed モータの回転速度 [°/秒], time 回転時間.<br>戻り値：|×|
|```run_target(speed, target_angle)```<br>モーターを指定された速度で指定された角度まで回す.<br>引数:speed モータの回転速度 [°/秒], target_angle 目標角度 [°].<br>戻り値：|×|
|```run_until_stalled(speed)```<br>モーターが止められるまで指定された速度で回転する.<br>引数:speed モータの回転速度 [°/秒]<br>戻り値:モーターが停止した時の角度|×<br>前述のpup_motor_is_stalled()が似たような機能を持つ.|
|```dc(duty)```<br>duty 値でモーターを回す.<br>・この方法でモーターを DC モーターとして使うことができる.<br>引数：duty 値(-100 to 100).<br>戻り値：|```pup_motor_set_duty_limit(motor, duty_limit)```<br>モータの duty 値を下げる.<br>元の状態に戻すにはこの関数の戻り値を使ってpup_motor_restore_duty_limit を呼ぶ.<br>引数:motor PUP モータデバイスポインタ, duty_limit 新しい duty 値（int, 0to100）.<br>戻り値：元の状態に戻すための最大電圧.|
|×(?)|```pup_motor_restore_duty_limit(motor, old_value)```<br>モータの duty 値を元に戻す.<br>引数: motor PUP モータデバイスポインタ, old_value pup_motor_set_duty_limit の戻り値.<br>戻り値：|


## Button
### Initialize the hub
| Pybricks | Spike-rt |
|:---|:---|
|```hub = PrimeHub()```|```hub_button_t buttons```<br>各ハブ内蔵ボタンのビットマスク値.|


### Using the buttons
| Pybricks | Spike-rt |
|:---|:---|
|```buttons.pressed()```<br>ボタンが押されているか確認する.<br>引数：<br>返り値；押されたボタンのセット(Button.LEFT or Button.RIGHT or Button.CENTER or Button.BLUETOOTH).|```hub_button_is_pressed(pressed)```<br>ボタンが押されているか確認する<br> 引数：押されているボタンのビット OR 値  (何も押されていなければ 0)<br>返り値：エラー番号|



## LED
### Initialize the hub
| Pybricks | Spike-rt |
|:---|:---|
|```hub = PrimeHub()```||

### Using the LED
| Pybricks | Spike-rt |
|:---|:---|
|```display.orientation(up)```<br>ディスプレイの表示方向を設定.<br>引数：up 表示方向の上側(Side.TOP, Side.LEFT, Side.RIGHT, Side.BOTTOM)<br>戻り値：|```hub_display_orientation(up)```<br>ディスプレイの表示方向を設定.<br>引 数 ： up 表 示 方 向 の 上 側 （ PBIO_SIDE_TOP, PBIO_SIDE_LEFT, PBIO_SIDE_RIGHT, PBIO_SIDE_BOTTOM から選択）<br>戻り値：エラー番号|
|```display.off()```<br>すべてのピクセルを消灯.<br>引数：<br>返り値：|```hub_display_off()```<br>すべてのピクセルを消灯.<br>引数：<br>返り値：エラー番号|
|```display.pixel()```<br>指定した輝度で，指定したピクセルを点灯する.<br>引数：row 一番上側を 0 とした行番号, column 一番左側を 0 とした列番号, brightness ピクセルの輝度(%).<br>返り値：|```hub_display_pixel(row, column, brightness)```<br>指定した輝度で，指定したピクセルを点灯する.<br>引数: row 一番上側を 0 とした行番号, column 一番左側を 0 とした列番号, brightness ピクセルの輝度(%)返り値：|
|```display.image(matrix)```<br>イメージ（輝度（0〜100）の行列によって表現）を表示.<br>引数：行列 輝度の行列<br>返り値：|```hub_display_image(image)``` <br>イメージ（輝度（0〜100）の行列によって表現）を表示.<br>ピクセルの指定は2進数の行列(２次元配列)で行う.<br>引数：行列 輝度の行列.２次元配列でも良い.<br>返り値：エラー番号|
|```display.animate(matrices, interval)``` <br>イメージのリストを用いてアニメーションを表示する.<br>引数：matrices 輝度の行列, Interval リスト内のイメージを表示する時間(ms)<br>戻り値：|×|
|```display.number(number)```<br>-99〜99 の数値を表示する．負の符号（-）は ディスプレイ中央に薄い点として表現される.<br>100 以上の場合は「>」, -100 以下の場合は「<」を表示する.<br>引数：number 表示する番号<br>返り値：|```hub_display_number(num)```<br>-99〜99 の数値を表示する．負の符号（-）は，ディスプレイ中央に薄い点として表現される.<br>引数：num 表示する番号<br>返り値：エラー番号|
|```display.char(char)```<br>１文字または記号を表示する．<br>小文字:(a-z)，大文字:(A-Z）<br>シンボル:( !"#$%&'()*+,-./:;<=>?@[¥]^_`{&#124;})<br>引数：char(str) 表示する文字または記号<br>返り値：| ```hub_display_char(char)```<br>１文字または記号を表示する．<br>小文字:(a-z)，大文字:(A-Z）<br>シンボル:( !"#$%&'()*+,-./:;<=>?@[]^_`{&#124;})<br>引数：char(str) 表示する文字または記号<br>返り値：エラー番号|
|```display.text(text, on, off)``` <br>文字列を表示する．<br>１文字ずつ表示し，各文字を表示する間で一定時間消灯する．<br>最後の文字を表示した後は，すべてのピクセルを消灯する．<br>引数：text(str) 表示する文字列．on(time: ms) 文字が表示される時間．off(time: ms) 文字表示間で消灯する時間．<br>返り値：|```hub_display_text(text, on, off)```<br>文字列を表示する．<br>１文字ずつ表示し，各文字を表示する間で一定時間消灯する．最後の文字を表示した後は，すべてのピクセルを消灯する．<br>引数：text(str) 表示する文字列．on(time: ms) 文字が表示される時間．off(time: ms) 文字表示間で消灯する時間<br>返り値：エラー番号|
|× |```hub_display_text_scroll(text, delay)``` <br>文字列をスクロールしながら表示する．<br>引数：text(str) 表示する文字列(time: ms) スクロールの間隔<br>返り値：エラー番号|
|× |```hub_light_on_color(color)```<br>指定された色でライトを点灯させる．<br>引数：color<br>返り値：エラー番号|
|× |```hub_light_on_hsv()``` <br>指定された HSV(※) でライトを点灯させる.<br>引数：HSV.<br>返り値：エラー番号.|


<br>※HSV…色相、彩度、明度の三つの成分からなる色空間

## Status light
### Using the hub status light
| Pybricks | Spike-rt |
|:---|:---|
|```light.on()```<br>指定された色でライトを点灯させる.<br>引数：色.|```hub_light_on_color()```<br>指定された色でライトを点灯させる.<br>引数：色.<br>戻り値：エラー番号.|
|```light.off()```<br>ライトを消灯させる.|```hub_light_off()```<br>ライトを消灯させる.<br>戻り値：エラー番号.|
|```light.blink(color, durations)```<br>ライトを点滅させる.<br>ライトの色と点灯・消灯の継続時間は引数で指定する.<br>点灯・消灯の継続時間はリストで指定.<br>引数：color 点灯させる色.<br>duarations 点灯・消灯の時系列. [on_1, off_1, on_2, off_2, ...] のようなリストで指定.|×|
|```light.animate(colors, interval)```<br>指定した間隔でライトの色を更新し、一連のライトの動作をアニメーション化する.<br>引数：colors 使用する色のリスト.<br>interval(ms) ライトの色を更新する間隔.|×|
|×|```hub_light_on_hsv()```<br>指定されたhsvでライトを点灯させる.<br>hsvの指定は2進数の配列で行う.<br>引数.：hsv.<br>戻り値：エラー番号.|

## Color Sensor
### Initialize a Color Sensor
| Pybricks | Spike-rt |
|:---|:---|
|```sensor = ColorSensor(Port.A)``` |```pup_device_t *pdev;```<br>```pdev = pup_color_sensor_get_device(PBIO_PORT_ID_A);```<br>ポート ID で指定されたカラーセンサへの PUP デバイスポインタを取得する.<br>失敗した場合、エラーログを出力し、NULL を返す.<br>引数：PUP ポート ID (PBIO_PORT_ID_A).<br>返り値：PUP デバイスポインタ (pdev).|

### Run a Color Sensor
| Pybricks | Spike-rt |
|:---|:---|
|```color(surface=True/False)```<br>カラーセンサで色を測定する<br>detectable_colors()で検出する色を指定する。<br>デフォルトでは、赤色、黄色、緑色、青色、白色、無しが検出される。<br>引数：surface true ならば表面の色から、falseならば他の光源の色を検出する。<br>返り値：色|```pup_color_sensor_color(pdev, surface=True/False)```<br>カラーセンサーで色を測定する.<br>測定したHSV値をdetectable_colors()で指定した色に近似して出力する.<br>デフォルトでは、赤色、黄色、緑色、青色、白色、無しが検出される.<br>引数：pdev PUP デバイスポインタ, surface surface true ならば表面の色から、falseならば他の光源の色を検出する.<br>返り値：色|
|```hsv(surface=True/False)```<br>カラーセンサで色を測定する。<br>color()と異なり、最も近い色に近似されず検出した hsv 値を返す。<br>引数：surface true ならば表面の色から、falseならば他の光源の色を検出する.<br>返り値：色 (hue (0–359), saturation (0–100), brightness value (0–100))|```pup_color_hsv_t color(pdev, surface)```<br>```color=pup_color_sensor_hsv(device, True/False)```<br>カラーセンサで色を測定する。<br>pup_color_sensor_color()!!と異なり、最も近い色に近似されず検出した hsv 値を返す.<br>引数：pdev PUP デバイスポインタ.surface (True or False) True ならば表面の色から、False ならば他の光源の色を検出する.<br>返り値：色（hsv による表現）.|
|```reflection()```<br>センサーの発する光を表面がどの程度反射するかを測定する。<br>引数：<br>返り値：どの程度反射しているか(0.0-100.0%)|```pup_color_sensor_reflection(pdev)```<br>センサーの発する光を表面がどの程度反射するかを測定する。<br>引数：PUP デバイスポインタ<br>返り値： どの程度反射しているか(%)|
|```ambient()```<br>周囲の光の強度を測定する。<br>引数：<br>返り値：周囲の光の強度(0-100%)|```pup_color_sensor_ambient(pdev)```<br>周囲の光の強度を測定する。<br>引数：pdev PUP デバイスポインタ<br>返り値：周囲の光の強度(%)|
|```detectable_colors(colors)```<br>color()が検出する色を指定する。<br>フルカラーで測定し、目的の色に近似する。<br>引数：colors 検出したい色(配列)。「Color.MAGENTA」のように標準色を指定するか「Color(h=348, s=96, v=40)」のように HSV を指定する。<br>戻り値：|```pup_color_hsv_t * colors;```<br>```pup_color_sensor_detectable_colors(size, colors)```<br>color()が検出する色を指定する。<br>指定は2進数の配列で行う。<br>引数：カラーの配列とそのサイズ<br>戻り値：色|

### Built-in lights 
| Pybricks | Spike-rt |
|:---|:---|
|×<br>(lights.on(brightness)に統合)|```pup_color_sensor_light_set(pdev, bv1, bv2, bv3)```<br>カラーセンサのライトを設定する。<br>引数：pdev PUP デバイスポインタ, Bv1, bv2, bv3 (輝度)<br>返り値：エラー番号|
|```lights.on(brightness)```<br>カラーセンサのライトを指定した輝度で点灯する。<br>引数：brightness 各ライトの輝度(%). 引数を 1 つだけ指定した場合は全てのライトを同じ輝度で点灯する。<br>返り値：|```pup_color_sensor_light_on(pdev)```<br>カラーセンサのライトを点灯する。<br>pup_color_sensor_light_set(pdev, 100, 100, 100) と同じ。<br>引数：pdev PUP デバイスポインタ<br>返り値：エラー番号|
|```lights.off()```<br>カラーセンサのライトを消灯する。<br>引数：<br>返り値：|```pup_color_sensor_light_off(pdev)```<br>カラーセンサのライトを消灯する。<br>pup_color_sensor_light_set(pdev, 0, 0, 0) と同じ。<br>引数：pdev PUP デバイスポインタ。<br>返り値：エラー番号。|


## Force Sensor
### Initialize a Force Sensor
| Pybricks | Spike-rt |
|:---|:---|
|```button=ForceSensor(Port.A)```|```pup_device_t* port```<br>```port=pup_force_sensor_get_device(PBIO_PORT_ID_A)```<br>ポート ID で指定されたフォースンサへの PUP デバイスポインタを取得する。<br>失敗した場合、エラーログを出力し、NULL を返す。<br>引数：port PUP ポート ID。<br>返り値：PUP デバイスポインタ。|

### Run a Force Sensor
| Pybricks | Spike-rt |
|:---|:---|
|```force()```<br>フォースセンサで力を測定する。<br>引数：<br>返り値：力(N, MAX…約 10.00N)。|```pup_force_sensor_force(port)```<br>フォースセンサで力を測定する。<br>引数：port PUP デバイスポインタ。<br>返り値：力(N)。|
|```distance()```<br>フォースセンサのボタンの移動距離を取得する。<br>引数：<br>返り値：距離(mm, MAX…約 8.00mm)。|```pup_force_sensor_distance(port)```<br>フォースセンサのボタンの移動距離を取得する。<br>引数：port PUP デバイスポインタ。<br>返り値：距離(mm)。|
|```pressed()```<br>ボタンが指定した力以上で押されているか検出する。<br>引数に何も入れない場合は 3N 以上で Trueになる。<br>引数；押されていると判断する最低の力(N)。<br>返り値：True 押されている, False 押されていない。|```pup_force_sensor_pressed(port, force)```<br>ボタンが指定した力以上で押されているか検出する。<br>引数：port PUP デバイスポインタ。, force 押されていると判断する最低の力(N)。<br>返り値：True 押されている, False 押されていない.|
|```touched()```<br>フォースセンサのボタンが触れられているかを検出する。<br>pressed()と似ているが,これはわずかなボタンの動きも検知する.<br>引数：<br>返り値：True 触れられている, False 触れられていない|```pup_force_sensor_touched()```<br>フォースセンサのボタンが触れられているかを検出する。<br>引数：port PUP デバイスポインタ。<br>返り値：True 触れられている, False 触れられていない.|


## Ultrasonic Sensor
### Initialize a Ultrasonic Sensor
| Pybricks | Spike-rt |
|:---|:---|
|```eyes=UltrasonicSensor(Port.A)```|```pup_device_t * pdev```<br>```pdev=pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_A)```<br>ポート ID で指定されたフォースンサへの PUP デバイスポインタを取得する。<br>失敗した場合、エラーログを出力し、NULL を返す。<br>引数：port PUP ポート ID。<br>返り値：PUP デバイスポインタ。|

### Run a Ultrasonic Sensor 
| Pybricks | Spike-rt |
|:---|:---|
|```distance()```<br>超音波を用いてセンサーと物体間の距離を測る。<br>失敗した場合は 2000mm を返す。<br>引数：<br>返り値：距離(mm)。|```pup_ultrasonic_sensor_distance(pdev)```<br>超音波センサで距離を測定する．<br>失敗した場合，エラーログを出力し，負の値を返す．<br>引数：pdev PUP ポート ID。<br>返り値：距離(mm)。|
|```presence()```<br>超音波を検出して他の超音波センサの存在を検知。<br>引数：<br>返り値：True 超音波を検知, False 超音波を検知せず。|```pup_ultrasonic_sensor_presence(pdev)```<br>超音波センサで超音波信号を検出する．<br>失敗した場合，false を返す．<br>引数：PUP デバイスポインタ<br>返り値：True 超音波を検知, False 超音波を検知せず.|

### Built-in lights 

| Pybricks | Spike-rt |
|:---|:---|
|```lights.on(brightness)```<br>各ライトを指定した明るさで点灯する。<br>各ライトに明るさを指定したい場合はタプルで指定する。<br>1 つの値を入れた場合は全てのライトを同じ明るさで点灯する。<br>引数：brightness 明るさ(単位:%, タプルもしくは数値)。<br>返り値|```pup_ultrasonic_sensor_light_on(pdev)```<br>超音波センサのライトを点灯させる．<br>pup_ultrasonic_sensor_light_set(pdev, 100, 100, 100, 100) と同じ．<br>引数：pdev PUP デバイスポインタ.<br>返り値：エラー番号.|
|×<br>(lights.on(brightness)に統合)|```pup_ultrasonic_sensor_light_set(pdev, bv1, bv2, bv3, bv4)```<br>超音波センサで超音波信号を検出する．<br>失敗した場合，false を返す．<br>引数：pdev PUP デバイスポインタ, bv1 輝度<br>返り値：エラー番号|
|```lights.off()```<br>ライトを消灯する。<br>引数：<br>返り値：|```pup_ultrasonic_sensor_light_off(pdev)```<br>超音波センサのライトを消灯させる．<br>pup_ultrasonic_sensor_light_set(pdev, 0, 0, 0, 0) と同じ．<br>引数：pdev PUP デバイスポインタ.<br>返り値：エラー番号.

## Using the battery
| Pybricks | Spike-rt |
|:---|:---|
|```battery.current()```<br>バッテリーの電流を取得する.<br>戻り値：電流(mA)|```hub_battery_get_current()```<br>バッテリーの電流を取得する.<br>戻り値：電流(mA)|battery.voltage()<br>バッテリーの電圧を取得する.<br>戻り値：電圧(mV)|hub_battery_get_voltage()<br>バッテリーの電圧を取得する.<br>戻り値：電圧(mV)|

## Delay Task
| Pybricks | Spike-rt |
|:---|:---|
|```wait(time)```<br>引数：time 時間(ms)|```dly_tsk(time)```<br>引数：time 時間(μs)|

## Saturated colors
#### These colors have maximum saturation and brightness value. They differ only in hue.
| Colors |
|:---|
|RED<br>Color= Color(h=0, s=100, v=100)|
|ORANGE<br>Color= Color(h=30, s=100, v=100)|
|YELLOW<br>Color= Color(h=60, s=100, v=100)|
|GREEN<br>Color= Color(h=120, s=100, v=100)|
|CYAN<br>Color= Color(h=180, s=100, v=100)|
|BLUE<br>Color= Color(h=240, s=100, v=100)|
|VIOLET<br>Color= Color(h=270, s=100, v=100)|
|MAGENTA<br>Color= Color(h=300, s=100, v=100)|

<br>
<br>

## Official API document
1. [Spike-rt API](https://spike-rt.github.io/spike-rt/ja/html/modules.html)<br>
1. [Pybricks API](https://docs.pybricks.com/en/v3.0/pupdevices/motor.html)

