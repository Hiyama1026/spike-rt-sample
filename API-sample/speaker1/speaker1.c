// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "speaker1.h"
#include "spike/hub/speaker.h"
#include "spike/pup/motor.h"

int16_t hz = 100;
static pbio_error_t r_err;  
static pup_motor_t *r_motor;

//#include <pbsys/user_program.h>

   


/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{
  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  r_motor = pup_motor_get_device(PBIO_PORT_ID_B);

  for(int i = 0; i < 10; i++)
    {
        bool reset_count = true;
        r_err = pup_motor_setup(r_motor, PUP_DIRECTION_CLOCKWISE, true);
        pup_motor_reset_count(r_motor);
        if(r_err != PBIO_ERROR_AGAIN){
            break;
        }
        // Set up failed -> Wait 1s and ry one more
        dly_tsk(1000000);
    }
  hub_speaker_play_tone(1800, SOUND_MANUAL_STOP);
  hub_speaker_set_volume(20);


  int count;
  while (1)
  {
    //hub_speaker_play_tone(1800, 1000);
    hub_speaker_play_tone(1800, SOUND_MANUAL_STOP);
    pup_motor_set_power(r_motor, 80);
    dly_tsk(1*1000*1000);
    pup_motor_set_power(r_motor, 0);
    dly_tsk(1*1000*1000);
    hub_speaker_stop();
    dly_tsk(1*1000*1000);
  }

  //pbsys_user_program_unprepare();
  //wup_pybricks();
}
