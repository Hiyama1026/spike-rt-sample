// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <kernel.h>
#include "kernel_cfg.h"
#include "raspike.h"
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
#include "spike/pup/ultrasonicsensor.h"
#include "spike/hub/button.h"
#include <spike/hub/light.h>
#include "pbio/color.h"
#include <spike/hub/imu.h>
#include <spike/hub/battery.h>
#include <pbdrv/battery.h>

#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"

//#include <pbsys/user_program.h>

#include <stdio.h>

extern void wup_pybricks(void);


#define DETECT_COM_FAIL_PERIOD 5000000

#define RASPIKE_PORTNO  4

int32_t color_sensor_mode = 0;
int32_t color_sensor_change = 0;

int32_t ultrasonic_sensor_mode = 0;
int32_t ultrasonic_sensor_change = 0;

int32_t gyro_sensor_mode = 0;
int32_t gyro_reset = 0;

int32_t other_command = 0;

uint32_t num_command = 0;
uint32_t num_fail = 0;

uint32_t last_command_time = 0;

uint8_t motor_reset_a = 0;
uint8_t motor_reset_r = 0;
uint8_t motor_reset_l = 0;
uint8_t motor_stop_a = 0;
uint8_t motor_stop_r = 0;
uint8_t motor_stop_l = 0;

/*モーターのセットアップ時にl_motorの回転方向を設定しているため，使用していない*/
uint8_t invert_A = 1;
uint8_t invert_R = 1;
uint8_t invert_L = 1;

/*PUPデバイスポインター*/
static pbio_error_t r_err;     
static pbio_error_t l_err;      
static pbio_error_t a_err;
static pup_motor_t *a_motor;       //arm motor
static pup_motor_t *r_motor;       //right motor
static pup_motor_t *l_motor;       //left motor
static pup_device_t *col;          //color sensor
static pup_device_t *ult;          //ultrasonic sensor

uint8_t gyro_sensor_mode_change = 0;

#if 0
static pup_color_hsv_t detect_color_for_lego_official[] = {
    { PBIO_COLOR_HUE_RED, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_ORANGE, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_YELLOW, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_GREEN, 0b01100100, 0b01100100 },
	{ PBIO_COLOR_HUE_SPRING_GREEN, 0b01100100, 0b01100100 }, 
    { PBIO_COLOR_HUE_CYAN, 0b01100100, 0b01100100 }, 
    { PBIO_COLOR_HUE_BLUE, 0b01100100, 0b01100100 }, 
    { PBIO_COLOR_HUE_VIOLET, 0b01100100, 0b01100100 }, 
    { PBIO_COLOR_HUE_MAGENTA, 0b01100100, 0b01100100 }, 
    {0, 0, 0b01100100},         //WHITE
    {0, 0, 0b1010},             //BRACK
    {0, 0, 0} ,                //NON
};
#endif

#if 0
//spike-rt default detectable color + brack
static pup_color_hsv_t detect_spike_rt_default[] = {
    { PBIO_COLOR_HUE_RED, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_YELLOW, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_GREEN, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_BLUE, 0b01100100, 0b01100100 }, 
    {0, 0, 0b01100100},     //WHITE
    {0, 0, 0b1010},         //BRACK
    {0, 0, 0} ,             //NON
};
#endif

#if 1
static pup_color_hsv_t detect_color_for_EV3[] = {
    { PBIO_COLOR_HUE_RED, 0b01100100, 0b01100100 },
    { PBIO_COLOR_HUE_YELLOW, 0b01100100, 0b01100100 },
	{ PBIO_COLOR_HUE_GREEN, 0b01100100, 0b01100100 }, 
    { PBIO_COLOR_HUE_BLUE, 0b01100100, 0b01100100 }, 
    {0b00101000, 0b01100100, 0b00100011},       //BROWN (H=40, S=100, V=35)
    {0, 0, 0b01100100},                         //WHITE
    {0, 0, 0b1010},                             //BRACK
    {0, 0, 0} ,                                 //NON
};
#endif

