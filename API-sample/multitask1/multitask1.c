// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <stdio.h>
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "multitask1.h"

#include "spike/hub/display.h"
#include "spike/pup/motor.h"

SYSTIM st;

pbio_error_t ma_err, mb_err, mc_err;
pup_motor_t *motor_a;
pup_motor_t *motor_b;

void busy_wait (void)   // Wait for 2 sec
{
  int32_t start_tim, cur_tim;
  get_tim(&st);
  start_tim = (int32_t)st;

  while(cur_tim - start_tim <= 2*1000*1000) {
    get_tim(&st);
    cur_tim = (int32_t)st;
  }
  return;
}

void
high_pri_task(intptr_t exinf)
{
  while (1) {
    pup_motor_set_speed(motor_a, 800);
    busy_wait();
    pup_motor_brake(motor_a);
    busy_wait();

    slp_tsk();
  }
}

void
mid_pri_task(intptr_t exinf)
{
  while (1)
  {
    pup_motor_set_speed(motor_b, 800);
    busy_wait();
    pup_motor_brake(motor_b);
    busy_wait();

    slp_tsk();
  }
}

void
low_pri_task(intptr_t exinf)
{
  while (1) {
    pup_motor_set_speed(motor_a, 800);
    pup_motor_set_speed(motor_b, 800);
    busy_wait();
    pup_motor_brake(motor_a);
    pup_motor_brake(motor_b);
    busy_wait();

    slp_tsk();
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
  motor_b = pup_motor_get_device(PBIO_PORT_ID_B);
  ma_err = pup_motor_setup(motor_b, PUP_DIRECTION_CLOCKWISE, true);


  dly_tsk(1000000);

  act_tsk(MOTOR_HIGH);    //mainタスクと同優先度だが，mainタスクの方が起動が早い為，mainタスクが休止状態に入るまで実行されない．
  act_tsk(MOTOR_LOW);     //mid_pri_task()より起動のタイミングが早いが，低優先度のため起動は最後．
  act_tsk(MOTOR_MID);     //高優先度タスクのhigh_pri_task()が休止状態に入ったら起動する．

  hub_display_image(img_smile);

  while (1)
  {
    slp_tsk();
  }
}
