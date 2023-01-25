#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "imu1.h"
#include <spike/hub/imu.h>
#include "spike/hub/display.h"

static uint8_t stay[1][25] = {
  {
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000, 
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
  },
};

static uint8_t right[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100, 
    0b0000000, 0b0000000, 0b1100100, 0b1100100, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};

static uint8_t left[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b1100100, 0b0000000, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100, 
    0b0000000, 0b1100100, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};

static uint8_t up[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b1100100, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100, 
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};

static uint8_t down[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100, 
    0b0000000, 0b1100100, 0b1100100, 0b1100100, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};

static uint8_t clock[1][25] = {
  {
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1100100,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1100100, 
    0b0000000, 0b0000000, 0b0000000, 0b1100100, 0b1100100,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1100100,
  },
};

static uint8_t counter[1][25] = {
  {
    0b1100100, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b1100100, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b1100100, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 
    0b1100100, 0b0000000, 0b0000000, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100,
  },
};



void
main_task(intptr_t exinf)
{
  float hub_velocity[3];
  int x_vel, y_vel, z_vel;
  int mod_x, mod_y, mod_z;

  hub_imu_init();
  while((hub_imu_init()) == PBIO_ERROR_FAILED	){
    hub_imu_init();
  }

  while(1){
    hub_imu_get_angular_velocity(&hub_velocity[0]);
    x_vel = hub_velocity[0];
    y_vel = hub_velocity[1];
    z_vel = hub_velocity[2];

    if(x_vel < 0)   mod_x = x_vel * (-1);
    else            mod_x = x_vel;
    if(y_vel < 0)   mod_y = y_vel * (-1);
    else            mod_y = y_vel;
    if(z_vel < 0)   mod_z = z_vel * (-1);
    else            mod_z = z_vel;

    if(mod_x < 5 && mod_y < 5 && mod_z < 5){
      hub_display_image(stay);
    }
    else if(mod_z <= mod_y){
      if(mod_y <= mod_x){
        if(x_vel > 0){
          hub_display_image(right);
        }
        else{
          hub_display_image(left);
        }
      }
      else{
        if(y_vel > 0){
          hub_display_image(up);
        }
        else{
          hub_display_image(down);
        }
      }
    }
    else{
      if(mod_z <= mod_x){
        if(x_vel > 0){
          hub_display_image(right);
        }
        else{
          hub_display_image(left);
        }
      }
      else{
        if(z_vel > 0){
          hub_display_image(counter);
        }
        else{
          hub_display_image(clock);
        }
      }
    }
    //syslog(LOG_NOTICE, "angular velocity : X = %d, Y = %d, Z = %d.", x_vel, y_vel, z_vel);
    dly_tsk(300000);
  }
}

