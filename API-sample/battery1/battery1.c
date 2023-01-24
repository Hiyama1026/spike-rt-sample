// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "battery1.h"
#include <spike/hub/battery.h>
#include <pbdrv/battery.h>

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
    int current, voltage;

    current = hub_battery_get_current();
    voltage = hub_battery_get_voltage();

    syslog(LOG_NOTICE, "current = %d mA.", current);
    syslog(LOG_NOTICE, "voltagef = %d mV).", voltage);

    dly_tsk(1000000);
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}
