#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "led1.h"

#include "spike/hub/display.h"
#include "pbio/light_matrix.h"
#include <spike/hub/light.h>

#include <pbsys/light.h>
#include <pbio/light.h>
#include <pbio/color.h>

extern const uint8_t pb_font_5x5[95][5];

static uint8_t ex[1][25] = {
  {
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b0000000, 0b1100100, 0b0000000,
    0b1100100, 0b0000000, 0b1100100, 0b0000000, 0b1100100, 
    0b0000000, 0b1100100, 0b0000000, 0b1100100, 0b0000000,
    0b0000000, 0b0000000, 0b1100100, 0b0000000, 0b0000000,
  },
};


void light_on(int cnt){
  if(cnt == 0) {
      hub_light_on_color(PBIO_COLOR_CYAN);
    }
    if(cnt == 1) {
      hub_light_on_color(PBIO_COLOR_ORANGE);
    }
    else if(cnt == 2) {
      hub_light_on_color(PBIO_COLOR_MAGENTA);
    }
    else if(cnt == 3) {
      hub_light_on_color(PBIO_COLOR_YELLOW);
    }
    else if(cnt == 4) {
      hub_light_on_color(PBIO_COLOR_RED);
    }
    else if(cnt == 5) {
      hub_light_on_color(PBIO_COLOR_GREEN);
    }
    else if(cnt == 6) {
      hub_light_on_color(PBIO_COLOR_BLUE);
      cnt = -1;
    }   
}

void pixel_on(void){
  hub_display_pixel(0, 0, 100);
  hub_display_pixel(0, 1, 100);
  hub_display_pixel(0, 3, 100);
  hub_display_pixel(0, 4, 100);
  hub_display_pixel(1, 0, 100);
  hub_display_pixel(1, 2, 100);
  hub_display_pixel(1, 4, 100);
  hub_display_pixel(2, 1, 100);
  hub_display_pixel(2, 3, 100);
  hub_display_pixel(3, 0, 100);
  hub_display_pixel(3, 2, 100);
  hub_display_pixel(3, 4, 100);
  hub_display_pixel(4, 0, 100);
  hub_display_pixel(4, 1, 100);
  hub_display_pixel(4, 3, 100);
  hub_display_pixel(4, 4, 100);
}

/*
 *  メインタスク
 */
void
main_task(intptr_t exinf)
{
  //pbsys_user_program_prepare(NULL); // pbsys_processをユーザプログラム実行状態に遷移させる．

  hub_display_orientation(PBIO_SIDE_TOP);


  hub_display_off();
  //hub_light_on_color(pbsys_status_light, PBIO_COLOR_BLUE);
  hub_light_on_color(PBIO_COLOR_WHITE);

  hub_display_number(3);
  dly_tsk(500000);
  hub_display_number(2);
  dly_tsk(500000);
  hub_display_number(1);
  dly_tsk(500000);
  int count;
  while(1)
  {
    hub_display_off();
    dly_tsk(500000);
    hub_display_text("HELLO", 900, 500);
    hub_display_text_scroll(" SPIKE-RT", 90);
    hub_display_image(ex);
    dly_tsk(1000000);
    pixel_on();
    dly_tsk(1000000);
    hub_display_off();
    dly_tsk(500000);

    light_on(count);
    count++;
  }
}

