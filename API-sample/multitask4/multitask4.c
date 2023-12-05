// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <stdio.h>
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "multitask4.h"

#include <syssvc/serial.h>
#include <spike/hub/bluetooth.h>
#include "spike/pup/motor.h"
#include "spike/hub/button.h"
#include "spike/hub/display.h"

hub_button_t pressed_ptn, pre_ptn;

void
display_task(intptr_t exinf)
{
  FLGPTN current_flg_ptn;

  while (1) {
    wai_flg(BUT_FLAG, BUTTONT_EVENT_MASK, TWF_ORW, &current_flg_ptn);  //TWF_OR　-> イベントフラグのOR待ち(待ち状態)

    if      (current_flg_ptn & HUB_BUTTON_CENTER)   hub_display_char('C');
    else if (current_flg_ptn & HUB_BUTTON_RIGHT)    hub_display_char('R');
    else if (current_flg_ptn & HUB_BUTTON_LEFT)     hub_display_char('L');
    else if (current_flg_ptn & HUB_BUTTON_BT)       hub_display_char('B');
  }
}

void
but_cyc_handler(intptr_t exinf)
{
  FLGPTN set_flg_ptn = 0;

  hub_button_is_pressed(&pressed_ptn);

  set_flg_ptn |= (FLGPTN)pressed_ptn;

  if (set_flg_ptn != pre_ptn) {
    iset_flg(BUT_FLAG, set_flg_ptn);
	}

  pre_ptn = pressed_ptn;
}

/*
 * Main Task
 */
void
main_task(intptr_t exinf)
{
  hub_display_char('-');
  dly_tsk(1000000);
  act_tsk(DISPLEY_TASK);
  sta_cyc(BUT_CYC);

  while (1)
  {
    slp_tsk();
  }
}
