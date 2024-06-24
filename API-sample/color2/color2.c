#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color2.h"
#include "spike/pup/colorsensor.h"

#include <stdio.h>

#define MAX_BRIGTHNESS 20

void
main_task(intptr_t exinf)
{
  int brightness = 0;

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);
  
  pbio_error_t err;
  pup_device_t *col;

  col = pup_color_sensor_get_device(PBIO_PORT_ID_A);

  pup_color_sensor_light_off(col);

  dly_tsk(1*1000*1000);
  
  while (1)
  {
    while (brightness <= MAX_BRIGTHNESS)
    {
      pup_color_sensor_light_set(col, brightness, 0, 0);
      brightness += 1;
      dly_tsk(10*1000);
    }
    brightness = 0;
    dly_tsk(1*1000*1000);


    while (brightness <= MAX_BRIGTHNESS)
    {
      pup_color_sensor_light_set(col, MAX_BRIGTHNESS, brightness, 0);
      brightness += 1;
      dly_tsk(10*1000);
    }
    brightness = 0;
    dly_tsk(1*1000*1000);

    while (brightness <= MAX_BRIGTHNESS)
    {
      pup_color_sensor_light_set(col, MAX_BRIGTHNESS, MAX_BRIGTHNESS, brightness);
      brightness += 1;
      dly_tsk(10*1000);
    }
    brightness = 0;
    dly_tsk(1*1000*1000);

    pup_color_sensor_light_off(col);
    dly_tsk(1*1000*1000);
    pup_color_sensor_light_on(col);   // かなり眩しいです
    dly_tsk(1*1000*1000);
    pup_color_sensor_light_off(col);
    dly_tsk(1*1000*1000);

  }

}
