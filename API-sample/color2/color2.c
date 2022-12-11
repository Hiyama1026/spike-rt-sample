#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color2.h"
#include "cbricks/pup/colorsensor.h"

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


  int i;
  bool filled = false;
  //pup_color_sensor_light_off(col);
  while (1)
  {
    if(filled == false){
      for(i=0; i<=150; i=i+1){
        if((i-50)>=0){
          pup_color_sensor_light_set(col, i, i-25, i-50);
          if(i==150){
            filled = true;
          }
        }
        else if((i-25)>=0){
          pup_color_sensor_light_set(col, i, i-25, 0);
        }
        else{
          pup_color_sensor_light_set(col, i, 0, 0);
        }  
      }
    }
    else {
      for(i=150; i>=0; i=i-1){
        if((i-50)>=0){
          pup_color_sensor_light_set(col, i, i-25, i-50);
        }
        else if((i-25)>=0){
          pup_color_sensor_light_set(col, i, i-25, 0);
        }
        else{
          pup_color_sensor_light_set(col, i, 0, 0);
          if(i == 0){
            filled = false;
          }
        }  
      }
    }
    dly_tsk(1000000);
  }
}
