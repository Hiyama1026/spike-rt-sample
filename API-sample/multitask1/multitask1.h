#include <kernel.h>

/*
 *  タスクの優先度の定義
 */

#define MAIN_PRIORITY	5		/* メインタスクの優先度 */
#define MOTOR_HIGH_PRIORITY	5		/* モータタスク優先度 高 */
#define MOTOR_MID_PRIORITY	6		/* モータタスク優先度 中 */
#define MOTOR_LOW_PRIORITY	7		/* モータタスク優先度 低 */

/*
 *  ターゲットに依存する可能性のある定数の定義
 */

#ifndef TASK_PORTID
#define	TASK_PORTID		1			/* 文字入力するシリアルポートID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define	STACK_SIZE		4096		/* タスクのスタックサイズ */
#endif /* STACK_SIZE */

/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void	main_task(intptr_t exinf);
extern void	high_pri_task(intptr_t exinf);
extern void	mid_pri_task(intptr_t exinf);
extern void	low_pri_task(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */

static uint8_t img_smile[1][25] = {
  {
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,
    0b0000000, 0b1100100, 0b0000000, 0b1100100, 0b0000000,
    0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 
    0b1100100, 0b0000000, 0b0000000, 0b0000000, 0b1100100,
    0b0000000, 0b1100100, 0b1100100, 0b1100100, 0b0000000,
  },
};