#if !defined(__STD_MACROS_H)
#define __STD_MACROS_H

#if defined(__IAR_SYSTEMS_ICC__)
#pragma diag_suppress=Pe236
#endif

#if defined(__HIWARE__)
#pragma MESSAGE DISABLE C4000
#pragma MESSAGE DISABLE C4001
#endif

/* check for C99-Compiler */
#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__>=199901L
        #define _C99_COMPILER
    #endif
#endif


/* check for C1x-Compiler */
#if 0
#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__>=??????L
        #define _C1x_COMPILER
    #endif
#endif
#endif

#if defined(_C99_COMPILER) || defined(_C1x_COMPILER)
#define _MODERN_C
#else
#define _LEGACY_C
#endif


/* check for C++-Compiler */
#if defined(__cplusplus)
    #define _CPP_COMPILER
#endif

/* Check for Freestanding-Environment */
#if !defined(__STDC_HOSTED__)
    #define _FREESTANDING
#endif

#if defined(_C99_COMPILER)
    #define INLINE inline
    #define RESTRICT restrict
#elif defined(_CPP_COMPILER)
    #define INLINE inline
    #define RESTRICT
#else
    #define INLINE
    #define RESTRICT
#endif

#if !defined(PROGRAM_STARTUP)
#define PROGRAM_STARTUP int main    /* ISO-C only requires 'int main()'-signatures for hosted environments !!! */
#endif /* PROGRAM_STARTUP */

#define UNREFERENCED_PARAMETER(p)   ((p)=(p))

#define MIN(a,b)            (((a)>(b)) ? (b) : (a))
#define MAX(a,b)            (((a)>(b)) ? (a) : (b))

#define BETWEEN(x,min,max)  (((x) >= (min)) && ((x) <= (max)))

#define ABS(i)              (((i)<0) ? ((i) * -1) : ((i)))

#define SWAP_VALUES(lhs,rhs)    \
    _BEGIN_BLOCK                \
        (lhs)^=(rhs);           \
        (rhs)^=(lhs);           \
        (lhs)^=(rhs);           \
    _END_BLOCK                  \

#define LOBYTE(w)           ((uint8)((uint16)((uint16)(w) & 0x00ffU)))
#define HIBYTE(w)           ((uint8)((uint16)(((uint16)(w )>> 8) & 0x00ffU)))

#define LOWORD(dw)          ((uint16)((uint32)((uint32)(dw) & 0xffffU)))
#define HIWORD(dw)          ((uint16)((uint32)(((uint32)(dw) >> 16) & 0xffffU)))

#define MAKEWORD(h,l)       (((h) & ((uint8)0xff)) << 8 | ((l) & ((uint8)0xff)))
#define MAKEDWORD(h,l)      (((h) & ((uint16)0xffffu)) << 16 | ((l) & ((uint16)0xffffu)))

#define INVERT_NIBBLE(b)    ((uint8)((~(b)) & ((uint8)0x0f)))

#define SIZEOF_ARRAY(arr)   (sizeof((arr)) / sizeof((arr[0])))
#define BEYOND_ARRAY(arr)   ((arr) + SIZE_OF_ARRAY((arr)))  /* todo: '_Bool'scher Ausdruck!!! */

#define FOREVER             while(TRUE)

#define NOT_ADDRESSABLE register

#define WAIT_FOR(cond)  \
    while (!(cond))     \
        {}

/*
**
**    todo: 'ASSERT_<object>_IS_ALLOWED(obj_id)' - das 'APPMODE' Objekt bekommt DISALLOW_<object>,
**          DISALLOW_TASK,DISALLOW_EVENT etc., mit denen man bestimmte Objekte f�r bestimmte
**          Application-Modes verbieten kann.
**
*/

/*
**
**      check: Zwischen DEBUG- und RELEASE- Assertions ('D_ASSERT','R_ASSERT') unterscheiden ???
*/

