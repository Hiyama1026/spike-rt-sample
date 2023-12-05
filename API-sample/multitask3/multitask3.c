// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */
#include <stdio.h>
#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "multitask3.h"

#include <syssvc/serial.h>
#include <spike/hub/bluetooth.h>
#include "spike/pup/motor.h"


pbio_error_t ma_err, mb_err;
pup_motor_t *motor_a;

void
motor_run_task(intptr_t exinf)
{
  while(1){
    wai_sem(MOTOR_SEM);  //セマフォ待ち
    pup_motor_set_speed(motor_a, 800);
    dly_tsk(3*1000*1000);
    sig_sem(MOTOR_SEM);  //セマフォ返却
  }
}

void
motor_stop_task(intptr_t exinf)
{
  while(1){
    wai_sem(MOTOR_SEM);    //セマフォ待ち
    pup_motor_brake(motor_a);
    dly_tsk(3*1000*1000);
    sig_sem(MOTOR_SEM);    //セマフォ返却 
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

  act_tsk(RUN_TASK);
  act_tsk(STOP_TASK);

  while (1)
  {
    slp_tsk();
  }
}
