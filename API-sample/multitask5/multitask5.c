// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <stdio.h>
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "multitask5.h"

#include <syssvc/serial.h>
#include <spike/hub/bluetooth.h>
#include "spike/pup/motor.h"
#include "spike/hub/button.h"
#include "spike/hub/display.h"

struct data_packet
{
  pup_motor_t *motor;
  int speed;
  int idx;
  bool is_setup;
};


void
create_pkt (struct data_packet *entry, int dev)
{
  static int a_cnt, b_cnt;
  static bool a_first = true, b_first = true;

  if (dev == MOTOR_A) {
    entry->motor = pup_motor_get_device(PBIO_PORT_ID_A);
    entry->idx = a_cnt;
    if (a_first) {
      entry->is_setup = false;
      a_first = false;
    }
    else
      entry->is_setup = true;

    if (a_cnt++ == 10)  a_cnt = 0;
  }
  else {
    entry->motor = pup_motor_get_device(PBIO_PORT_ID_B);
    entry->idx = b_cnt;
    if (b_first) {
      entry->is_setup = false;
      b_first = false;
    }
    else
      entry->is_setup = true;

    if (b_cnt++ == 11)  b_cnt = 0;
  }

  entry->speed = 800;
}

void
motor_task(intptr_t exinf)
{
  intptr_t rev_datta_pkt;
  struct data_packet *receive_pkt;
  pbio_error_t m_err;

  while (1) {
    rcv_dtq(MOTOR_DTQ,  &rev_datta_pkt);    // データキュー受信待ち
    receive_pkt = rev_datta_pkt;

    if (!receive_pkt->is_setup)
      m_err = pup_motor_setup(receive_pkt->motor, PUP_DIRECTION_CLOCKWISE, true);

    if ((receive_pkt->idx % 2) == 0)
      pup_motor_set_speed(receive_pkt->motor, receive_pkt->speed);
    else 
      pup_motor_brake(receive_pkt->motor);
  }
}

void
but_cyc_handler(intptr_t exinf)   //1ms周期
{
  struct data_packet send_pkt;
  static hub_button_t pressed_ptn, pre_ptn;
  intptr_t send_data;

  hub_button_is_pressed(&pressed_ptn);

  if ((pressed_ptn & HUB_BUTTON_LEFT) && pre_ptn == 0) {
    create_pkt(&send_pkt, MOTOR_A);
    send_data = &send_pkt;

    snd_dtq(MOTOR_DTQ, send_data);    // データキューに送信
  }
  else if ((pressed_ptn & HUB_BUTTON_RIGHT) && pre_ptn == 0) {
    create_pkt(&send_pkt, MOTOR_B);
    send_data = &send_pkt;

    snd_dtq(MOTOR_DTQ, send_data);    // データキューに送信
  }
  pre_ptn = pressed_ptn;
}

/*
 * Main Task
 */
void
main_task(intptr_t exinf)
{
  act_tsk(MOTOR_TASK);
  sta_cyc(BUT_CYC);

  hub_display_image(img_smile);
  while (1)
  {
    slp_tsk();
  }
}
