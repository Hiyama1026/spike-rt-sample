// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "motor3.h"
#include "spike/pup/motor.h"
#include "spike/hub/button.h"
#include "spike/pup/colorsensor.h"

//#include <pbsys/user_program.h>

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

  pbio_error_t err;
  pup_motor_t *motor;
  pup_device_t *col;
  
  dly_tsk(3000000);

  // Get pointer to servo
  motor = pup_motor_get_device(PBIO_PORT_ID_B);
  col = pup_color_sensor_get_device(PBIO_PORT_ID_C);
  
  // Set up servo
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    err = pup_motor_setup(motor, PUP_DIRECTION_CLOCKWISE, reset_count);
    if(err != PBIO_ERROR_AGAIN)
      break;
  }
  pup_motor_set_duty_limit(motor, 70);    
    
  int restore;
  bool stop = false;
  hub_button_t pressed;

  pup_color_sensor_light_off(col);
  pup_motor_set_speed(motor, 400);

  while (1)
  {
    hub_button_is_pressed(&pressed);

    if((pup_motor_is_stalled(motor)) && stop == false){
      stop = true;
      restore = pup_motor_set_duty_limit(motor, 0);
      pup_color_sensor_light_on(col);
    }

    if((pressed == HUB_BUTTON_CENTER) && stop == true){
      stop = false;
      pup_motor_restore_duty_limit(motor, restore);
      pup_color_sensor_light_off(col); 
    }
  }
  pbsys_user_program_unprepare();
  wup_pybricks();
}