static uint8_t text_ET[1][25] = {
  {
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100,
    0b1100100, 0b0000000, 0b0000000, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b0000000, 0b1100100, 0b0000000, 
    0b1100100, 0b0000000, 0b0000000, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b0000000, 0b1100100, 0b0000000,
  },
};

static uint8_t img_sad[1][25] = {
  {
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b0000000, 0b1100100, 0b0000000,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 
    0b0000000, 0b1100100, 0b1100100, 0b1100100, 0b0000000,
    0b1100100, 0b0000000, 0b0000000, 0b0000000, 0b1100100,
  },
};


#define SEND_PACKET_SIZE (sizeof("@0000:000000"))
static char buf[SEND_PACKET_SIZE] = "@0000:000000";

static void
send_data(int cmd, int val)
{
    
#if 1         
    buf[4] = '0' + cmd % 10; cmd /= 10;
    buf[3] = '0' + cmd % 10; cmd /= 10;
    buf[2] = '0' + cmd % 10; cmd /= 10;
    buf[1] = '0' + cmd % 10; cmd /= 10;

    if (val >= 0) {
        buf[11] = '0' + val % 10; val /= 10;        
        buf[10] = '0' + val % 10; val /= 10;    
        buf[9] = '0' + val % 10; val /= 10;
        buf[8] = '0' + val % 10; val /= 10;
        buf[7] = '0' + val % 10; val /= 10;
        buf[6] = '0' + val % 10; val /= 10;    
    }
    else {
        val = -val;
        buf[11] = '0' + val % 10; val /= 10;        
        buf[10] = '0' + val % 10; val /= 10;    
        buf[9] = '0' + val % 10; val /= 10;
        buf[8] = '0' + val % 10; val /= 10;
        buf[7] = '0' + val % 10; val /= 10;
        buf[6] = '-';    
    }
#endif    
    serial_wri_dat(RASPIKE_PORTNO, buf, SEND_PACKET_SIZE-1);
    //dly_tsk(500);
}

#define ACK_PACKET_SIZE (sizeof("<0000:000000"))
static char ack_buf[ACK_PACKET_SIZE] = "<0000:000000";

static void
send_ack(int cmd)
{    
    ack_buf[4] = '0' + cmd % 10; cmd /= 10;
    ack_buf[3] = '0' + cmd % 10; cmd /= 10;
    ack_buf[2] = '0' + cmd % 10; cmd /= 10;
    ack_buf[1] = '0' + cmd % 10; cmd /= 10;

    serial_wri_dat(RASPIKE_PORTNO, ack_buf, ACK_PACKET_SIZE-1);
    //dly_tsk(500);    
}


static void
detect_com_fail(void) {
    
    //ディスプレイにraspike_etrobo.pyのhub.Image.SADと同じ顔を表示する
    hub_display_image(img_sad);

    //ステータスライトを赤く点灯する
    hub_light_on_color(PBIO_COLOR_RED);

    //モーターを止める
    pup_motor_stop(r_motor);
    pup_motor_stop(l_motor);
    pup_motor_stop(a_motor);
}

