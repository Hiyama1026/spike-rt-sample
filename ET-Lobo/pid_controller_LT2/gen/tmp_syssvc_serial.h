/*  1 "./gen/tmp_C_src.c" */
/*  1 "<built-in>" */
/*  1 "<command-line>" */
/*  1 "./gen/tmp_C_src.c" */
/*  36 "./gen/tmp_C_src.c" */
typedef struct { int dummy; } va_list;

/*  1 "../../../asp3/syssvc/serial.h" 1 */
/*  53 "../../../asp3/syssvc/serial.h" */
/*  1 "../../../asp3/include/kernel.h" 1 */
/*  64 "../../../asp3/include/kernel.h" */
/*  1 "../../../asp3/include/t_stddef.h" 1 */
/*  65 "../../../asp3/include/t_stddef.h" */
/*  1 "../../../asp3/target/primehub_gcc/target_stddef.h" 1 */
/*  63 "../../../asp3/target/primehub_gcc/target_stddef.h" */
/*  1 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 1 3 4 */
/*  34 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 3 4 */

/*  34 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 3 4 */
typedef signed char int8_t;


typedef short int int16_t;


typedef long int int32_t;


typedef long long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef long unsigned int uint32_t;


typedef long long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int int_least32_t;
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef long unsigned int uint_least32_t;
typedef long long unsigned int uint_least64_t;



typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long long unsigned int uint_fast64_t;




typedef int intptr_t;


typedef unsigned int uintptr_t;




typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
/*  64 "../../../asp3/target/primehub_gcc/target_stddef.h" 2 */

/*  1 "../../../asp3/arch/gcc/tool_stddef.h" 1 */
/*  81 "../../../asp3/arch/gcc/tool_stddef.h" */
/*  1 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 1 3 4 */
/*  143 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4 */
typedef int ptrdiff_t;
/*  209 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4 */
typedef unsigned int size_t;
/*  321 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4 */
typedef unsigned int wchar_t;
/*  415 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4 */
typedef struct {
  long long __max_align_ll ;
  long double __max_align_ld ;
/*  426 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4 */
} max_align_t;
/*  82 "../../../asp3/arch/gcc/tool_stddef.h" 2 */
/*  1 "/usr/lib/gcc/arm-none-eabi/9.2.1/include-fixed/limits.h" 1 3 4 */
/*  83 "../../../asp3/arch/gcc/tool_stddef.h" 2 */
/*  66 "../../../asp3/target/primehub_gcc/target_stddef.h" 2 */




/*  1 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" 1 */
/*  59 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" */
/*  1 "../../../asp3/arch/arm_m_gcc/common/core_stddef.h" 1 */
/*  60 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" 2 */
/*  71 "../../../asp3/target/primehub_gcc/target_stddef.h" 2 */
/*  66 "../../../asp3/include/t_stddef.h" 2 */
/*  84 "../../../asp3/include/t_stddef.h" */

/*  84 "../../../asp3/include/t_stddef.h" */
struct TOPPERS_dummy_t { int TOPPERS_dummy_field; };
typedef void (*TOPPERS_fp_t)(struct TOPPERS_dummy_t);






typedef int bool_t;

typedef signed int int_t;
typedef unsigned int uint_t;

typedef signed long long_t;
typedef unsigned long ulong_t;

typedef int_t FN;
typedef int_t ER;
typedef int_t ID;
typedef uint_t ATR;
typedef uint_t STAT;
typedef uint_t MODE;
typedef int_t PRI;
typedef uint32_t TMO;
typedef uint32_t RELTIM;

typedef uint64_t SYSTIM;



typedef uint32_t PRCTIM;

typedef uint32_t HRTCNT;







typedef TOPPERS_fp_t FP;

typedef int_t ER_BOOL;
typedef int_t ER_ID;
typedef int_t ER_UINT;

typedef uintptr_t MB_T;

typedef uint32_t ACPTN;
typedef struct acvct {
 ACPTN acptn1;
 ACPTN acptn2;
 ACPTN acptn3;
 ACPTN acptn4;
} ACVCT;
/*  65 "../../../asp3/include/kernel.h" 2 */




