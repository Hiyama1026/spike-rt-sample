// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "motor4.h"
#include "spike/pup/motor.h"
#include "spike/pup/forcesensor.h"

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  //pbsys_user_program_prepare(NULL);
  //wup_pybricks();

  pbio_error_t err;
  pup_motor_t *motor;
  pup_device_t *force;
  
  dly_tsk(3000000);

  // Get pointer to servo
  motor = pup_motor_get_device(PBIO_PORT_ID_A);
  force = pup_force_sensor_get_device(PBIO_PORT_ID_D);
  
  // Set up servo
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    err = pup_motor_setup(motor, PUP_DIRECTION_CLOCKWISE, reset_count);
    if(err != PBIO_ERROR_AGAIN)
      break;
  }

  int force_val;

  while (1)
  {
    force_val = pup_force_sensor_force(force);
    pup_motor_set_speed(motor, force_val * 100);

    dly_tsk(10000);  //wait 0.01s
  }
}