void
notify_sensor_task(intptr_t exinf) {
    
    hub_button_t pressed, touched;
    pup_color_hsv_t tmp_color_val, color_hsv;
    pup_color_rgb_t color_rgb;
    static hub_button_t touch_sensor_value, pre_touch_sensor_value;
    int button_command = 0;        
    static int long_period_count, prev_button_command, x_ang_vel; 
    int send_val, ambient, color_val, reflect, val;
    static uint8_t mscnt = 0;
    float hub_angular_velocity[3];
    SYSTIM tim;

    // カラーセンサーの切り替えがあった場合、タイミングによってはget()がNoneになったり,
    // RGBではない値が取れたりするので、その場合は次の周期で通知する
      
    if (color_sensor_mode == 1) {
        ambient = pup_color_sensor_ambient(col);
        if (ambient >= 0 && ambient <=100) {
            // ambient
            send_data(1, ambient);
        }
    }
    else if (color_sensor_mode == 2) {
        tmp_color_val = pup_color_sensor_color(col, true);

#if 1
        // for EV3
        switch (tmp_color_val.h){
            case PBIO_COLOR_HUE_RED:
                if (tmp_color_val.s == 100){        // RED (PBIO_COLOR_HUE_RED=0)
                color_val = 5;
                }
            else if (tmp_color_val.v == 100){       // WHITE
                color_val = 6;
            }
            else if (tmp_color_val.v == 10){        // BRACK
                color_val = 1;
            }
            else{
                color_val = -1;                     // NONE
            }
            break;
            case PBIO_COLOR_HUE_BLUE:
                color_val = 2;
                break;
            case PBIO_COLOR_HUE_GREEN:
                color_val = 3;
                break;
            case PBIO_COLOR_HUE_YELLOW:
                color_val = 4;
                break;
            case 40:                                    // BROWN
                color_val = 7;
                break;
            default:
                color_val = -1;
        }
    
#endif

#if 0
    //for spike-rt_default + brack 
    switch(tmp_color_val.h){
        case 0:            
            if(tmp_color_val.s == 100){         //RED (PBIO_COLOR_HUE_RED=0)
                color_val = 1;
            }
            else if(tmp_color_val.v == 100){    //WHITE
                color_val = 5;
            }
            else if(tmp_color_val.v == 10){     //BRACK
                color_val = 6;
            }
            else{
                color_val = 0;                  //NONE
            }
            break;
        case PBIO_COLOR_HUE_YELLOW:
            color_val = 2;
            break;
        case PBIO_COLOR_HUE_GREEN:
            color_val = 3;
            break;
        case PBIO_COLOR_HUE_BLUE:
            color_val = 4;
            break;
        default:
            color_val = -1;      //err
    }
#endif

#if 0      
        //for lego official
        switch(tmp_color_val.h){
            case PBIO_COLOR_HUE_RED:            
                if(tmp_color_val.s == 100){             //RED (PBIO_COLOR_HUE_RED=0)
                    color_val = 9;
                }
                else if(tmp_color_val.v == 100){        //WHITE
                    color_val = 10;
                }
                else if(tmp_color_val.v == 10){         //BRACK
                    color_val = 0;
                }
                else{
                    color_val = -1;                     //NON
                }
                break;
            case PBIO_COLOR_HUE_ORANGE:
                color_val = 8;
                break;
            case PBIO_COLOR_HUE_YELLOW:
                color_val = 7;
                break;
            case PBIO_COLOR_HUE_GREEN:
                color_val = 6;
                break;
            case PBIO_COLOR_HUE_SPRING_GREEN:
                color_val = 5;
                break;
            case PBIO_COLOR_HUE_CYAN:
                color_val = 4;
                break;
            case PBIO_COLOR_HUE_BLUE:
                color_val = 3;
                break;
            case PBIO_COLOR_HUE_VIOLET:
                color_val = 2;
                break;
            case PBIO_COLOR_HUE_MAGENTA:
                color_val = 1;
                break;
            default:
                color_val = -2;
        }
#endif

        if(color_val >= 0){             //color is not NONE
            send_data(2, color_val); 
        }    
    }

    else if (color_sensor_mode == 3) {
        reflect = pup_color_sensor_reflection(col);
        if (reflect >= 0 && reflect <= 100) {
            // Reflect
            send_data(3, reflect);
        }
    }
    else if (color_sensor_mode == 4) {
        //RGB
       color_rgb = pup_color_sensor_rgb(col);
       color_hsv = pup_color_sensor_hsv(col, true);
       if(color_hsv.h==0 && color_hsv.s==0 && color_hsv.v==0)
       {
       }
       else{
        send_data(4, color_rgb.r / 4);  
        send_data(5, color_rgb.g / 4);          
        send_data(6, color_rgb.b / 4);
       }                  
    }
        
                  
    // 超音波センサー
    
    if (ultrasonic_sensor_mode == 1) { 
        val = pup_ultrasonic_sensor_distance(ult);
        val = val/10;
        if(val < 0){
            val = -1;
        }
        send_data(22, val);
    }

    else if (ultrasonic_sensor_mode == 2) {
      
        send_data(23, pup_ultrasonic_sensor_presence(ult));
   
    }
             
    // モーター出力
    send_data(64, pup_motor_get_count(a_motor) * invert_A);
    send_data(65, pup_motor_get_count(r_motor) * invert_R);
    send_data(66, pup_motor_get_count(l_motor) * invert_L);

    // Gyro
    //10msec周期なので、その分を加算する
    hub_imu_get_angular_velocity(&hub_angular_velocity[0]);
    x_ang_vel = hub_angular_velocity[0];
    send_data(8,x_ang_vel);
    send_data(7, 0);     //キャリブレーション処理はAPIがないため0を出力している

    //タッチセンサー
    hub_button_is_pressed(&touched);
    if((touched & HUB_BUTTON_BT) == HUB_BUTTON_BT){
        touch_sensor_value = HUB_BUTTON_BT;
    }
    else{
        touch_sensor_value = 0;
    }
    if(pre_touch_sensor_value != touch_sensor_value){
        pre_touch_sensor_value = touch_sensor_value;
        send_val = 0;
        if (touch_sensor_value == HUB_BUTTON_BT){
            send_val = 2048;
        }
        send_data(28,send_val);
    }

    //Ackの処理
    //モーターリセット
    if (motor_reset_a == 1) {
        motor_reset_a = 0;
        send_ack(9);
    }
    if (motor_reset_r == 1) {
        motor_reset_r = 0;
        send_ack(10);
    }
    if (motor_reset_l == 1) {
        motor_reset_l = 0;
        send_ack(11);
    }
    if (color_sensor_change == 1) {
        color_sensor_change = 0;
        send_ack(61);
    }
    if (ultrasonic_sensor_change == 1) {
        ultrasonic_sensor_change = 0;
        send_ack(62);
    }
    if (gyro_reset == 1) {
        gyro_reset = 0;
        send_ack(13);
    }
    if (gyro_sensor_mode_change == 1) {
        gyro_sensor_mode_change = 0;
        send_ack(63);
    }
    if (motor_stop_a == 1) {
        motor_stop_a = 0;
        send_ack(5);
    }
    if (motor_stop_r == 1) {
        motor_stop_r = 0;
        send_ack(6);
    }
    if (motor_stop_l == 1) {
        motor_stop_l = 0;
        send_ack(7);
    }
    if (other_command != 0) {
        send_ack(other_command);
        other_command =0;
    }
              
    /* 100ms周期 */
    if (++mscnt == 10) {
        mscnt = 0;     
        // 電流/電圧は1sec毎に送るが、位相はずらす
        if (((long_period_count+5) % 10) == 0){      
            send_data(29,hub_battery_get_current());
        }
        if (((long_period_count) % 10) == 0){
            send_data(30,hub_battery_get_voltage());
        }

        //本体ボタン(100msec毎)
        hub_button_is_pressed(&pressed);
        if((pressed & HUB_BUTTON_LEFT) == HUB_BUTTON_LEFT) {
            button_command = 1;
        }
        if((pressed & HUB_BUTTON_RIGHT) == HUB_BUTTON_RIGHT){
            button_command = button_command + 2;
        }
        if((pressed & HUB_BUTTON_CENTER) == HUB_BUTTON_CENTER){
            button_command = button_command + 16;
        }
        if(button_command != prev_button_command){
            send_data(0,button_command);
            prev_button_command = button_command;
        }

        //long_period = cur + long_period_time_us;
        long_period_count = long_period_count + 1;
              
    }

    // 最終の有効コマンドを受け取ってから5秒経ったら、通信断絶として、画面表示を変える
    get_tim(&tim);
    if ((last_command_time + DETECT_COM_FAIL_PERIOD < tim)) {
        detect_com_fail();
    } 
    else{
        hub_display_image(text_ET); 
        hub_light_off();     
    }   
}


