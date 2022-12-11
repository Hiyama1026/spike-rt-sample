// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "motor2.h"
#include "cbricks/pup/motor.h"
#include "cbricks/hub/button.h"


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
  
  //pup_motor_set_duty_limit(motor, 100);


  if (err != PBIO_SUCCESS)
  {
  }
 
  int Penc, enc;
  syslog(LOG_NOTICE, "Turn the motor");
  while (1)
     {
       enc = pup_motor_get_count(motor);
       if(enc - Penc > 3 || enc - Penc < -3){
         syslog(LOG_NOTICE, "Sample program (count = %d).", enc);
         Penc = enc;
       }
       if(enc>=180 || enc<=-180){
         syslog(LOG_NOTICE, "reset");
         pup_motor_reset_count(motor);
         enc = pup_motor_get_count(motor);
       }
     }
  pbsys_user_program_unprepare();
  wup_pybricks();
}
