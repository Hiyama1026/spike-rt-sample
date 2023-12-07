// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <stdio.h>
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "multitask2.h"

#include <syssvc/serial.h>
#include <spike/hub/bluetooth.h>
#include "spike/pup/motor.h"

SYSTIM st;
pbio_error_t ma_err, mb_err;
pup_motor_t *motor_a;

int motor_direction = CLOCKWISE;
int motor_speed = 800;

void busy_wait (void)   // Wait for10 ms
{
  int32_t start_tim, cur_tim;
  get_tim(&st);
  start_tim = (int32_t)st;

  while(cur_tim - start_tim <= 10*1000) {
    get_tim(&st);
    cur_tim = (int32_t)st;
  }
  return;
}

void
ctrl_task(intptr_t exinf)   //3s周期かつmotor_task()より高優先度．
{
  pup_motor_hold(motor_a);
  if (motor_direction == CLOCKWISE)   motor_direction = COUNTER_CLOCKWISE;
  else                                motor_direction = CLOCKWISE;
  
}

void
motor_task(intptr_t exinf)
{
  while(1) {
    pup_motor_set_speed(motor_a, motor_speed * motor_direction);
    busy_wait();
  }
}

/*
 * Main Task
 */
void
main_task(intptr_t exinf)
{
  
  motor_a = pup_motor_get_device(PBIO_PORT_ID_A);
  ma_err = pup_motor_setup(motor_a, PUP_DIRECTION_CLOCKWISE, true);

  dly_tsk(1000000);

  syslog(LOG_NOTICE, "pup init done.");

  act_tsk(MOTOR_TASK);
  syslog(LOG_NOTICE, "act mptor task.");
  sta_cyc(CTRL_CYC);      //タイマ起動
  syslog(LOG_NOTICE, "act timer.");
  
  hub_display_image(img_smile);
  while (1)
  {
    slp_tsk();
  }
}
