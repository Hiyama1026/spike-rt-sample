#include <t_syslog.h>
#include "kernel_cfg.h"
#include "dc_motor_straight.h"
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
#include "spike/hub/display.h"

//#include <pbsys/user_program.h>

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{
  pbio_error_t r_err;
  pbio_error_t l_err;
  pup_motor_t *r_motor;
  pup_motor_t *l_motor;

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  //pbsys_user_program_prepare(NULL);
  //wup_pybricks();
  
  dly_tsk(3000000);
  // printf("Set Up Motor\n");

  // Get pointer to servo
  r_motor = pup_motor_get_device(PBIO_PORT_ID_B); //get pupMotor's devicePointer
  l_motor = pup_motor_get_device(PBIO_PORT_ID_E);

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

  /*duty値指定でモーターを駆動*/
  pup_motor_set_duty_limit(r_motor, 50);
  pup_motor_set_duty_limit(l_motor, 50);
  pup_motor_set_speed(r_motor, 1000);     //指定速度はMax
  pup_motor_set_speed(l_motor, 1000);

  dly_tsk(7000000); //Wait 7s

  pup_motor_set_duty_limit(r_motor, 0);
  pup_motor_set_duty_limit(l_motor, 0);

  while (1)
  {
    slp_tsk();
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}