/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
 *                                      cpu12.gems@googlemail.com>

 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#if !defined(__ISR_H)
#define __ISR_H

#if defined(__cplusplus)
extern "C" {
#endif

                                    /*   *** Compiler ***   */
                                    /*======================*/
#if defined(__CSMC__)               /* Cosmic               */
    #define II_INC_COMP_H             "cosmic/ISR_CSMC.h"
    #define II_INC_PATH_COMP          "cosmic/"
#elif defined(__GNUC__)             /* GNU GCC              */
    #define II_INC_COMP_H             "gcc/ISR_GCC.h"
    #define II_INC_PATH_COMP          "gcc/"
#elif defined(__HIWARE__)           /* Metrowerks/Freescale */
    #define II_INC_COMP_H             "metrowerks/ISR_MW.h"
    #define II_INC_PATH_COMP          "metrowerks"
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */
    #define II_INC_COMP_H             "iar/ISR_IAR.h"
    #define II_INC_PATH_COMP          "iar/"
#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #define II_INC_COMP_H             "imagecraft/ISR_ICC.h"
    #define II_INC_PATH_COMP          "imagecraft/"
#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

typedef  void (*const IISR_IVF)(void);

/*
**  OSEK-ISR2-Wrapper.
*/
#if defined(USE_ORTI)
#define OS_SET_ISRID(id)    (OsCurrentISRID=(id))
#else
#define OS_SET_ISRID(id)
#endif

#define DEFINE_ISR2_VECTOR DECLARE_ISR2_VECTOR

/*
**  ISR2_HANDLER: Handler, that is implemented /w 'ISR()'.
*/
#define DECLARE_ISR2_USER_HANDLER(IsrName) void IsrName##_Handler(void)

#define IMPLEMENT_ISR2_VECTOR(IsrName)              \
        DEFINE_ISR2_VECTOR(IsrName)                 \
                                    {               \
        _BEGIN_BLOCK                                \
            OSEnterISR();                           \
            OS_SET_ISRID(ISRID_##IsrName);          \
            IsrName##_Handler();                    \
            OS_SET_ISRID(ISRID_NONE);               \
            OSLeaveISR();                           \
        _END_BLOCK;                                 \
        }


#define INC_PATH_H II_INC_PATH_COMP ## II_INC_TARGET_H
#define INC_PATH_C II_INC_PATH_COMP II_INC_TARGET_C

#include II_INC_COMP_H

#include "ISR_Cfg.h"

#if !defined(ISR)
#define ISR(IsrName) void IsrName##_Handler(void)
#endif


void ISR_Init(void);


#if defined(__cplusplus)
}
#endif

#endif /* __ISR_H */
