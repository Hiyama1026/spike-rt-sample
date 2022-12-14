#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color3.h"
#include "cbricks/pup/colorsensor.h"
#include "cbricks/hub/display.h"

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
  pup_device_t *col;

  dly_tsk(3000000);

  col = pup_color_sensor_get_device(PBIO_PORT_ID_A);


  int ref;
  //pup_color_sensor_light_off(col);
  while (1)
  {
    ref = pup_color_sensor_reflection(col);
    if(ref == 0){
      syslog(LOG_NOTICE, "reflectance : %d %%.", ref);
      hub_display_number(ref);
      while(ref == 0){
        ref = pup_color_sensor_reflection(col);
      }
    } 
    syslog(LOG_NOTICE, "reflectance : %d %%.", ref);
    hub_display_number(ref);
    dly_tsk(1000000);
  }
}
