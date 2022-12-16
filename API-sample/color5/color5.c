#include <t_syslog.h>
#include "kernel_cfg.h"
#include "color5.h"
#include "spike/pup/colorsensor.h"
#include "pbio/color.h"
#include <stdio.h>

//pup_color_hsv_t *ori_color;
pup_color_hsv_t ori_color[] = {
  
  { PBIO_COLOR_HUE_RED, 0b01100100, 0b01100100 },
  { PBIO_COLOR_HUE_YELLOW, 0b01100100, 0b01100100 },
  { PBIO_COLOR_HUE_GREEN, 0b01100100, 0b01100100 },
  { PBIO_COLOR_HUE_BLUE, 0b01100100, 0b01100100 },
	{ 0b000100101100, 0b01100100, 0b01100100 }, //Magenta
  { 0b10110100, 0b01100100, 0b01100100 }, //Cyan
  {	0, 0, 0b01100100	},//White
  {	0, 0, 0b1010	},//Brack
  { 0, 0, 0} , //None
};

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

  col = pup_color_sensor_get_device(PBIO_PORT_ID_B);

  pup_color_sensor_detectable_colors(9, ori_color);

  pup_color_hsv_t hsv;
  pup_color_hsv_t color;
  
  while (1)
  {
    hsv = pup_color_sensor_hsv(col, true);
    color = pup_color_sensor_color(col, true);
    syslog(LOG_NOTICE, "HSV:H = %d  S = %d  V = %d).", hsv.h, hsv.s, hsv.v);

    if(color.h == 300 && color.s == 100 && color.v == 100)                    syslog(LOG_NOTICE, "Rounded Color : MAGENTA");
    if(color.h == 180 && color.s == 100 && color.v == 100)                     syslog(LOG_NOTICE, "Rounded Color : CYAN");
    if(color.h == PBIO_COLOR_HUE_RED && color.s == 100 && color.v == 100)     syslog(LOG_NOTICE, "Rounded Color : RED");
    if(color.h == PBIO_COLOR_HUE_YELLOW && color.s == 100 && color.v == 100)  syslog(LOG_NOTICE, "Rounded Color : YELLOW");
    if(color.h == PBIO_COLOR_HUE_GREEN && color.s == 100 && color.v == 100)   syslog(LOG_NOTICE, "Rounded Color : GREEN");
    if(color.h == PBIO_COLOR_HUE_BLUE && color.s == 100 && color.v == 100)    syslog(LOG_NOTICE, "Rounded Color : BLUE");
    if(color.h == 0 && color.s == 0 && color.v == 100)                        syslog(LOG_NOTICE, "Rounded Color : WHITE");
    if(color.h == 0 && color.s == 0 && color.v == 10)                          syslog(LOG_NOTICE, "Rounded Color : BRACK");
    if(color.h == 0 && color.s == 0 && color.v == 0)                          syslog(LOG_NOTICE, "Rounded Color : NON");
    
    dly_tsk(1000000);
  }
}
