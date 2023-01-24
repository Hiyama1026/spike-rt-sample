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

  //pbsys_user_program_prepare(NULL);
  //wup_pybricks();

  int count;
  while (1)
  {
    hub_button_t pressed;
    int command = 0;

    hub_button_is_pressed(&pressed);

    if((pressed & HUB_BUTTON_RIGHT) == HUB_BUTTON_RIGHT)    command = command + 1;
    if((pressed & HUB_BUTTON_LEFT) == HUB_BUTTON_LEFT)      command = command + 2;
    if((pressed & HUB_BUTTON_CENTER) == HUB_BUTTON_CENTER)  command = command + 4;
    if((pressed & HUB_BUTTON_BT) == HUB_BUTTON_BT)          command = command + 8;

    switch(command){
      case 1:
        hub_display_text("R", 1, 0);
        break;
      case 2:
        hub_display_text("L", 1, 0);
        break;
      case 3:
        hub_display_text_scroll(" R+L", 70);
        break;
      case 4:
        hub_display_text("C", 1, 0);
        break;
      case 5:
        hub_display_text_scroll(" R+C",70);
        break;
      case 6:
        hub_display_text_scroll(" L+C", 70);
        break;
      case 7:
        hub_display_text_scroll(" R+L+C", 70);
        break;
      case 8:
        hub_display_text("B", 1, 0);
        break;
      case 9:
        hub_display_text_scroll(" R+B",70);
        break;
      case 10:
        hub_display_text_scroll(" L+B", 70);
        break;
      case 11:
        hub_display_text_scroll(" R+L+B", 70);
        break;
      case 12:
        hub_display_text_scroll(" C+B", 70);
        break;
      case 13:
        hub_display_text_scroll(" R+C+B", 70);
        break;
      case 14:
        hub_display_text_scroll(" L+C+B", 70);
        break;
      case 15:
        hub_display_text_scroll(" ALL", 70);
        break;
      default:
        hub_display_text("-", 1, 0);
    }
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}
