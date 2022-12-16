#include <t_syslog.h>
#include "kernel_cfg.h"
#include "brightness_measure.h"
#include "spike/pup/colorsensor.h"
#include "spike/hub/display.h"

#include <stdio.h>

void
main_task(intptr_t exinf)
{
  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  pbsys_user_program_prepare(NULL);
  wup_pybricks();
  
  pbio_error_t err;
  pup_device_t *col;

  dly_tsk(3000000);

  col = pup_color_sensor_get_device(PBIO_PORT_ID_C);


  int ref;
  //pup_color_sensor_light_off(col);
  while (1)
  {
    ref = pup_color_sensor_reflection(col);
    hub_display_number(ref);
    dly_tsk(500000);
  }
}
