#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color4.h"
#include "cbricks/pup/colorsensor.h"
#include "cbricks/pup/ultrasonicsensor.h"
#include "pbio/color.h"
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
  pup_device_t *ult;

  dly_tsk(3000000);

  col = pup_color_sensor_get_device(PBIO_PORT_ID_A);
  ult = pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_B);

  int amb;
  while (1)
  {
    amb = pup_color_sensor_ambient(col);
    syslog(LOG_NOTICE, "amb = %d %%", amb);

    if(amb > 10 && amb <= 40)      pup_ultrasonic_sensor_light_set(ult, 0, 0, 30, 30);
    else if(amb <= 10) pup_ultrasonic_sensor_light_set(ult, 100, 100, 30, 30);
    else               pup_ultrasonic_sensor_light_off(ult);

    dly_tsk(1000000);
  }
}