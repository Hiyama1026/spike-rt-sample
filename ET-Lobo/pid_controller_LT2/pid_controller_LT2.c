#include <t_syslog.h>
#include "kernel_cfg.h"
#include "pid_controller_LT2.h"
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"

//#include <pbsys/user_program.h>

static void motor_drive_control(int steering_amount, int R_motor_pt, int L_motor_pt){
  
  int left_motor_powor, right_motor_powor;

  /*走行エッジを右にする場合はRIGHT_EDGEに切り替える*/
  left_motor_powor = (int)(BACE_SPEED + (steering_amount * LEFT_EDGE));
  right_motor_powor = (int)(BACE_SPEED - (steering_amount * LEFT_EDGE));

  /*左右モーター駆動パワーの設定*/
  pup_motor_set_speed(L_motor_pt, left_motor_powor);
  pup_motor_set_speed(R_motor_pt, right_motor_powor);
}

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  pbsys_user_program_prepare(NULL);
  wup_pybricks();

  pbio_error_t r_err;
  pbio_error_t l_err;
  pup_motor_t *r_motor;
  pup_motor_t *l_motor;
  pup_device_t *col;
  
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
  // TEST_ASSERT_NOT_EQUAL(err, PBIO_ERROR_NO_DEV);
  // TEST_ASSERT_EQUAL(err, PBIO_SUCCESS);

  static float diff[2];
  static int target_brightness, reflection, integral;
  static float p, i, d, diff_brightness, steering_amount;
  while (1)
  {   
    /*ステアリングの操舵量を計算*/
    
    /*目標輝度*/
    target_brightness = (WHITE_BRIGHTNESS-BLACK_BRIGHTNESS)/2;
    /*カラーセンサー値の取得*/
    reflection =  pup_color_sensor_reflection(col);
    //syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", reflection);
    diff[0] = diff[1];
    /*目標輝度とカラーセンサー値の差分を計算*/
    diff[1] = (float)(target_brightness - reflection);
    /*ステアリング操舵量を計算*/
    integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;
    p = KP * diff[1];
    i = KI * integral;
    d = KD * (diff[1] - diff[0]) / DELTA_T; 
    steering_amount = p + i + d;

    /*走行モーター制御*/
    motor_drive_control(steering_amount, r_motor, l_motor);

    dly_tsk(4000);  //delay 4msec
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
