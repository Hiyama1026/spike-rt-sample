#include <t_syslog.h>
#include "kernel_cfg.h"
#include "ultrasonic2.h"
#include "cbricks/pup/ultrasonicsensor.h"
#include "cbricks/hub/display.h"

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

  pbio_error_t err;
  pup_device_t *ult;
  dly_tsk(3000000);

  hub_display_off();
  ult = pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_A); //get devicePointer
  bool presence;
  while (1)
  {
    
    presence = pup_ultrasonic_sensor_presence(ult);
    if(presence == true) {
      pup_ultrasonic_sensor_light_on(ult);
      dly_tsk(1000000);   //これを消すと反応しなくなる、もしくは一瞬点灯して以降反応しなくなる
      syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 1);

    }
    else{
      pup_ultrasonic_sensor_light_off(ult);

    }  
    
    //dly_tsk(1000000);  
  }
  
  pbsys_user_program_unprepare();
  wup_pybricks();
}