/* 
    todo: Funktion bzw. Benutzerdefinierter Handler!!!
    Au�erdem als Konfigurations-Option ErrorHook(), falls
    installiert, mit einer speziellen Konstante
    (E_OS_SYS_ASSERTION_FAILED) aufrufen.

    - DONT_USE_ASSERT.
    - SYS_DEFINED_ASSERT.
    - USER_DEFINED_ASSERT.
*/
#if !defined(NDEBUG)
#define ASSERT(cond)            \
   _BEGIN_BLOCK                 \
        if (!(cond)) {          \
            CPU_BREAKPOINT();   \
        }                       \
   _END_BLOCK

#else
#define ASSERT(cond)
#endif  /* NDEBUG */

/* Static  (compile time) Assertion. */
#if defined(_C1x_COMPILER)
#define STATIC_ASSERT(cond,msg) _Static_assert((cond),(msg))
#else
#define STATIC_ASSERT(cond,msg)                 \
struct  GLUE2(__NEVER_USED_BY_ISO_C_,__LINE__){ \
    int x[(cond) ? 1 : -1];                     \
} 
#endif

#define RETURN_VALUE_IF_FALSE(expr,value)   \
    _BEGIN_BLOCK                            \
        if (!(expr)) {                      \
            return (value);                 \
        }                                   \
    _END_BLOCK                              \


#define _BEGIN_BLOCK    do {
#define _END_BLOCK      } while (0)

typedef void (*VoidFunctionType)(void);

#define TO_STRING_2(s)  #s
#define TO_STRING(s)    TO_STRING_2(s)

#define GLUE2_2(a,b)    a ## b
#define GLUE2(a,b)      GLUE2_2(a,b)

#define GLUE3_2(a,b,c)  a ## b ## c
#define GLUE3(a,b,c)    GLUE3_2(a,b,c)

#define BREF(b,o)       (*(((uint8*)(b)+(o))))
#define BPTR(b,o)       ((((uint8*)(b)+(o))))

#define WREF(w,o)       (*((uint16*) ((uint8*)(w)+(o))))
#define WPTR(w,o)       (((uint16*) ((uint8*)(w)+(o))))

#define LREF(l,o)       (*((uint32*) ((uint8*)(l)+(o))))
#define LPTR(l,o)       (((uint32*) ((uint8*)(l)+(o))))

#define FREF(f,o)       (*((float64*) ((uint8*)(f)+(o))))
#define FPTR(f,o)       (((float64*) ((uint8*)(f)+(o))))

#define BYTE_REG(base,offs)     *(volatile uint8*)BPTR((base),(offs))
#define WORD_REG(base,offs)     *(volatile uint16*)WPTR((base),(offs))


#define BIT0    ((uint16)0x01)
#define BIT1    ((uint16)0x02)
#define BIT2    ((uint16)0x04)
#define BIT3    ((uint16)0x08)
#define BIT4    ((uint16)0x10)
#define BIT5    ((uint16)0x20)
#define BIT6    ((uint16)0x40)
#define BIT7    ((uint16)0x80)
#define BIT8    ((uint16)0x0100)
#define BIT9    ((uint16)0x0200)
#define BIT10   ((uint16)0x0400)
#define BIT11   ((uint16)0x0800)
#define BIT12   ((uint16)0x1000)
#define BIT13   ((uint16)0x2000)
#define BIT14   ((uint16)0x4000)
#define BIT15   ((uint16)0x8000)


#define OFFSET_OF(structure, member) ((SizeType) &(((structure)*)0)->(member))
#define SIZE_OF(s,m) ((SizeType) sizeof(((s *)0)->m))

#define HW_GET_CONFIGURATION(conf,dest,id,err_ret)                  \
    _BEGIN_BLOCK                                                    \
        RETURN_VALUE_IF_FALSE((id)<SIZEOF_ARRAY((conf)),(err_ret)); \
        (dest)=&(conf)[(id)];                                       \
    _END_BLOCK                                                      \

#endif /* __STD_MACROS_H */
