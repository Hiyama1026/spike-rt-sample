#include <t_syslog.h>
#include "kernel_cfg.h"
#include "switch_edge_LT.h"
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
#include "spike/hub/display.h"

//#include <pbsys/user_program.h>

extern int base_speed = 5;

static void motor_drive_control(int steering_amount, int R_motor_pt, int L_motor_pt, int edge){
  
  int left_motor_powor, right_motor_powor;

  left_motor_powor = (int)(base_speed + (steering_amount * edge));
  right_motor_powor = (int)(base_speed - (steering_amount * edge));

  /*左右モーター駆動パワーの設定*/
  pup_motor_set_duty_limit(L_motor_pt, left_motor_powor);
  pup_motor_set_duty_limit(R_motor_pt, right_motor_powor);
}

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{
  pbio_error_t r_err;
  pbio_error_t l_err;
  pup_motor_t *r_motor;
  pup_motor_t *l_motor;
  pup_device_t *col;

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  pbsys_user_program_prepare(NULL);
  wup_pybricks();

  
  
  dly_tsk(3000000);

  // Get pointer to servo
  r_motor = pup_motor_get_device(PBIO_PORT_ID_B);
  l_motor = pup_motor_get_device(PBIO_PORT_ID_E);
  col = pup_color_sensor_get_device(PBIO_PORT_ID_C); 
  
  /*右モーターをセットアップ*/
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    r_err = pup_motor_setup(r_motor, PUP_DIRECTION_CLOCKWISE, reset_count);
    if(r_err != PBIO_ERROR_AGAIN)
      break;
    
    // Set up failed -> Wait 1s and ry one more
    dly_tsk(1000000);
  }
  pup_motor_set_duty_limit(r_motor, base_speed);
  /*左モーターをセットアップ*/
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    l_err = pup_motor_setup(l_motor, PUP_DIRECTION_COUNTERCLOCKWISE, reset_count);
    if(l_err != PBIO_ERROR_AGAIN)
      break;
    
    // Set up failed -> Wait 1s and ry one more
    dly_tsk(1000000);
  }
  pup_motor_set_duty_limit(l_motor, base_speed);
  pup_motor_reset_count(l_motor);
  // TEST_ASSERT_NOT_EQUAL(err, PBIO_ERROR_NO_DEV);
  // TEST_ASSERT_EQUAL(err, PBIO_SUCCESS);

  bool test_change = false;
  bool is_change = false;
  bool passed_center = false;
  int edge = LEFT_EDGE;   //初めは左エッジ
  static float diff[2];
  static int now_brightness, target_brightness, reflection, integral, encoder_val, base_brightness, cnt;
  static float p, i, d, diff_brightness, steering_amount, Ke;
  base_brightness = (int)(WHITE_BRIGHTNESS-BLACK_BRIGHTNESS)/2;
  pup_motor_set_speed(r_motor, 1000);
  pup_motor_set_speed(l_motor, 1000);
  while (1)
  {   
    
    now_brightness = target_brightness;
    /*目標輝度を計算*/
    if(is_change == false){
    target_brightness = base_brightness;
    Ke = 0;
    base_speed =6;
    }
    else {
      if((passed_center == false) && (now_brightness > BLACK_BRIGHTNESS)){
        cnt++;
        base_speed = 4;
        if(cnt == 3){
          target_brightness = now_brightness - 1;
          cnt = 0;
          Ke = 0.17;
        }
      }
      else if((now_brightness == (double)BLACK_BRIGHTNESS) && (passed_center == false)){
        cnt++;
        base_speed = 4;
        if(cnt ==3){
          edge = RIGHT_EDGE;  //エッジ切り替え
          passed_center = true;
          cnt = 0;
          Ke = 0.17;
        }
      }
      else if((passed_center == true) && (now_brightness < base_brightness)){
        cnt++;
        base_speed = 4;
        if(cnt == 3){
          target_brightness = now_brightness + 1;
          cnt = 0;
          Ke = 0.17;
        }
        if((int)target_brightness == (int)base_brightness){
          passed_center = false;
          is_change = false;
        }
      }
    }
    hub_display_number(target_brightness);
    /*カラーセンサー値の取得*/
    reflection =  pup_color_sensor_reflection(col);
    diff[0] = diff[1];
    /*目標輝度とカラーセンサー値の差分を計算*/
    diff[1] = (float)(target_brightness - reflection);
    /*ステアリング操舵量を計算*/
    integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;
    p = (KP+Ke) * diff[1];
    i = KI * integral;
    d = KD * (diff[1] - diff[0]) / DELTA_T; 
    steering_amount = p + i + d;
    syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", Ke);
    /*走行モーター制御*/
    motor_drive_control(steering_amount, r_motor, l_motor, edge);

    
    encoder_val = pup_motor_get_count(l_motor);
    if((encoder_val >= 720) && test_change == false){
      is_change = true;
      test_change = true;
    }
    dly_tsk(3900);  //delay 4msec
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
