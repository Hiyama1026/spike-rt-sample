#include <kernel.h>

/*
 *  タスクの優先度の定義
 */

#define MAIN_PRIORITY	5		/* メインタスクの優先度 */

/*積分の処理周期*/
#define DELTA_T (0.001)

/*カラーセンサーの輝度設定*/
#define WHITE_BRIGHTNESS  (74)
#define BLACK_BRIGHTNESS  (4)

/*ステアリング操舵量の係数*/
#define STEERING_COF      (3)

/*基本走行スピード*/
#define BACE_SPEED        (50)

/*ライントレースエッジ切り替え*/
#define LEFT_EDGE         (-1)
#define RIGHT_EDGE        (1)

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

#endif
