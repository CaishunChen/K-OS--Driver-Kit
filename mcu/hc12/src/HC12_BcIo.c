/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
 * s. FLOSS-EXCEPTION.txt
 */

#include "HC12_BcIo.h"
#include "Hw_Cfg.h"

#if HC12BCIO_DEV_ERROR_DETECT == STD_ON
#define HC12BCIO_ASSERT_VALID_PORT(port) \
_BEGIN_BLOCK \
if (port > HC12BCIO_PORT_MAX) { \
/*            ErrorHandler(...); */ \
    return; \
} \
_END_BLOCK
#else
#define HC12BCIO_ASSERT_VALID_PORT(port)
#endif /* HC12BCIO_DEV_ERROR_DETECT */

#if HC12BCIO_DEV_ERROR_DETECT == STD_ON
#define HC12BCIO_ASSERT_VALID_CHANNEL(channel) \
_BEGIN_BLOCK \
if (channel > HC12BCIO_CHANNEL_MAX) { \
    /*            ErrorHandler(...); */ \
    return; \
} \
_END_BLOCK
#else
#define HC12BCIO_ASSERT_VALID_CHANNEL(channel)
#endif  /* HC12BCIO_DEV_ERROR_DETECT */

/*
** Global Variables.
*/

/*
** Local Constants.
*/
static const uint8 HC12BcIo_Ports[] = {
    PORTA,
    PORTB,
    PORTE
};

static const uint8 HC12BcIo_PortDDRs[] = {
    DDRA,
    DDRB,
    DDRE
};

/*
**	Global Functions.
*/
void HC12BcIo_Init(void)
{
    HC12BCIO_REG8(PORTA)   = BCIO.PortA;
    HC12BCIO_REG8(DDRA)    = BCIO.DdrA;

    HC12BCIO_REG8(PORTB)   = BCIO.PortB;
    HC12BCIO_REG8(DDRB)    = BCIO.DdrB;

    HC12BCIO_REG8(PORTE)   = BCIO.PortE;
    HC12BCIO_REG8(DDRE)    = BCIO.DdrE;

    HC12BCIO_REG8(PUCR)    = BCIO.Pucr;
    HC12BCIO_REG8(RDRIV)   = BCIO.Rdriv;
}


HC12BcIo_ModeType HC12BcIo_GetMode(void)
{
    return (HC12BcIo_ModeType)((HC12BCIO_REG8(MODE) & (uint8)0xe0) >> 5);
}


boolean HC12BcIo_SpecialMode(void)
{
    uint8 mode = (HC12BCIO_REG8(MODE) & (uint8)0xe0) >> 5;

    return !(((mode & ((uint8)0x04)) == ((uint8)0x04)) && !((mode & ((uint8)0x06)) == ((uint8)0x06)));
}


/*
**  Implementation of common functions.
*/

IMPLEMENT_IO_WRITE_PORT(HC12BCIO, HC12BcIo)
IMPLEMENT_IO_READ_PORT(HC12BCIO, HC12BcIo)

IMPLEMENT_IO_WRITE_CHANNEL(HC12BCIO, HC12BcIo)
IMPLEMENT_IO_READ_CHANNEL(HC12BCIO, HC12BcIo)

IMPLEMENT_IO_WRITE_CHANNEL_GROUP(HC12BCIO, HC12BcIo)
IMPLEMENT_IO_READ_CHANNEL_GROUP(HC12BCIO, HC12BcIo)

IMPLEMENT_IO_SET_PIN_DIRECTION(HC12BCIO, HC12BcIo)

