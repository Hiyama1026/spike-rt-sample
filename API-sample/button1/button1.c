// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "button1.h"
#include "spike/pup/motor.h"
#include "spike/hub/button.h"
#include "spike/hub/display.h"
#include "pbio/light_matrix.h"

//#include <pbsys/user_program.h>

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  pbsys_user_program_prepare(NULL);
  wup_pybricks();

  int count;
  while (1)
  {
    hub_button_t pressed;

    hub_button_is_pressed(&pressed);

    switch(pressed){
      case HUB_BUTTON_RIGHT:
        hub_display_text("R", 1, 1);
        break;
      case HUB_BUTTON_LEFT:
        hub_display_text("L", 1, 1);
        break;
      case HUB_BUTTON_CENTER:
        hub_display_text("C", 1, 1);
        break;
      case HUB_BUTTON_BT:
        hub_display_text("B", 1, 1);
        break;
      default:
        hub_display_text("-", 1, 1);
    }
  }

  pbsys_user_program_unprepare();
  wup_pybricks();
}
