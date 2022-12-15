/*  1 "./gen/tmp_C_src.c" */
/*  1 "<built-in>" */
/*  1 "<command-line>" */
/*  1 "./gen/tmp_C_src.c" */
/*  36 "./gen/tmp_C_src.c" */
typedef struct { int dummy; } va_list;

/*  1 "../../../../asp3/syssvc/syslog.h" 1 */
/*  53 "../../../../asp3/syssvc/syslog.h" */
/*  1 "../../../../asp3/include/t_stddef.h" 1 */
/*  65 "../../../../asp3/include/t_stddef.h" */
/*  1 "../../../../asp3/target/primehub_gcc/target_stddef.h" 1 */
/*  63 "../../../../asp3/target/primehub_gcc/target_stddef.h" */
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
/*  64 "../../../../asp3/target/primehub_gcc/target_stddef.h" 2 */

/*  1 "../../../../asp3/arch/gcc/tool_stddef.h" 1 */
/*  81 "../../../../asp3/arch/gcc/tool_stddef.h" */
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
/*  82 "../../../../asp3/arch/gcc/tool_stddef.h" 2 */
/*  1 "/usr/lib/gcc/arm-none-eabi/9.2.1/include-fixed/limits.h" 1 3 4 */
/*  83 "../../../../asp3/arch/gcc/tool_stddef.h" 2 */
/*  66 "../../../../asp3/target/primehub_gcc/target_stddef.h" 2 */




/*  1 "../../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" 1 */
/*  59 "../../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" */
/*  1 "../../../../asp3/arch/arm_m_gcc/common/core_stddef.h" 1 */
/*  60 "../../../../asp3/arch/arm_m_gcc/stm32f4xx_stm32cube/chip_stddef.h" 2 */
/*  71 "../../../../asp3/target/primehub_gcc/target_stddef.h" 2 */
/*  66 "../../../../asp3/include/t_stddef.h" 2 */
/*  84 "../../../../asp3/include/t_stddef.h" */

/*  84 "../../../../asp3/include/t_stddef.h" */
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
/*  54 "../../../../asp3/syssvc/syslog.h" 2 */
/*  1 "../../../../asp3/include/t_syslog.h" 1 */
/*  71 "../../../../asp3/include/t_syslog.h" */
/*  1 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 1 3 4 */
/*  40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4 */

/*  40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4 */
typedef 
/*  40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" */
       va_list 
/*  40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4 */
                         __gnuc_va_list;
/*  99 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4 */
typedef __gnuc_va_list va_list;
/*  72 "../../../../asp3/include/t_syslog.h" 2 */
/*  122 "../../../../asp3/include/t_syslog.h" */

/*  122 "../../../../asp3/include/t_syslog.h" */
typedef struct {
 uint_t logtype;
 HRTCNT logtim;
 intptr_t logpar[6];
} SYSLOG;







extern ER syslog_wri_log(uint_t prio, const SYSLOG *p_syslog) ;
/*  144 "../../../../asp3/include/t_syslog.h" */
static inline void
t_syslog_0(uint_t prio, uint_t type)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_1(uint_t prio, uint_t type, intptr_t arg1)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_2(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_3(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2, intptr_t arg3)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_4(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
           intptr_t arg3, intptr_t arg4)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_5(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
        intptr_t arg3, intptr_t arg4, intptr_t arg5)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 logbuf.logpar[4] = arg5;
 ((void) syslog_wri_log(prio, &logbuf));
}

static inline void
t_syslog_6(uint_t prio, uint_t type, intptr_t arg1, intptr_t arg2,
     intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6)
{
 SYSLOG logbuf;

 logbuf.logtype = type;
 logbuf.logpar[0] = arg1;
 logbuf.logpar[1] = arg2;
 logbuf.logpar[2] = arg3;
 logbuf.logpar[3] = arg4;
 logbuf.logpar[4] = arg5;
 logbuf.logpar[5] = arg6;
 ((void) syslog_wri_log(prio, &logbuf));
}




extern void tt_syslog(SYSLOG *p_logbuf, const char *format, va_list ap);

static inline void
syslog(uint_t prio, const char *format, ...)
{
 va_list ap;
 SYSLOG logbuf;

 
/*  242 "../../../../asp3/include/t_syslog.h" 3 4 */
__builtin_va_start(
/*  242 "../../../../asp3/include/t_syslog.h" */
ap
/*  242 "../../../../asp3/include/t_syslog.h" 3 4 */
,
/*  242 "../../../../asp3/include/t_syslog.h" */
format
/*  242 "../../../../asp3/include/t_syslog.h" 3 4 */
)
/*  242 "../../../../asp3/include/t_syslog.h" */
                    ;
 tt_syslog(&logbuf, format, ap);
 
/*  244 "../../../../asp3/include/t_syslog.h" 3 4 */
__builtin_va_end(
/*  244 "../../../../asp3/include/t_syslog.h" */
ap
/*  244 "../../../../asp3/include/t_syslog.h" 3 4 */
)
/*  244 "../../../../asp3/include/t_syslog.h" */
          ;
 ((void) syslog_wri_log(prio, &logbuf));
}




extern void tt_perror(SYSLOG *p_logbuf, const char *file, int_t line,
            const char *expr, ER ercd);

static inline void
t_perror(uint_t prio, const char *file, int_t line, const char *expr, ER ercd)
{
 SYSLOG logbuf;

 tt_perror(&logbuf, file, line, expr, ercd);
 ((void) syslog_wri_log(prio, &logbuf));
}
/*  55 "../../../../asp3/syssvc/syslog.h" 2 */
/*  65 "../../../../asp3/syssvc/syslog.h" */
typedef struct t_syslog_rlog {
 uint_t count;
 uint_t lost;
 uint_t logmask;
 uint_t lowmask;
} T_SYSLOG_RLOG;




extern ER syslog_wri_log(uint_t prio, const SYSLOG *p_syslog) ;
extern ER_UINT syslog_rea_log(SYSLOG *p_syslog) ;
extern ER syslog_msk_log(uint_t logmask, uint_t lowmask) ;
extern ER syslog_ref_log(T_SYSLOG_RLOG *pk_rlog) ;
extern ER syslog_fls_log(void) ;
/*  38 "./gen/tmp_C_src.c" 2 */
