#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "imu3.h"
#include <spike/hub/imu.h>


void
main_task(intptr_t exinf)
{
  float hub_accel[3];
  int x_accel, y_accel, z_accel;

  hub_imu_init();
  while((hub_imu_init()) == PBIO_ERROR_FAILED	){
    hub_imu_init();
  }

  while(1){
    hub_imu_get_acceleration(&hub_accel[0]);
    x_accel = hub_accel[0];
    y_accel = hub_accel[1];
    z_accel = hub_accel[2];
    
    syslog(LOG_NOTICE, "acceleration : X = %d, Y = %d, Z = %d.", x_accel, y_accel, z_accel);
    dly_tsk(300000);
  }
}