/*  1 "../../../asp3/target/primehub_gcc/target_kernel.h" 1 */
/*  71 "../../../asp3/target/primehub_gcc/target_kernel.h" */
/*  1 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_kernel.h" 1 */
/*  78 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_kernel.h" */
/*  1 "../../../asp3/arch/arm_m_gcc/common/core_kernel.h" 1 */
/*  79 "../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_kernel.h" 2 */
/*  72 "../../../asp3/target/primehub_gcc/target_kernel.h" 2 */
/*  70 "../../../asp3/include/kernel.h" 2 */
/*  103 "../../../asp3/include/kernel.h" */
typedef uint_t FLGPTN;
typedef uint_t INTNO;
typedef uint_t INHNO;
typedef uint_t EXCNO;




typedef void (*TASK)(intptr_t exinf);
typedef void (*TMEHDR)(intptr_t exinf);
typedef void (*ISR)(intptr_t exinf);
typedef void (*INTHDR)(void);
typedef void (*EXCHDR)(void *p_excinf);
typedef void (*INIRTN)(intptr_t exinf);
typedef void (*TERRTN)(intptr_t exinf);







typedef long long STK_T;




typedef intptr_t MPF_T;




typedef struct t_rtsk {
 STAT tskstat;
 PRI tskpri;
 PRI tskbpri;
 STAT tskwait;
 ID wobjid;
 TMO lefttmo;
 uint_t actcnt;
 uint_t wupcnt;
 bool_t raster;
 bool_t dister;
} T_RTSK;

typedef struct t_rsem {
 ID wtskid;
 uint_t semcnt;
} T_RSEM;

typedef struct t_rflg {
 ID wtskid;
 FLGPTN flgptn;
} T_RFLG;

typedef struct t_rdtq {
 ID stskid;
 ID rtskid;
 uint_t sdtqcnt;
} T_RDTQ;

typedef struct t_rpdq {
 ID stskid;

 ID rtskid;

 uint_t spdqcnt;

} T_RPDQ;

typedef struct t_rmtx {
 ID htskid;
 ID wtskid;
} T_RMTX;

typedef struct t_rmpf {
 ID wtskid;

 uint_t fblkcnt;

} T_RMPF;

typedef struct t_rcyc {
 STAT cycstat;
 RELTIM lefttim;
} T_RCYC;

typedef struct t_ralm {
 STAT almstat;
 RELTIM lefttim;
} T_RALM;
/*  202 "../../../asp3/include/kernel.h" */
extern ER act_tsk(ID tskid) ;
extern ER_UINT can_act(ID tskid) ;
extern ER get_tst(ID tskid, STAT *p_tskstat) ;
extern ER chg_pri(ID tskid, PRI tskpri) ;
extern ER get_pri(ID tskid, PRI *p_tskpri) ;
extern ER get_inf(intptr_t *p_exinf) ;
extern ER ref_tsk(ID tskid, T_RTSK *pk_rtsk) ;




extern ER slp_tsk(void) ;
extern ER tslp_tsk(TMO tmout) ;
extern ER wup_tsk(ID tskid) ;
extern ER_UINT can_wup(ID tskid) ;
extern ER rel_wai(ID tskid) ;
extern ER sus_tsk(ID tskid) ;
extern ER rsm_tsk(ID tskid) ;
extern ER dly_tsk(RELTIM dlytim) ;




extern ER ext_tsk(void) ;
extern ER ras_ter(ID tskid) ;
extern ER dis_ter(void) ;
extern ER ena_ter(void) ;
extern bool_t sns_ter(void) ;
extern ER ter_tsk(ID tskid) ;




extern ER sig_sem(ID semid) ;
extern ER wai_sem(ID semid) ;
extern ER pol_sem(ID semid) ;
extern ER twai_sem(ID semid, TMO tmout) ;
extern ER ini_sem(ID semid) ;
extern ER ref_sem(ID semid, T_RSEM *pk_rsem) ;

extern ER set_flg(ID flgid, FLGPTN setptn) ;
extern ER clr_flg(ID flgid, FLGPTN clrptn) ;
extern ER wai_flg(ID flgid, FLGPTN waiptn,
      MODE wfmode, FLGPTN *p_flgptn) ;
extern ER pol_flg(ID flgid, FLGPTN waiptn,
      MODE wfmode, FLGPTN *p_flgptn) ;
extern ER twai_flg(ID flgid, FLGPTN waiptn,
      MODE wfmode, FLGPTN *p_flgptn, TMO tmout) ;
extern ER ini_flg(ID flgid) ;
extern ER ref_flg(ID flgid, T_RFLG *pk_rflg) ;

