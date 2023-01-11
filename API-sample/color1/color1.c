#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color1.h"
#include "spike/pup/colorsensor.h"

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

  col = pup_color_sensor_get_device(PBIO_PORT_ID_C);

  pup_color_hsv_t hsv;
  pup_color_hsv_t color;
  pup_color_rgb_t measured_rgb;
  
  while (1)
  {
    hsv = pup_color_sensor_hsv(col, true);
    color = pup_color_sensor_color(col, true);
    measured_rgb = pup_color_sensor_rgb(col);
    syslog(LOG_NOTICE, "HSV:H = %d  S = %d  V = %d).", hsv.h, hsv.s, hsv.v);
    syslog(LOG_NOTICE, "RGB:R = %d  G = %d  B = %d).", measured_rgb.r, measured_rgb.g, measured_rgb.b);

    if(color.h == PBIO_COLOR_HUE_RED && color.s == 100 && color.v == 100)    syslog(LOG_NOTICE, "Rounded Color : RED");
    if(color.h == PBIO_COLOR_HUE_YELLOW && color.s == 100 && color.v == 100) syslog(LOG_NOTICE, "Rounded Color : YELLOW");
    if(color.h == PBIO_COLOR_HUE_GREEN && color.s == 100 && color.v == 100)  syslog(LOG_NOTICE, "Rounded Color : GREEN");
    if(color.h == PBIO_COLOR_HUE_BLUE && color.s == 100 && color.v == 100)   syslog(LOG_NOTICE, "Rounded Color : BLUE");
    if(color.h == 0 && color.s == 0 && color.v == 100)                       syslog(LOG_NOTICE, "Rounded Color : WHITE");
    if(color.h == 0 && color.s == 0 && color.v == 0)                         syslog(LOG_NOTICE, "Rounded Color : NON");
    
    dly_tsk(1000000);
  }
}