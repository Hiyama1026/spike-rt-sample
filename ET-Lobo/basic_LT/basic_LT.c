#include <t_syslog.h>
#include "kernel_cfg.h"
#include "basic_LT.h"
#include "cbricks/pup/motor.h"
#include "cbricks/pup/colorsensor.h"
#include "cbricks/pup/forcesensor.h"

//#include <pbsys/user_program.h>

static int steering_amount_calculation(int colorsensor_pt){
  int target_brightness;
  float diff_brightness;
  int steering_amount;
  int reflection;

  /*目標輝度*/
  target_brightness = (WHITE_BRIGHTNESS-BLACK_BRIGHTNESS)/2;
  /*カラーセンサー値の取得*/
  reflection =  pup_color_sensor_reflection(colorsensor_pt);
  /*目標輝度とカラーセンサー値の差分を計算*/
  diff_brightness = (float)(target_brightness - reflection);
  /*ステアリング操舵量を計算*/
  steering_amount = (int)(diff_brightness * STEERING_COF);

  return steering_amount;
}

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

  int steering_amount;

  while (1)
  {   
    /*ステアリングの操舵量を計算*/
    steering_amount = steering_amount_calculation(col);

    /*走行モーター制御*/
    motor_drive_control(steering_amount, r_motor, l_motor);
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
