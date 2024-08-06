#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "imu4.h"
#include <spike/hub/imu.h>
#include "spike/hub/button.h"

float x_angle = 0;
hub_button_t pressed_ptn, pre_ptn;

void
ctrl_task(intptr_t exinf)   //10ms周期
{
  float hub_velocity[3];
  hub_imu_get_angular_velocity(&hub_velocity[0]);

  hub_button_is_pressed(&pressed_ptn);
  if ((pressed_ptn & HUB_BUTTON_CENTER) && !(pre_ptn & HUB_BUTTON_CENTER)){
    hub_imu_init();
    x_angle = 0;
    syslog(LOG_NOTICE, "reset");
  }
  pre_ptn = pressed_ptn;

  // Hub停止時の角速度の値が-1となる（個体差？）ため，角速度0から-1の範囲を0とする
  if (hub_velocity[2] <= 0 && (int)hub_velocity[2] >= -1){
    return;
  }
  
  x_angle += hub_velocity[2] * 0.01;
  
  syslog(LOG_NOTICE, "x angular velocity : %d", (int)x_angle);

}

void
main_task(intptr_t exinf)
{
  hub_imu_init();
  while((hub_imu_init()) == PBIO_ERROR_FAILED	){
    hub_imu_init();
  }

  sta_cyc(CTRL_CYC);      //タイマ起動

  while(1){
    slp_tsk();
  }
}

