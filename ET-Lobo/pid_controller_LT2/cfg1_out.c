/* cfg1_out.c */
#define TOPPERS_CFG1_OUT
#include "kernel/kernel_int.h"
#line 1 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#include "target_timer.h"
#line 3 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#ifdef USE_SYSTICK_AS_TIMETICK
#line 5 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#else
#line 6 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#ifdef USE_TIM_AS_HRT
#line 11 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#endif
#line 12 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#endif
#line 10 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
#include "pybricks.h"
#line 1 "./gen/tecsgen.cfg"
#include "tTask_tecsgen.h"
#line 6 "./gen/tecsgen.cfg"
#include "tISR_tecsgen.h"
#line 8 "./gen/tecsgen.cfg"
#include "tInitializeRoutine_tecsgen.h"
#line 10 "./gen/tecsgen.cfg"
#include "tTerminateRoutine_tecsgen.h"
#line 8 "pid_controller_LT2.cfg"
#include "pid_controller_LT2.h"

#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include "target_cfg1_out.h"

const uint32_t TOPPERS_magic_number = 0x12345678;
const uint32_t TOPPERS_sizeof_signed_t = sizeof(signed_t);
const uint32_t TOPPERS_sizeof_intptr_t = sizeof(intptr_t);
const uint32_t TOPPERS_sizeof_char_ptr_t = sizeof(char *);