extern ER snd_dtq(ID dtqid, intptr_t data) ;
extern ER psnd_dtq(ID dtqid, intptr_t data) ;
extern ER tsnd_dtq(ID dtqid, intptr_t data, TMO tmout) ;
extern ER fsnd_dtq(ID dtqid, intptr_t data) ;
extern ER rcv_dtq(ID dtqid, intptr_t *p_data) ;
extern ER prcv_dtq(ID dtqid, intptr_t *p_data) ;
extern ER trcv_dtq(ID dtqid, intptr_t *p_data, TMO tmout) ;
extern ER ini_dtq(ID dtqid) ;
extern ER ref_dtq(ID dtqid, T_RDTQ *pk_rdtq) ;

extern ER snd_pdq(ID pdqid, intptr_t data, PRI datapri) ;
extern ER psnd_pdq(ID pdqid, intptr_t data, PRI datapri) ;
extern ER tsnd_pdq(ID pdqid, intptr_t data,
          PRI datapri, TMO tmout) ;
extern ER rcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) ;
extern ER prcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) ;
extern ER trcv_pdq(ID pdqid, intptr_t *p_data,
          PRI *p_datapri, TMO tmout) ;
extern ER ini_pdq(ID pdqid) ;
extern ER ref_pdq(ID pdqid, T_RPDQ *pk_rpdq) ;

extern ER loc_mtx(ID mtxid) ;
extern ER ploc_mtx(ID mtxid) ;
extern ER tloc_mtx(ID mtxid, TMO tmout) ;
extern ER unl_mtx(ID mtxid) ;
extern ER ini_mtx(ID mtxid) ;
extern ER ref_mtx(ID mtxid, T_RMTX *pk_rmtx) ;




extern ER get_mpf(ID mpfid, void **p_blk) ;
extern ER pget_mpf(ID mpfid, void **p_blk) ;
extern ER tget_mpf(ID mpfid, void **p_blk, TMO tmout) ;
extern ER rel_mpf(ID mpfid, void *blk) ;
extern ER ini_mpf(ID mpfid) ;
extern ER ref_mpf(ID mpfid, T_RMPF *pk_rmpf) ;




extern ER set_tim(SYSTIM systim) ;
extern ER get_tim(SYSTIM *p_systim) ;
extern ER adj_tim(int32_t adjtim) ;
extern HRTCNT fch_hrt(void) ;

extern ER sta_cyc(ID cycid) ;
extern ER stp_cyc(ID cycid) ;
extern ER ref_cyc(ID cycid, T_RCYC *pk_rcyc) ;

extern ER sta_alm(ID almid, RELTIM almtim) ;
extern ER stp_alm(ID almid) ;
extern ER ref_alm(ID almid, T_RALM *pk_ralm) ;




extern ER rot_rdq(PRI tskpri) ;
extern ER get_tid(ID *p_tskid) ;
extern ER get_lod(PRI tskpri, uint_t *p_load) ;
extern ER get_nth(PRI tskpri, uint_t nth, ID *p_tskid) ;
extern ER loc_cpu(void) ;
extern ER unl_cpu(void) ;
extern ER dis_dsp(void) ;
extern ER ena_dsp(void) ;
extern bool_t sns_ctx(void) ;
extern bool_t sns_loc(void) ;
extern bool_t sns_dsp(void) ;
extern bool_t sns_dpn(void) ;
extern bool_t sns_ker(void) ;
extern ER ext_ker(void) ;




extern ER dis_int(INTNO intno) ;
extern ER ena_int(INTNO intno) ;
extern ER clr_int(INTNO intno) ;
extern ER ras_int(INTNO intno) ;
extern ER_BOOL prb_int(INTNO intno) ;
extern ER chg_ipm(PRI intpri) ;
extern ER get_ipm(PRI *p_intpri) ;




extern bool_t xsns_dpn(void *p_excinf) ;
/*  54 "../../../asp3/syssvc/serial.h" 2 */




typedef struct {
 uint_t reacnt;
 uint_t wricnt;
} T_SERIAL_RPOR;




extern ER serial_opn_por(ID portid) ;
extern ER serial_cls_por(ID portid) ;
extern ER_UINT serial_rea_dat(ID portid, char *buf, uint_t len) ;
extern ER_UINT serial_wri_dat(ID portid, const char *buf, uint_t len) ;
extern ER serial_ctl_por(ID portid, uint_t ioctl) ;
extern ER serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor) ;
/*  38 "./gen/tmp_C_src.c" 2 */
