#include <kernel.h>

/*
 *  タスクの優先度の定義
 */

#define MAIN_PRIORITY	    5		/* メインタスクの優先度 */
#define DISPLAY_PRIORITY	4		/* メインタスクの優先度 */

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
 *  Event Bit
 */
// HUB_BUTTON_CENTER, HUB_BUTTON_RIGHT, HUB_BUTTON_LEFT, HUB_BUTTON_BTは押されているボタンのコマンド（ビット値）
#define BUTTONT_EVENT_MASK  HUB_BUTTON_CENTER | HUB_BUTTON_RIGHT | HUB_BUTTON_LEFT | HUB_BUTTON_BT


/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void	main_task(intptr_t exinf);
extern void	but_cyc_handler(intptr_t exinf);
extern void	display_task(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
