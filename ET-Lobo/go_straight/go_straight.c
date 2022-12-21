#include <t_syslog.h>
#include "kernel_cfg.h"
#include "go_straight.h"
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
  hub_display_off();
  pup_motor_set_speed(r_motor, 350);
  pup_motor_set_speed(l_motor, 350);
  while (1)
  {   
    slp_tsk();
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
