#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "template.h"

#include <pbsys/light.h>

/*
 *  メインタスク
 */
void
main_task(intptr_t exinf)
{
  int scroll_time = 60;
  syslog(LOG_NOTICE, "This is a project template.");
  
  hub_display_orientation(PBIO_SIDE_TOP);
  hub_display_off();

  while(1)
  {
    hub_display_text_scroll("PROJECT TEMPLATE", scroll_time);
    dly_tsk(1000000);
  }
}

