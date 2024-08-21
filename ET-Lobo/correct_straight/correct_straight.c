#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "correct_straight.h"
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
#include "spike/hub/display.h"
#include "spike/hub/button.h"

#define STEER_LIMIT 20
#define ENABLE_KP_SETTING false

pbio_error_t r_err;
pbio_error_t l_err;
pup_motor_t *r_motor;
pup_motor_t *l_motor;
pup_device_t *col;
hub_button_t pressed, pre_pressed_button;

double KP;  //base_speed=100, KP=2またはbase_speed=80, KP=1.5でそこそこ上手く動いた
int base_speed = 80;

int r_speed = 100;
int l_speed = 100;
int steering_amount;
int temp_r_speed, temp_l_speed;
int current_r_cnt,diff_r_count , start_r_cnt;
int current_l_cnt, diff_l_count, start_l_cnt;

int steering_amount_limit(int ori_val)
{
  if (ori_val >= STEER_LIMIT) return STEER_LIMIT;
  else if (ori_val <= -STEER_LIMIT) return -STEER_LIMIT;
  else return ori_val;
}

int motor_speed_limit(int ori_val)
{
  if (ori_val >= 100) return 100;
  else if (ori_val < 0) return 0;
  else return ori_val;
}

ctrl_task(intptr_t exinf)   //1ms周期, 高優先度
{
  current_r_cnt = pup_motor_get_count(r_motor);
  current_l_cnt = pup_motor_get_count(l_motor);
  diff_r_count = current_r_cnt - start_r_cnt;
  diff_l_count = current_l_cnt - start_l_cnt;

  steering_amount = (int)((double)(diff_r_count - diff_l_count) * KP);
  steering_amount = steering_amount_limit(steering_amount);

  l_speed = motor_speed_limit(base_speed + steering_amount);
  r_speed = motor_speed_limit(base_speed - steering_amount);
  //syslog(LOG_NOTICE, "LEFT r_speed: %d, l_speed: %d", r_speed, l_speed);
}

void
motor_task(intptr_t exinf)  //10ms周期
{
  pup_motor_set_power(r_motor, r_speed);
  pup_motor_set_power(l_motor, l_speed);
}

/*
 *  メインタスク
 */
void
main_task(intptr_t exinf)
{

  // Get pointer to servo
  r_motor = pup_motor_get_device(PBIO_PORT_ID_B);
  l_motor = pup_motor_get_device(PBIO_PORT_ID_E);
  col = pup_color_sensor_get_device(PBIO_PORT_ID_C); 
  int button_cnt;
  static int pre_button_cnt;
  
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
  pup_motor_reset_count(r_motor);

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
  pup_motor_reset_count(l_motor);

  #if ENABLE_KP_SETTING
  // KP設定機能あり
  hub_display_number(0);
  while (1)
  {
    hub_button_is_pressed(&pressed);
    if (pre_pressed_button != pressed) {
      if (pressed & HUB_BUTTON_CENTER)
        break;
      else if (pressed & HUB_BUTTON_LEFT)
        button_cnt++;
      else if (pressed & HUB_BUTTON_RIGHT) 
        if (button_cnt > 0) button_cnt--;
        
      if (button_cnt != pre_button_cnt) 
        hub_display_number(button_cnt);
      pre_button_cnt = button_cnt;
    }

    pre_pressed_button = pressed;
  }
  KP = button_cnt * 0.1;
  #else

  //KP決め打ち
  while (1)
  {
    hub_button_is_pressed(&pressed);
    if (pressed == HUB_BUTTON_CENTER) break;
  }
  KP = 1.5;
  #endif

  dly_tsk(3000000);

  hub_display_off();
  
  start_r_cnt = pup_motor_get_count(r_motor);
  start_l_cnt = pup_motor_get_count(l_motor);
  syslog(LOG_NOTICE, "start_r_cnt: %d, start_l_cnt: %d", start_r_cnt, start_l_cnt);

  syslog(LOG_NOTICE, "Timer start");
  
  sta_cyc(MOT_CYC);      //タイマ起動
  sta_cyc(CTRL_CYC);      //タイマ起動
  
  while(1)
  {
    slp_tsk();
  }
}
