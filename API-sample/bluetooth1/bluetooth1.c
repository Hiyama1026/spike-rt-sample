// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "bluetooth1.h"

#include <syssvc/serial.h>
#include <spike/hub/bluetooth.h>

#include "spike/hub/button.h"
#include "spike/hub/display.h"
#include "serial/serial.h"

ER ercd_op, ercd_wr, ercd_re;

void
wait_for_connect (void)
{
  hub_display_off();
  
  act_tsk(DISPLAY_TASK);
  ercd_op = serial_opn_por(SIO_BLUETOOTH_PORTID);
  ter_tsk(DISPLAY_TASK);

  hub_display_off();
  hub_display_image(img_smile);

  return;
}

void
display_task(intptr_t exinf)
{
  while (1)
  {
    hub_display_text_scroll("READY", 100);  //出力後休止状態に
    dly_tsk(100*1000);
  } 
}

void
check_task(intptr_t exinf)
{
  bool is_connected;

  while (1)
  {
    hub_bluetooth_is_connected(&is_connected);
    if (!is_connected)
      wait_for_connect();

    dly_tsk(500*1000);
  } 
}

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{
  const char init_msg[] = "\nWrite data via Bluetooth.\n";

  wait_for_connect();

  dly_tsk(1*1000*1000);

  ercd_wr = serial_wri_dat(SIO_BLUETOOTH_PORTID, init_msg, sizeof(init_msg));
  
  dly_tsk(500*1000);

  syslog(LOG_NOTICE, "open (err = %d).", ercd_op);
  syslog(LOG_NOTICE, "write (err = %d).", ercd_wr);

  act_tsk(CHECK_TASK);

  while (1)
  {
    char input[3];
    bool is_connected;

    const char write_msg[] = "\nInput 3 characters to send and display.\nInput : ";

    ercd_wr = serial_wri_dat(SIO_BLUETOOTH_PORTID, write_msg, sizeof(write_msg));
    ercd_re = serial_rea_dat(SIO_BLUETOOTH_PORTID, input, sizeof(input));
    ercd_wr = serial_wri_dat(SIO_BLUETOOTH_PORTID, "\nSnd to Hub via Bluetooth!!\n", sizeof("\nSnd to Hub via Bluetooth!!\n"));

    dly_tsk(500*1000);
    hub_display_text_scroll(input, 150);
    dly_tsk(500*1000);
    hub_display_image(img_smile);

  }
}
