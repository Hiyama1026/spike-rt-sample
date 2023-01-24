// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "motor1.h"
#include "spike/pup/motor.h"
#include "spike/hub/button.h"

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
  //pbsys_user_program_prepare(NULL);
  //wup_pybricks();

  pbio_error_t err;
  pup_motor_t *motor;
  
  dly_tsk(3000000);
  // printf("Set Up Motor\n");

  // Get pointer to servo
  motor = pup_motor_get_device(PBIO_PORT_ID_A); //get pupMotor's devicePointer
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
    
    // Set up failed -> Wait 1s and ry one more
    dly_tsk(1000000);
  }
  // TEST_ASSERT_NOT_EQUAL(err, PBIO_ERROR_NO_DEV);
  // TEST_ASSERT_EQUAL(err, PBIO_SUCCESS);
  
  pup_motor_set_duty_limit(motor, 100);
  int speed = 500;
  err = pup_motor_set_speed(motor, speed);


  if (err != PBIO_SUCCESS)
  {
  }
 
  int count;
  while (1)
  {
    //syslog(LOG_NOTICE, "RUN BUTTON");
    SYSTIM st;
    hub_button_t buttons = wait_for_hub_buttons(HUB_BUTTON_RIGHT|HUB_BUTTON_LEFT|HUB_BUTTON_CENTER|HUB_BUTTON_BT);
    get_tim(&st);
    printf("%u: %d ", (unsigned int) st, buttons);

    if (buttons&HUB_BUTTON_LEFT)  {
      if(speed >= 1000){
        syslog(LOG_NOTICE, "MAXIMUM");
      }
      else{
        syslog(LOG_NOTICE, "LEFT/SPEED UP");
        speed += 50;
        pup_motor_set_speed(motor, speed);
      }
    } 

    if (buttons&HUB_BUTTON_RIGHT){
      if(speed <= 0){
        syslog(LOG_NOTICE, "MINIMUM");
      }
      else{
        syslog(LOG_NOTICE, "RIGHT/SPEED DOWN");
        speed -= 50;
        pup_motor_set_speed(motor, speed);
      }
    }

    if (buttons&HUB_BUTTON_CENTER){
      if(pup_motor_get_speed(motor) == 0){
        syslog(LOG_NOTICE, "CENTER/START");
        pup_motor_set_speed(motor, speed);
      }
      else{
        syslog(LOG_NOTICE, "CENTER/STOP");
        pup_motor_stop(motor);
        //pup_motor_brake(motor);
        //pup_motor_hold(motor);
      }
    } 
    
    if (buttons&HUB_BUTTON_BT){
      count = pup_motor_get_speed(motor);
      syslog(LOG_NOTICE, "Get Speed (speed = %d).", count);
    }
    printf("\n");
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}