void
wait_read(char *buf, int size)
{
    serial_rea_dat(RASPIKE_PORTNO, buf, 1);
}


void
receiver_task(intptr_t exinf) {
    uint8_t cmd;
    uint8_t data1,data2;
    uint8_t idx;
    uint8_t cmd_id;
    int32_t value;
    SYSTIM tim;
    
    while(1) {
        while(1) {
            wait_read((char*)&cmd, 1);
            if (cmd & 0x80U)
                break;
        }
        
        while(1) {
            wait_read((char*)&data1, 1);
            num_command++;
            if (data1 & 0x80U) {    
                cmd = data1;
                num_fail++;
                continue;
            }
            idx = cmd & 0x7FU;     

            wait_read((char*)&data2, 1);

            num_command++;
            if (data2 & 0x80U) {
                cmd = data2;
                num_fail++;
                continue;
            }
            cmd_id = idx;
            value = ((data1 & 0x1F) << 7) | data2;      
            if (data1 & 0x20U)                          
              value = value * (-1);
              //syslog(LOG_NOTICE, "idx = %d: %d:%d %d", idx, data1, data2, value);
            break;                
        }

        if ((value < -2048) || (value > 2048)) {
            num_fail = num_fail + 1;
            continue;
        }
        
        // 有効なコマンドを受け取った最後の時間
        get_tim(&tim);
        last_command_time = tim;
        
        // 高速化のために、motorスピードを優先して判定する

        if (cmd_id == 1) {
            if ((value <= 100) && (value >= -100)) {
                 pup_motor_set_power(a_motor, value);
            }
        }
        else if (cmd_id == 2) {
            if ((value <= 100) && (value >= -100)) {
                pup_motor_set_power(r_motor, value);
            }
        }
        else if (cmd_id == 3) {
            if ((value <= 100) && (value >= -100)) {
                pup_motor_set_power(l_motor, value);
            }
        }
        else if (cmd_id == 5) {
            if (value == 1) {
                // motor_A.brake()
                pup_motor_brake(a_motor);
            }
            else {
                // motor_A.float()
                pup_motor_stop(a_motor);
            }                               
            motor_stop_a = 1;
        }
        else if (cmd_id == 6) {
            if (value == 1) {
                // motor_B.brake()
                pup_motor_brake(r_motor);
            }
            else {
                // motor_B.float()
                pup_motor_stop(r_motor);
            }
            motor_stop_r = 1;
        }
        else if (cmd_id == 7) {
            if (value == 1) {
                // motor_C.brake()
                pup_motor_brake(l_motor);
            }
            else {
                // motor_C.float()
                pup_motor_stop(l_motor);
            }
            motor_stop_l = 1;
        }
        else if (cmd_id == 9) {                  
            // motor_A.preset(0)
            pup_motor_reset_count(a_motor);
            motor_reset_a = 1;
        }
        else if (cmd_id == 10) {                  
            // motor_B.preset(0)
            pup_motor_reset_count(r_motor);
            motor_reset_r = 1;
        }
        else if (cmd_id == 11) {                  
            // motor_C.preset(0)
            pup_motor_reset_count(l_motor);
            motor_reset_l = 1;
        }

        else if (cmd_id == 61) {  
#if 0   
        //カラーセンサーのAPIを呼び出すとモードが自動的に切り替わるので記述していません.  

            // Port2 Color Sensor
            // Color Sensor Mode
            // 切り替えの間カラーセンサーの取得がされると不安定になるため、modeは一時的に0にする
            color_sensor_mode = 0;
            
            if (value == 1) {
                // Ambient
                // color_sensor.mode(2)
            }
            else if (value == 2) {
                // Color
                // color_sensor.mode(0)
            }
            else if (value == 3) {                
                // Reflect
                //    color_sensor.mode(1)
            }
            else if (value == 4) {                                      
                // RGB
                // color_sensor.mode(5)
            }
#endif

            //ダミーリード
            // cv = color_sensor.get();
            color_sensor_mode = value;      //color_sensor_mode切替え
            color_sensor_change = 1;        
        }
        
        else if (cmd_id == 62) {                  
            // Port3 Ultra Sonic Sensor
            // led = b''+chr(9)+chr(9)+chr(9)+chr(9);       //ライトオン？
            // ultrasonic_sensor.mode(5,led)                
            pup_ultrasonic_sensor_light_set(ult, 90, 90, 90, 90);       //違うかもしれません
            
#if 0
            //APIを呼び出すと自動的にモードが切り替わるため記述していない.
            if (value == 1) {
                // ultrasonic_sensor.mode(0)                
            }
            else if(value == 2) {
                // ultrasonic_sensor.mode(3)                
            }
#endif

            // 設定のまでのWait
            ultrasonic_sensor_mode = value;     //ultrasonic_sensor_mode切替え
            ultrasonic_sensor_change = 1;
        }
        else if (cmd_id == 13) {                  
            // Port4 Gyro Sensor
            gyro_sensor_mode = 0;
            if (value == 1) {
                hub_imu_init();
            }
            gyro_reset = 1;
        }                    
        else {
            other_command = cmd_id;
        }
    }   
}

