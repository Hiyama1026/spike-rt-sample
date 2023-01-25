#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "imu2.h"
#include <spike/hub/imu.h>
#include "spike/hub/display.h"


void
main_task(intptr_t exinf)
{
  int temperature;

  hub_imu_init();
  while((hub_imu_init()) == PBIO_ERROR_FAILED	){
    hub_imu_init();
  }

  while(1){
    temperature = hub_imu_get_temperature();

    hub_display_number(temperature);

    dly_tsk(1000000);
  }
}

