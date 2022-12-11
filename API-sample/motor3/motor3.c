// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "motor3.h"
#include "cbricks/pup/motor.h"
#include "cbricks/hub/button.h"
#include "cbricks/pup/colorsensor.h"


static inline hub_button_t hub_buttons_pressed(hub_button_t buttons)
{
  hub_button_t pressed;
  hub_button_is_pressed(&pressed);
  return pressed & buttons;
}

static hub_button_t wait_for_hub_buttons(hub_button_t buttons_to_watch)

{
  hub_button_t buttons = 0;
  hub_button_t pressed;
  while (hub_buttons_pressed(buttons_to_watch) == 0) dly_tsk(10000);
  while (pressed = hub_buttons_pressed(buttons_to_watch), pressed != 0) {
    buttons |= pressed;
    dly_tsk(10000);
  }
  return buttons;
}

//#include <pbsys/user_program.h>

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  // Prepare the pybricks runtime for running a user program.
  // TODO: integrate pbsys_user_program_prepare() and wup_pybricks into one function. 
  pbsys_user_program_prepare(NULL);
  wup_pybricks();

  pbio_error_t err;
  pup_motor_t *motor;
  pup_device_t *ult;
  pup_device_t *col;
  pup_device_t *foce;
  
  dly_tsk(3000000);
  // printf("Set Up Motor\n");

  // Get pointer to servo
  motor = pup_motor_get_device(PBIO_PORT_ID_A); //get pupMotor's devicePointer
  col = pup_color_sensor_get_device(PBIO_PORT_ID_E);
  if(motor == NULL)
  {

  }
  
  // Set up servo
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    err = pup_motor_setup(motor, PUP_DIRECTION_CLOCKWISE, reset_count);
    if(err != PBIO_ERROR_AGAIN)
      break;
  }
    
  int duty = 40;
  pup_motor_set_duty_limit(motor, duty);
  
  bool stl;
  dly_tsk(1000000);
  pup_color_sensor_light_off(col);
  pup_motor_set_speed(motor, 1000);
  while (1)
  {
    stl = pup_motor_is_stalled(motor);
    if(stl){
      pup_color_sensor_light_on(col);
      if(duty<=100){
        duty = duty + 5;
        pup_motor_set_duty_limit(motor, duty);
        
      }
    }
    else{
      pup_color_sensor_light_off(col);
      duty = 40;
      pup_motor_set_duty_limit(motor, duty);
    }
    syslog(LOG_NOTICE, "Duty : %d", duty);
    dly_tsk(1000000);
  }
  pbsys_user_program_unprepare();
  wup_pybricks();
}