/*
 * Main Task
 */
void
main_task(intptr_t exinf)
{
    ER_UINT	ercd;

    /*get device pointers*/
    a_motor = pup_motor_get_device(PBIO_PORT_ID_A);
    r_motor = pup_motor_get_device(PBIO_PORT_ID_B);
    l_motor = pup_motor_get_device(PBIO_PORT_ID_E);
    col = pup_color_sensor_get_device(PBIO_PORT_ID_C); 
    ult = pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_D);

    pup_color_sensor_detectable_colors(8, detect_color_for_EV3);    //lego公式APIに合わせる場合はpup_color_sensor_detectable_colors(12, detect_color_for_lego_official)

    /*set up right motor*/
    for(int i = 0; i < 10; i++)
    {
        bool reset_count = true;
        r_err = pup_motor_setup(r_motor, PUP_DIRECTION_CLOCKWISE, true);
        pup_motor_reset_count(r_motor);     //??
        if(r_err != PBIO_ERROR_AGAIN){
            break;
        }
        // Set up failed -> Wait 1s and ry one more
        dly_tsk(1000000);
    }

    /*set up left motor*/
    for(int i = 0; i < 10; i++){
        l_err = pup_motor_setup(l_motor, PUP_DIRECTION_COUNTERCLOCKWISE, true);
        pup_motor_reset_count(l_motor);     //??
        if(l_err != PBIO_ERROR_AGAIN){
            break;
        }
        // Set up failed -> Wait 1s and ry one more
        dly_tsk(1000000);
    }

    /*set up arm motor*/
    for(int i = 0; i < 10; i++){
        a_err = pup_motor_setup(a_motor, PUP_DIRECTION_CLOCKWISE, true);
        pup_motor_reset_count(a_motor);     //??
        if(a_err != PBIO_ERROR_AGAIN){
            break;
        }
        // Set up failed -> Wait 1s and ry one more
        dly_tsk(1000000);
    }

    hub_imu_init();
    dly_tsk(1000000);
    
    ercd = serial_opn_por(RASPIKE_PORTNO);
    if (ercd < 0 && MERCD(ercd) != E_OBJ) {
        syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
               itron_strerror(ercd), SERCD(ercd));
    }
    serial_ctl_por(RASPIKE_PORTNO, IOCTL_NULL); //フロー制御当を無効にする

    sta_cyc(NOTIFY_SENSOR_CYC);
    act_tsk(RECEIVER_TASK);

    while (1)
    {
        slp_tsk();
    }
}
