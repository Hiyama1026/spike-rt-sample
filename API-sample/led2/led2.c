#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "led2.h"

#include "cbricks/hub/display.h"
#include "pbio/light_matrix.h"
#include <cbricks/hub/light.h>

#include <pbsys/light.h>
#include <pbio/light.h>
#include <pbio/color.h>

extern const uint8_t pb_font_5x5[95][5];

/*
 *  メインタスク
 */
void
main_task(intptr_t exinf)
{
  pbsys_user_program_prepare(NULL); // pbsys_processをユーザプログラム実行状態に遷移させる．

  hub_display_orientation(PBIO_SIDE_TOP);


  hub_display_off();
  //hub_light_on_color(pbsys_status_light, PBIO_COLOR_BLUE);
  hub_light_on_color(PBIO_COLOR_WHITE);

  while(1)
  {
    char a;
    a = '1';
    hub_display_char('a');
    dly_tsk(500000);
     hub_display_off();
    dly_tsk(500000);
    hub_display_char('a'+1);
    dly_tsk(500000);
    hub_display_off();
    dly_tsk(500000);
    hub_display_char(a);
    dly_tsk(500000);
     hub_display_off();
    dly_tsk(500000);
    hub_display_char(a+1);
    dly_tsk(500000);
    hub_display_off();
    dly_tsk(500000);
    
  }
}

