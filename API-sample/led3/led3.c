#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "led3.h"

#include "spike/hub/display.h"
#include "pbio/light_matrix.h"
#include <spike/hub/light.h>

#include <pbsys/light.h>
#include <pbio/light.h>
#include <pbio/color.h>

#include "spike/pup/colorsensor.h"

extern const uint8_t pb_font_5x5[95][5];

/*
 *  メインタスク
 */
void
main_task(intptr_t exinf)
{
  //pbsys_user_program_prepare(NULL); // pbsys_processをユーザプログラム実行状態に遷移させる．
  
  //pup_device_t *col;
  //col = pup_color_sensor_get_device(PBIO_PORT_ID_B);

  hub_display_orientation(PBIO_SIDE_TOP);
  

  hub_display_off();
  //hub_light_on_color(pbsys_status_light, PBIO_COLOR_BLUE);
  hub_light_on_color(PBIO_COLOR_WHITE);

  pup_color_hsv_t c_hsv;
  pbio_color_hsv_t beige_hsv[3] = {
    {
      0b00100001, 0b01011010, 0b01000101,
    },
  };

  hub_light_on_hsv(beige_hsv);  //h=33 s=90 v=69
  while(1)
  {
    slp_tsk();
  }
}

