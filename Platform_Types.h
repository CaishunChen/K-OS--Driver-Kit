/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined( __PLATFORM_TYPES_H)
#define __PLATFORM_TYPES_H


#define CPU_TYPE_8          8
#define CPU_TYPE_16         16
#define CPU_TYPE_32         32

#define MSB_FIRST           0
#define LSB_FIRST           1

#define HIGH_BYTE_FIRST     0
#define LOW_BYTE_FIRST      1

#if !defined(NULL)
    #define NULL            0
#endif

#if defined(_MSC_VER)
    #include "mcu/i386/inc/Platform_Types_i386.h"
#else

    #if CPU_FAMILY == CPU12_HC12

       #include "mcu/hc12/inc/Platform_Types_HC12.h"

    #elif CPU_FAMILY == CPU12_S12

       #include "mcu/s12/inc/Platform_Types_S12.h"

    #elif CPU_FAMILY == PIC_F18

       #include "mcu/pic/inc/Platform_Types_PIC.h"

    #else
       #error Unknown CPU family.
    #endif

#endif


#endif /* __PLATFORM_TYPES_H  */
