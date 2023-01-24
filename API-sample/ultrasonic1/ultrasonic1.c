// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "ultrasonic1.h"
#include "spike/pup/ultrasonicsensor.h"

//#include <pbsys/user_program.h>

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  //syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  // Prepare the pybricks runtime for running a user program.
  // TODO: integrate pbsys_user_program_prepare() and wup_pybricks into one function. 
  //pbsys_user_program_prepare(NULL);
  //wup_pybricks();

  pbio_error_t err;
  pup_device_t *ult;
  dly_tsk(3000000);

  ult = pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_A); //get devicePointer

  syslog(LOG_NOTICE, "Run a Ultrasonic Sensor");
  int dist;
  while (1)
  {
   dist = pup_ultrasonic_sensor_distance(ult);
   if(dist >= 0){
    if(dist <= 250){
      syslog(LOG_NOTICE, "Detect Objects (distance = %d mm).", dist);
      pup_ultrasonic_sensor_light_on(ult);
    }
    if(dist <= 500 && dist > 250){
      syslog(LOG_NOTICE, "Detect Objects (distance = %d mm).", dist);
      pup_ultrasonic_sensor_light_set(ult, 100, 100, 100, 0);
    }
    if(dist <= 750 && dist > 500){
      syslog(LOG_NOTICE, "Detect Objects (distance = %d mm).", dist);
      pup_ultrasonic_sensor_light_set(ult, 100, 100, 0, 0);
    }
    if(dist > 750){
      syslog(LOG_NOTICE, "Detect Objects (distance = %d mm).", dist);
      pup_ultrasonic_sensor_light_set(ult, 100, 0, 0, 0);
    }
   }
   else{
    syslog(LOG_NOTICE, "No Object");
    pup_ultrasonic_sensor_light_off(ult);
   }
   dly_tsk(500000);
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}
