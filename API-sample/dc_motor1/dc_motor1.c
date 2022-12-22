// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "dc_motor1.h"
#include "spike/pup/motor.h"
#include "spike/hub/button.h"

#include <pbio/servo.h>
#include <pbio/control.h>
#include <pbio/battery.h>

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

  pbio_error_t r_err;
  pbio_error_t l_err;
  pup_motor_t *r_motor;
  pbio_dcmotor_t **pt_r_dcmotor;
  pup_motor_t *l_motor;
  pbio_dcmotor_t **pt_l_dcmotor;
  
  dly_tsk(3000000);
  // printf("Set Up Motor\n");

  // Get pointer to servo
  r_motor = pup_motor_get_device(PBIO_PORT_ID_B); //get pupMotor's devicePointer
  l_motor = pup_motor_get_device(PBIO_PORT_ID_E);
  pt_r_dcmotor = &r_motor;
  pt_l_dcmotor = &l_motor;

  r_err = pybricks_c_common_dcmotor_make_new(pt_r_dcmotor, PBIO_PORT_ID_B, PBIO_DIRECTION_CLOCKWISE);
  l_err = pybricks_c_common_dcmotor_make_new(pt_l_dcmotor, PBIO_PORT_ID_E, PUP_DIRECTION_COUNTERCLOCKWISE);

  pybricks_c_common_dcmotor_duty(r_motor, 50);
  pybricks_c_common_dcmotor_duty(l_motor, 50);

  dly_tsk(7000000); //Wait 7s

  //pybricks_c_common_dcmotor_stop(r_motor);
  //pybricks_c_common_dcmotor_stop(l_motor);

  pybricks_c_common_dcmotor_brake(r_motor);
  pybricks_c_common_dcmotor_brake(l_motor);

  while (1)
  {
    slp_tsk();
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
