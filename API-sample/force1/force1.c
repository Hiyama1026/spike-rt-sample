#include <t_syslog.h>
#include "kernel_cfg.h"
#include "force1.h"
#include "spike/pup/forcesensor.h"

#include <stdio.h>

void
main_task(intptr_t exinf)
{
  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 1.11);

  // Prepare the pybricks runtime for running a user program.
  // TODO: integrate pbsys_user_program_prepare() and wup_pybricks into one function. 
  pbsys_user_program_prepare(NULL);
  wup_pybricks();
  
  pbio_error_t err;
  pup_device_t *force;  
  dly_tsk(3000000);

  force = pup_force_sensor_get_device(PBIO_PORT_ID_A); //get pupMotor's devicePointer

  int got_force;
  int dist, per;
  float D_dist, temp_D_dist;
  int ite, dec;
  bool ps = false;
  while (1)
  {
    ps = pup_force_sensor_touched(force);
    if(ps == false){
      syslog(LOG_NOTICE, "Press a Force Senser");
      while(ps == false){
        ps = pup_force_sensor_touched(force);
      }
    }
    else{
      got_force = pup_force_sensor_force(force);
      dist = pup_force_sensor_distance(force);
      syslog(LOG_NOTICE, "Detect Force (force = %dN, dist = %dmm).", got_force, dist);  
    }
    dly_tsk(500000);  //wait 0.5s
  }
  pbsys_user_program_unprepare();
  wup_pybricks();
}