const unsigned_t TOPPERS_cfg_CHAR_BIT = (unsigned_t)(CHAR_BIT);
const signed_t TOPPERS_cfg_SCHAR_MAX = (signed_t)(SCHAR_MAX);
const signed_t TOPPERS_cfg_SCHAR_MIN = (signed_t)(SCHAR_MIN);
const unsigned_t TOPPERS_cfg_UCHAR_MAX = (unsigned_t)(UCHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MAX = (signed_t)(CHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MIN = (signed_t)(CHAR_MIN);
const signed_t TOPPERS_cfg_SHRT_MAX = (signed_t)(SHRT_MAX);
const signed_t TOPPERS_cfg_SHRT_MIN = (signed_t)(SHRT_MIN);
const unsigned_t TOPPERS_cfg_USHRT_MAX = (unsigned_t)(USHRT_MAX);
const signed_t TOPPERS_cfg_INT_MAX = (signed_t)(INT_MAX);
const signed_t TOPPERS_cfg_INT_MIN = (signed_t)(INT_MIN);
const unsigned_t TOPPERS_cfg_UINT_MAX = (unsigned_t)(UINT_MAX);
const signed_t TOPPERS_cfg_LONG_MAX = (signed_t)(LONG_MAX);
const signed_t TOPPERS_cfg_LONG_MIN = (signed_t)(LONG_MIN);
const unsigned_t TOPPERS_cfg_ULONG_MAX = (unsigned_t)(ULONG_MAX);
#if defined(SIL_ENDIAN_BIG)
const signed_t TOPPERS_cfg_SIL_ENDIAN_BIG = (signed_t)(true);
#endif
#if defined(SIL_ENDIAN_LITTLE)
const signed_t TOPPERS_cfg_SIL_ENDIAN_LITTLE = (signed_t)(true);
#endif
#if defined(USE_EXTERNAL_ID)
const signed_t TOPPERS_cfg_USE_EXTERNAL_ID = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_USE_EXTERNAL_ID = (signed_t)(false);
#endif
const unsigned_t TOPPERS_cfg_TA_NULL = (unsigned_t)(TA_NULL);
const unsigned_t TOPPERS_cfg_TA_ACT = (unsigned_t)(TA_ACT);
const unsigned_t TOPPERS_cfg_TA_NOACTQUE = (unsigned_t)(TA_NOACTQUE);
const unsigned_t TOPPERS_cfg_TA_TPRI = (unsigned_t)(TA_TPRI);
const unsigned_t TOPPERS_cfg_TA_WMUL = (unsigned_t)(TA_WMUL);
const unsigned_t TOPPERS_cfg_TA_CLR = (unsigned_t)(TA_CLR);
const unsigned_t TOPPERS_cfg_TA_CEILING = (unsigned_t)(TA_CEILING);
const unsigned_t TOPPERS_cfg_TA_STA = (unsigned_t)(TA_STA);
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = (unsigned_t)(TA_NONKERNEL);
const unsigned_t TOPPERS_cfg_TA_ENAINT = (unsigned_t)(TA_ENAINT);
const unsigned_t TOPPERS_cfg_TA_EDGE = (unsigned_t)(TA_EDGE);
const unsigned_t TOPPERS_cfg_TNFY_HANDLER = (unsigned_t)(TNFY_HANDLER);
const unsigned_t TOPPERS_cfg_TNFY_SETVAR = (unsigned_t)(TNFY_SETVAR);
const unsigned_t TOPPERS_cfg_TNFY_INCVAR = (unsigned_t)(TNFY_INCVAR);
const unsigned_t TOPPERS_cfg_TNFY_ACTTSK = (unsigned_t)(TNFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TNFY_WUPTSK = (unsigned_t)(TNFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TNFY_SIGSEM = (unsigned_t)(TNFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TNFY_SETFLG = (unsigned_t)(TNFY_SETFLG);
const unsigned_t TOPPERS_cfg_TNFY_SNDDTQ = (unsigned_t)(TNFY_SNDDTQ);
const unsigned_t TOPPERS_cfg_TENFY_SETVAR = (unsigned_t)(TENFY_SETVAR);
const unsigned_t TOPPERS_cfg_TENFY_INCVAR = (unsigned_t)(TENFY_INCVAR);
const unsigned_t TOPPERS_cfg_TENFY_ACTTSK = (unsigned_t)(TENFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TENFY_WUPTSK = (unsigned_t)(TENFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TENFY_SIGSEM = (unsigned_t)(TENFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TENFY_SETFLG = (unsigned_t)(TENFY_SETFLG);
const unsigned_t TOPPERS_cfg_TENFY_SNDDTQ = (unsigned_t)(TENFY_SNDDTQ);
const signed_t TOPPERS_cfg_TMIN_TPRI = (signed_t)(TMIN_TPRI);
const signed_t TOPPERS_cfg_TMAX_TPRI = (signed_t)(TMAX_TPRI);
const signed_t TOPPERS_cfg_TMIN_DPRI = (signed_t)(TMIN_DPRI);
const signed_t TOPPERS_cfg_TMAX_DPRI = (signed_t)(TMAX_DPRI);
const signed_t TOPPERS_cfg_TMIN_ISRPRI = (signed_t)(TMIN_ISRPRI);
const signed_t TOPPERS_cfg_TMAX_ISRPRI = (signed_t)(TMAX_ISRPRI);
const unsigned_t TOPPERS_cfg_TBIT_FLGPTN = (unsigned_t)(TBIT_FLGPTN);
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = (unsigned_t)(TMAX_MAXSEM);
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = (unsigned_t)(TMAX_RELTIM);
const signed_t TOPPERS_cfg_TMIN_INTPRI = (signed_t)(TMIN_INTPRI);
const signed_t TOPPERS_cfg_TMAX_INTPRI = (signed_t)(TMAX_INTPRI);
const signed_t TOPPERS_cfg_TMIN_TSKID = (signed_t)(TMIN_TSKID);
const signed_t TOPPERS_cfg_TMIN_SEMID = (signed_t)(TMIN_SEMID);
const signed_t TOPPERS_cfg_TMIN_FLGID = (signed_t)(TMIN_FLGID);
const signed_t TOPPERS_cfg_TMIN_DTQID = (signed_t)(TMIN_DTQID);
const signed_t TOPPERS_cfg_TMIN_PDQID = (signed_t)(TMIN_PDQID);
const signed_t TOPPERS_cfg_TMIN_MTXID = (signed_t)(TMIN_MTXID);
const signed_t TOPPERS_cfg_TMIN_MPFID = (signed_t)(TMIN_MPFID);
const signed_t TOPPERS_cfg_TMIN_CYCID = (signed_t)(TMIN_CYCID);
const signed_t TOPPERS_cfg_TMIN_ALMID = (signed_t)(TMIN_ALMID);
#if defined(USE_TSKINICTXB)
const signed_t TOPPERS_cfg_USE_TSKINICTXB = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_USE_TSKINICTXB = (signed_t)(false);
#endif
#if defined(OMIT_INITIALIZE_INTERRUPT)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = (signed_t)(false);
#endif
#if defined(USE_INHINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INHINIB_TABLE = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_USE_INHINIB_TABLE = (signed_t)(false);
#endif
#if defined(USE_INTINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INTINIB_TABLE = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_USE_INTINIB_TABLE = (signed_t)(false);
#endif
#if defined(OMIT_INITIALIZE_EXCEPTION)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = (signed_t)(false);
#endif
#if defined(DEFAULT_ISTK)
const uintptr_t TOPPERS_cfg_DEFAULT_ISTK = (uintptr_t)(DEFAULT_ISTK);
#endif
#if defined(TARGET_TSKATR)
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(TARGET_TSKATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INTATR)
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(TARGET_INTATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INHATR)
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(TARGET_INHATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(0);
#endif
#if defined(TARGET_ISRATR)
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(TARGET_ISRATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(0);
#endif
#if defined(TARGET_EXCATR)
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(TARGET_EXCATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(0);
#endif
#if defined(TARGET_MIN_STKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(TARGET_MIN_STKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(1);
#endif
#if defined(TARGET_MIN_ISTKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(TARGET_MIN_ISTKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(1);
#endif
#if defined(CHECK_STKSZ_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(CHECK_STKSZ_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(CHECK_INTPTR_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_NONNULL)
const signed_t TOPPERS_cfg_CHECK_INTPTR_NONNULL = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_CHECK_INTPTR_NONNULL = (signed_t)(false);
#endif
#if defined(CHECK_FUNC_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(CHECK_FUNC_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_FUNC_NONNULL)
const signed_t TOPPERS_cfg_CHECK_FUNC_NONNULL = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_CHECK_FUNC_NONNULL = (signed_t)(false);
#endif
#if defined(CHECK_STACK_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(CHECK_STACK_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_STACK_NONNULL)
const signed_t TOPPERS_cfg_CHECK_STACK_NONNULL = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_CHECK_STACK_NONNULL = (signed_t)(false);
#endif
#if defined(CHECK_MPF_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(CHECK_MPF_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_MPF_NONNULL)
const signed_t TOPPERS_cfg_CHECK_MPF_NONNULL = (signed_t)(true);
#else
const signed_t TOPPERS_cfg_CHECK_MPF_NONNULL = (signed_t)(false);
#endif
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = (unsigned_t)(sizeof(void*));
const unsigned_t TOPPERS_cfg_sizeof_uint_t = (unsigned_t)(sizeof(uint_t));
const unsigned_t TOPPERS_cfg_sizeof_size_t = (unsigned_t)(sizeof(size_t));
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = (unsigned_t)(sizeof(intptr_t));
const unsigned_t TOPPERS_cfg_sizeof_ID = (unsigned_t)(sizeof(ID));
const unsigned_t TOPPERS_cfg_sizeof_FP = (unsigned_t)(sizeof(FP));
const unsigned_t TOPPERS_cfg_sizeof_INTNO = (unsigned_t)(sizeof(INTNO));
const unsigned_t TOPPERS_cfg_sizeof_INHNO = (unsigned_t)(sizeof(INHNO));
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = (unsigned_t)(sizeof(EXCNO));
const unsigned_t TOPPERS_cfg_sizeof_TASK = (unsigned_t)(sizeof(TASK));
const unsigned_t TOPPERS_cfg_sizeof_TMEHDR = (unsigned_t)(sizeof(TMEHDR));
const unsigned_t TOPPERS_cfg_sizeof_ISR = (unsigned_t)(sizeof(ISR));
const unsigned_t TOPPERS_cfg_sizeof_INTHDR = (unsigned_t)(sizeof(INTHDR));
const unsigned_t TOPPERS_cfg_sizeof_EXCHDR = (unsigned_t)(sizeof(EXCHDR));
const unsigned_t TOPPERS_cfg_sizeof_INIRTN = (unsigned_t)(sizeof(INIRTN));
const unsigned_t TOPPERS_cfg_sizeof_TERRTN = (unsigned_t)(sizeof(TERRTN));
const unsigned_t TOPPERS_cfg_sizeof_NFYHDR = (unsigned_t)(sizeof(NFYHDR));
const unsigned_t TOPPERS_cfg_sizeof_TINIB = (unsigned_t)(sizeof(TINIB));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = (unsigned_t)(offsetof(TINIB,tskatr));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = (unsigned_t)(offsetof(TINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = (unsigned_t)(offsetof(TINIB,task));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = (unsigned_t)(offsetof(TINIB,ipriority));
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = (unsigned_t)(offsetof(TINIB,stksz));
#endif
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = (unsigned_t)(offsetof(TINIB,stk));
#endif
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = (unsigned_t)(sizeof(SEMINIB));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = (unsigned_t)(offsetof(SEMINIB,sematr));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = (unsigned_t)(offsetof(SEMINIB,isemcnt));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = (unsigned_t)(offsetof(SEMINIB,maxsem));
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = (unsigned_t)(sizeof(FLGPTN));
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = (unsigned_t)(sizeof(FLGINIB));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = (unsigned_t)(offsetof(FLGINIB,flgatr));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = (unsigned_t)(offsetof(FLGINIB,iflgptn));
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = (unsigned_t)(sizeof(DTQINIB));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = (unsigned_t)(offsetof(DTQINIB,dtqatr));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = (unsigned_t)(offsetof(DTQINIB,dtqcnt));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = (unsigned_t)(offsetof(DTQINIB,p_dtqmb));
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = (unsigned_t)(sizeof(PDQINIB));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = (unsigned_t)(offsetof(PDQINIB,pdqatr));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = (unsigned_t)(offsetof(PDQINIB,pdqcnt));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = (unsigned_t)(offsetof(PDQINIB,maxdpri));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = (unsigned_t)(offsetof(PDQINIB,p_pdqmb));
const unsigned_t TOPPERS_cfg_sizeof_MTXINIB = (unsigned_t)(sizeof(MTXINIB));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_mtxatr = (unsigned_t)(offsetof(MTXINIB,mtxatr));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_ceilpri = (unsigned_t)(offsetof(MTXINIB,ceilpri));
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = (unsigned_t)(sizeof(MPFINIB));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = (unsigned_t)(offsetof(MPFINIB,mpfatr));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = (unsigned_t)(offsetof(MPFINIB,blkcnt));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = (unsigned_t)(offsetof(MPFINIB,blksz));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = (unsigned_t)(offsetof(MPFINIB,mpf));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = (unsigned_t)(offsetof(MPFINIB,p_mpfmb));
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = (unsigned_t)(sizeof(CYCINIB));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = (unsigned_t)(offsetof(CYCINIB,cycatr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = (unsigned_t)(offsetof(CYCINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_nfyhdr = (unsigned_t)(offsetof(CYCINIB,nfyhdr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = (unsigned_t)(offsetof(CYCINIB,cyctim));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = (unsigned_t)(offsetof(CYCINIB,cycphs));
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = (unsigned_t)(sizeof(ALMINIB));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = (unsigned_t)(offsetof(ALMINIB,almatr));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = (unsigned_t)(offsetof(ALMINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_nfyhdr = (unsigned_t)(offsetof(ALMINIB,nfyhdr));
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INHINIB = (unsigned_t)(sizeof(INHINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INHINIB_inhno = (unsigned_t)(offsetof(INHINIB,inhno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INHINIB_inhatr = (unsigned_t)(offsetof(INHINIB,inhatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INHINIB_int_entry = (unsigned_t)(offsetof(INHINIB,int_entry));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INTINIB = (unsigned_t)(sizeof(INTINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INTINIB_intno = (unsigned_t)(offsetof(INTINIB,intno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INTINIB_intatr = (unsigned_t)(offsetof(INTINIB,intatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offsetof_INTINIB_intpri = (unsigned_t)(offsetof(INTINIB,intpri));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_sizeof_EXCINIB = (unsigned_t)(sizeof(EXCINIB));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offsetof_EXCINIB_excno = (unsigned_t)(offsetof(EXCINIB,excno));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offsetof_EXCINIB_excatr = (unsigned_t)(offsetof(EXCINIB,excatr));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offsetof_EXCINIB_exc_entry = (unsigned_t)(offsetof(EXCINIB,exc_entry));
#endif
const unsigned_t TOPPERS_cfg_sizeof_INIRTNB = (unsigned_t)(sizeof(INIRTNB));
const unsigned_t TOPPERS_cfg_offsetof_INIRTNB_inirtn = (unsigned_t)(offsetof(INIRTNB,inirtn));
const unsigned_t TOPPERS_cfg_offsetof_INIRTNB_exinf = (unsigned_t)(offsetof(INIRTNB,exinf));
const unsigned_t TOPPERS_cfg_sizeof_TERRTNB = (unsigned_t)(sizeof(TERRTNB));
const unsigned_t TOPPERS_cfg_offsetof_TERRTNB_terrtn = (unsigned_t)(offsetof(TERRTNB,terrtn));
const unsigned_t TOPPERS_cfg_offsetof_TERRTNB_exinf = (unsigned_t)(offsetof(TERRTNB,exinf));
const unsigned_t TOPPERS_cfg_TA_DIRECT = (unsigned_t)(TA_DIRECT);
const unsigned_t TOPPERS_cfg_TMAX_INTNO = (unsigned_t)(TMAX_INTNO);
const unsigned_t TOPPERS_cfg_TIPM_LOCK = (unsigned_t)(TIPM_LOCK);
const unsigned_t TOPPERS_cfg_TBITW_IPRI = (unsigned_t)(TBITW_IPRI);
const unsigned_t TOPPERS_cfg_sizeof_TCB = (unsigned_t)(sizeof(TCB));
const unsigned_t TOPPERS_cfg_offsetof_TCB_p_tinib = (unsigned_t)(offsetof(TCB,p_tinib));
const unsigned_t TOPPERS_cfg_offsetof_TCB_pc = (unsigned_t)(offsetof(TCB,tskctxb.pc));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_TSKINICTXB_stk_top = (unsigned_t)(offsetof(TINIB,tskinictxb.stk_top));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_TSKINICTXB_stk_bottom = (unsigned_t)(offsetof(TINIB,tskinictxb.stk_bottom));
const unsigned_t TOPPERS_cfg_offsetof_TCB_sp = (unsigned_t)(offsetof(TCB,tskctxb.sp));
const unsigned_t TOPPERS_cfg_offsetof_TCB_stk_top = (unsigned_t)(offsetof(TCB,tskctxb.stk_top));
const unsigned_t TOPPERS_cfg_offsetof_TCB_fpu_flag = (unsigned_t)(offsetof(TCB,tskctxb.fpu_flag));


#line 3 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#ifdef USE_SYSTICK_AS_TIMETICK

#line 7 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
#line 7 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_1 = (unsigned_t)(TA_NULL);

#line 8 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
#line 8 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_2 = (unsigned_t)(TA_NULL);

#line 9 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
#line 9 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_3 = (unsigned_t)(INTNO_TIMER);
#line 9 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_3 = (unsigned_t)(TA_ENAINT|INTATR_TIMER);
#line 9 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_3 = (signed_t)(INTPRI_TIMER);

#line 10 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
#line 10 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_4 = (unsigned_t)(INHNO_TIMER);
#line 10 "../../../asp3/arch/arm_m_gcc/common/core_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_4 = (unsigned_t)(TA_NULL);

#line 5 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#else

#line 6 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#ifdef USE_TIM_AS_HRT

#line 7 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
#line 7 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = (unsigned_t)(TA_NULL);

#line 8 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
#line 8 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_6 = (unsigned_t)(TA_NULL);

#line 9 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
#line 9 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_7 = (unsigned_t)(INTNO_TIMER);
#line 9 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_7 = (unsigned_t)(TA_ENAINT|INTATR_TIMER);
#line 9 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_7 = (signed_t)(INTPRI_TIMER);

#line 10 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
#line 10 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_8 = (unsigned_t)(INHNO_TIMER);
#line 10 "../../../asp3/target/primehub_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_8 = (unsigned_t)(TA_NULL);

#line 11 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#endif

#line 12 "../../../asp3/target/primehub_gcc/target_timer.cfg"
#endif

#line 11 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
#define PYBRICKS_TASK	(<>)
#line 11 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_9 = (unsigned_t)(TA_ACT);
#line 11 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_9 = (signed_t)(PYBRICKS_PRIORITY);
#line 11 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_9 = (unsigned_t)(PYBRICKS_STACK_SIZE);

#line 12 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#define PB_CYCHDR	(<>)
#line 12 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_10 = (unsigned_t)(TA_STA);
#line 12 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_10 = (unsigned_t)(TNFY_HANDLER);
#line 12 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_10 = (unsigned_t)(1000);
#line 12 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_10 = (unsigned_t)(0);

#line 20 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#line 20 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_11 = (unsigned_t)(INTNO_DMA1_STREAM5);
#line 20 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_11 = (unsigned_t)(INTATR_DMA1_STREAM5);
#line 20 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_11 = (signed_t)(INTPRI_DMA1_STREAM5);

#line 21 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#line 21 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_12 = (unsigned_t)(INHNO_DMA1_STREAM5);
#line 21 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_12 = (unsigned_t)(TA_NULL);

#line 23 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#line 23 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_13 = (unsigned_t)(INTNO_DMA1_STREAM6);
#line 23 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_13 = (unsigned_t)(INTATR_DMA1_STREAM6);
#line 23 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_13 = (signed_t)(INTPRI_DMA1_STREAM6);

#line 24 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#line 24 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_14 = (unsigned_t)(INHNO_DMA1_STREAM6);
#line 24 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_14 = (unsigned_t)(TA_NULL);

#line 26 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#line 26 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_15 = (unsigned_t)(INTNO_DMA1_STREAM7);
#line 26 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_15 = (unsigned_t)(INTATR_DMA1_STREAM7);
#line 26 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_15 = (signed_t)(INTPRI_DMA1_STREAM7);

#line 27 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#line 27 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_16 = (unsigned_t)(INHNO_DMA1_STREAM7);
#line 27 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_16 = (unsigned_t)(TA_NULL);

#line 29 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
#line 29 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_17 = (unsigned_t)(INTNO_DMA2_STREAM0);
#line 29 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_17 = (unsigned_t)(INTATR_DMA2_STREAM0);
#line 29 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_17 = (signed_t)(INTPRI_DMA2_STREAM0);

#line 30 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#line 30 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_18 = (unsigned_t)(INHNO_DMA2_STREAM0);
#line 30 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_18 = (unsigned_t)(TA_NULL);

#line 32 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
#line 32 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_19 = (unsigned_t)(INTNO_DMA2_STREAM2);
#line 32 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_19 = (unsigned_t)(INTATR_DMA2_STREAM2);
#line 32 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_19 = (signed_t)(INTPRI_DMA2_STREAM2);

#line 33 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
#line 33 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_20 = (unsigned_t)(INHNO_DMA2_STREAM2);
#line 33 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_20 = (unsigned_t)(TA_NULL);

#line 35 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
#line 35 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_21 = (unsigned_t)(INTNO_DMA2_STREAM3);
#line 35 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_21 = (unsigned_t)(INTATR_DMA2_STREAM3);
#line 35 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_21 = (signed_t)(INTPRI_DMA2_STREAM3);

#line 36 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
#line 36 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_22 = (unsigned_t)(INHNO_DMA2_STREAM3);
#line 36 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_22 = (unsigned_t)(TA_NULL);

#line 38 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
#line 38 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_23 = (unsigned_t)(INTNO_USART2);
#line 38 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_23 = (unsigned_t)(INTATR_USART2);
#line 38 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_23 = (signed_t)(INTPRI_USART2);

#line 39 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
#line 39 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_24 = (unsigned_t)(INHNO_USART2);
#line 39 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_24 = (unsigned_t)(TA_NULL);

#line 41 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
#line 41 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_25 = (unsigned_t)(INTNO_UART4);
#line 41 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_25 = (unsigned_t)(INTATR_UART4);
#line 41 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_25 = (signed_t)(INTPRI_UART4);

#line 42 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
#line 42 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_26 = (unsigned_t)(INHNO_UART4);
#line 42 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_26 = (unsigned_t)(TA_NULL);

#line 44 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
#line 44 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_27 = (unsigned_t)(INTNO_UART5);
#line 44 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_27 = (unsigned_t)(INTATR_UART5);
#line 44 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_27 = (signed_t)(INTPRI_UART5);

#line 45 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#line 45 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_28 = (unsigned_t)(INHNO_UART5);
#line 45 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_28 = (unsigned_t)(TA_NULL);

#line 47 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#line 47 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_29 = (unsigned_t)(INTNO_UART7);
#line 47 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_29 = (unsigned_t)(INTATR_UART7);
#line 47 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_29 = (signed_t)(INTPRI_UART7);

#line 48 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
#line 48 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_30 = (unsigned_t)(INHNO_UART7);
#line 48 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_30 = (unsigned_t)(TA_NULL);

#line 50 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_31 = 31;
#line 50 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_31 = (unsigned_t)(INTNO_UART8);
#line 50 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_31 = (unsigned_t)(INTATR_UART8);
#line 50 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_31 = (signed_t)(INTPRI_UART8);

#line 51 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_32 = 32;
#line 51 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_32 = (unsigned_t)(INHNO_UART8);
#line 51 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_32 = (unsigned_t)(TA_NULL);

#line 58 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_33 = 33;
#line 58 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_33 = (unsigned_t)(INTNO_UART10);
#line 58 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_33 = (unsigned_t)(INTATR_UART10);
#line 58 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_33 = (signed_t)(INTPRI_UART10);

#line 59 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_34 = 34;
#line 59 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_34 = (unsigned_t)(INHNO_UART10);
#line 59 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_34 = (unsigned_t)(TA_NULL);

#line 61 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_35 = 35;
#line 61 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_35 = (unsigned_t)(INTNO_SPI1);
#line 61 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_35 = (unsigned_t)(INTATR_SPI1);
#line 61 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_35 = (signed_t)(INTPRI_SPI1);

#line 62 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_36 = 36;
#line 62 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_36 = (unsigned_t)(INHNO_SPI1);
#line 62 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_36 = (unsigned_t)(TA_NULL);

#line 67 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_37 = 37;
#line 67 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_37 = (unsigned_t)(INTNO_OTG_FS);
#line 67 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_37 = (unsigned_t)(INTATR_OTG_FS);
#line 67 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_37 = (signed_t)(INTPRI_OTG_FS);

#line 68 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_38 = 38;
#line 68 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_38 = (unsigned_t)(INHNO_OTG_FS);
#line 68 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_38 = (unsigned_t)(TA_NULL);

#line 70 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_39 = 39;
#line 70 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_39 = (unsigned_t)(INTNO_I2C2_ER);
#line 70 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_39 = (unsigned_t)(INTATR_I2C2_ER);
#line 70 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_39 = (signed_t)(INTPRI_I2C2_ER);

#line 71 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_40 = 40;
#line 71 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_40 = (unsigned_t)(INHNO_I2C2_ER);
#line 71 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_40 = (unsigned_t)(TA_NULL);

#line 73 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_41 = 41;
#line 73 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_41 = (unsigned_t)(INTNO_I2C2_EV);
#line 73 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_41 = (unsigned_t)(INTATR_I2C2_EV);
#line 73 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_41 = (signed_t)(INTPRI_I2C2_EV);

#line 74 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_42 = 42;
#line 74 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_42 = (unsigned_t)(INHNO_I2C2_EV);
#line 74 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_42 = (unsigned_t)(TA_NULL);

#line 76 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_43 = 43;
#line 76 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_43 = (unsigned_t)(INTNO_EXTI9_5);
#line 76 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_43 = (unsigned_t)(INTATR_EXTI9_5);
#line 76 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_43 = (signed_t)(INTPRI_EXTI9_5);

#line 77 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_static_api_44 = 44;
#line 77 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_44 = (unsigned_t)(INHNO_EXTI9_5);
#line 77 "../../../asp3/target/primehub_gcc/drivers/pybricks.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_44 = (unsigned_t)(TA_NULL);

#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_45 = 45;
#define TSKID_tTask_LogTask_Task	(<>)
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_45 = (unsigned_t)(TA_ACT);
#line 2 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_45 = (signed_t)(3);
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_45 = (unsigned_t)(4096);

#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_46 = 46;
#define SEMID_tSemaphore_SerialPort1_ReceiveSemaphore	(<>)
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_46 = (unsigned_t)(TA_NULL);
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_46 = (unsigned_t)(0);
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_46 = (unsigned_t)(1);

#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_47 = 47;
#define SEMID_tSemaphore_SerialPort1_SendSemaphore	(<>)
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_47 = (unsigned_t)(TA_NULL);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_47 = (unsigned_t)(1);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_47 = (unsigned_t)(1);

#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_48 = 48;
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_48 = (unsigned_t)(USART_INTNO);
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_48 = (unsigned_t)(TA_NULL);
#line 5 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_48 = (signed_t)(-2);

#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_49 = 49;
#define ISRID_tISR_SIOPortTarget1_ISRInstance	(<>)
#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isratr_49 = (unsigned_t)(TA_NULL);
#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_49 = (unsigned_t)(USART_INTNO);
#line 7 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_isrpri_49 = (signed_t)(1);

#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_50 = 50;
#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_50 = (unsigned_t)(TA_NULL);

#line 11 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_51 = 51;
#line 11 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_51 = (unsigned_t)(TA_NULL);

#line 9 "pid_controller_LT2.cfg"
const unsigned_t TOPPERS_cfg_static_api_52 = 52;
#define MAIN_TASK	(<>)
#line 9 "pid_controller_LT2.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_52 = (unsigned_t)(TA_ACT);
#line 9 "pid_controller_LT2.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_52 = (signed_t)(MAIN_PRIORITY);
#line 9 "pid_controller_LT2.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_52 = (unsigned_t)(STACK_SIZE);

