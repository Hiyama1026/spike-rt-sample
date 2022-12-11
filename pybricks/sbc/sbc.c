// SPDX-License-Identifier: MIT
/*
 * Copyright (c) 2022 Embedded and Real-Time Systems Laboratory,
 *                    Graduate School of Information Science, Nagoya Univ., JAPAN
 */

#include <t_syslog.h>
#include "kernel_cfg.h"
#include "sbc.h"
#include "cbricks/pup/motor.h"
#include "cbricks/pup/ultrasonicsensor.h"
#include "cbricks/pup/colorsensor.h"

#include "cbricks/hub/display.h"
#include "pbio/light_matrix.h"

#include "pbsys/light.h"
#include "pbio/light.h"
#include "pbio/color.h"

#include "pup_device.h"
#include "cb_error.h"

//#include <pbsys/user_program.h>

extern const uint8_t pb_font_5x5[95][5];

//int h = 100;

static const uint8_t up[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b1100100, 0b1100100, 0b0000000,
    0b1100100, 0b1100100, 0b1100100, 0b1100100, 0b1100100, 
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};

pbio_color_hsv_t CREATE_COLOR_BAIGE[3] = {
    {
      0b00100001, 0b01011010, 0b01000101,
    },
  };
pbio_color_hsv_t CREATE_COLOR_EMERALD[3] = {
    {
      0b10001100, 0b01100100, 0b01100100,
    },
  };
pbio_color_hsv_t CREATE_COLOR_LIME[3] = {
    {
      0b01010000, 0b01100100, 0b01100100,
    },
  };

static void light_on(int cnt){
  if(cnt == 0) {
      hub_light_on_color(PBIO_COLOR_ORANGE);
    }
    if(cnt == 1) {
      hub_light_on_color(PBIO_COLOR_CYAN);
    }
    else if(cnt == 2) {
      hub_light_on_hsv(CREATE_COLOR_LIME);
    }
    else if(cnt == 3) {
      hub_light_on_color(PBIO_COLOR_YELLOW);
    }
    else if(cnt == 4) {
      hub_light_on_color(PBIO_COLOR_BLUE);
    }
    else if(cnt == 5) {
      hub_light_on_color(PBIO_COLOR_GREEN);
    }
    else if(cnt == 6) {
      hub_light_on_color(PBIO_COLOR_RED);
    }   
    else if(cnt == 7) {
      hub_light_on_hsv(CREATE_COLOR_BAIGE);
    }
    else if(cnt == 8) {
      hub_light_on_color(PBIO_COLOR_VIOLET);
    }
    else if(cnt == 9) {
      hub_light_on_hsv(CREATE_COLOR_EMERALD);
    }
    else if(cnt == 10) {
      hub_light_on_color(PBIO_COLOR_MAGENTA);
    }
}

/*
 * Main Task
 */
#include <stdio.h>
void
main_task(intptr_t exinf)
{

  syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", 0);

  // Prepare the pybricks runtime for running a user program.
  // TODO: integrate pbsys_user_program_prepare() and wup_pybricks into one function. 
  pbsys_user_program_prepare(NULL);
  wup_pybricks();

  pbio_error_t err;
  pup_motor_t *motor;
  pup_device_t *ult;
  pup_device_t *col;
  
  dly_tsk(3000000);
  // printf("Set Up Motor\n");

  // Get pointer to servo
  motor = pup_motor_get_device(PBIO_PORT_ID_E); //get pupMotor's devicePointer
  ult = pup_ultrasonic_sensor_get_device(PBIO_PORT_ID_D);
  col = pup_color_sensor_get_device(PBIO_PORT_ID_B);
  if(motor == NULL)
  {

  }
  
  // Set up servo
  for(int i = 0; i < 10; i++)
  {
    bool reset_count = true;
    err = pup_motor_setup(motor, PUP_DIRECTION_COUNTERCLOCKWISE, reset_count);
    if(err != PBIO_ERROR_AGAIN)
      break;
    
    // Set up failed -> Wait 1s and ry one more
    dly_tsk(1000000);
  }
  // TEST_ASSERT_NOT_EQUAL(err, PBIO_ERROR_NO_DEV);
  // TEST_ASSERT_EQUAL(err, PBIO_SUCCESS);
  
  pup_motor_set_duty_limit(motor, 100);
  err = pup_motor_set_speed(motor, 0);


  if (err != PBIO_SUCCESS)
  {
  }

  hub_display_off();
  hub_light_on_color(PBIO_COLOR_WHITE);
  pup_color_sensor_light_off(col);

  pup_color_hsv_t color;
  int count;
  int dist = -1;
  bool st = false;
  bool pre_not_W = true;

  while (1)
  {

    if(st == false){  
      hub_display_image(up);
      hub_light_on_color(PBIO_COLOR_WHITE);
      pup_ultrasonic_sensor_light_on(ult);
      dist = pup_ultrasonic_sensor_distance(ult);
      if(dist >= 0 && dist <= 80){
        st = true;
        pup_color_sensor_light_on(col);
        pup_motor_set_speed(motor, 170);
        light_on(count);
      }
    }

    else if(st == true){  
      color = pup_color_sensor_color(col, true);
      hub_display_char('0'+count);
      if((color.h == 0 && color.s == 0 && color.v == 100) && pre_not_W == true){
        pre_not_W = false;
        pup_ultrasonic_sensor_light_off(ult);
        count++;
        light_on(count);
        if(count == 10){         
          count = 0;
          pup_motor_stop(motor);
          hub_display_text("10", 500, 250);
          st = false;
          pup_ultrasonic_sensor_light_on(ult);
          pup_color_sensor_light_off(col);
          pb_assert(pbio_light_matrix_clear(pbsys_hub_light_matrix));
        }
        pup_ultrasonic_sensor_light_on(ult);
      }
      else if(color.h != 0 || color.s != 0 || color.v != 100){    //Not white
        pre_not_W = true;
      }
    }
      
  }
}
