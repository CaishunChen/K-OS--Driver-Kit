#if !defined(__HW_CFG_H)
#define __HW_CFG_H

#include "S12_Atd.h"
#include "S12_Can.h"
#include "S12_Ect.h"
#include "S12_Iic.h"
#include "S12_Mebi.h"
#include "S12_Mmc.h"
#include "S12_Pim.h"
#include "S12_Sci.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#define BASE_ADDR_REGISTERS ((uint16)0x0000)

/*
**  ATD
*/
#define BASE_ADDR_ATD0  (BASE_ADDR_REGISTERS+(uint16)0x0080)
#define BASE_ADDR_ATD1  (BASE_ADDR_REGISTERS+(uint16)0x0120)

#define ATD0    &S12Atd_Configuration[0]
#define ATD1    &S12Atd_Configuration[1]

extern const S12Atd_ConfigType S12Atd_Configuration[2];


/*
**  CAN
*/
#define BASE_ADDR_CAN0  (BASE_ADDR_REGISTERS+(uint16)0x0140)
#define BASE_ADDR_CAN1  (BASE_ADDR_REGISTERS+(uint16)0x0180)
#define BASE_ADDR_CAN2  (BASE_ADDR_REGISTERS+(uint16)0x01C0)
#define BASE_ADDR_CAN3  (BASE_ADDR_REGISTERS+(uint16)0x0220)
#define BASE_ADDR_CAN4  (BASE_ADDR_REGISTERS+(uint16)0x0280)

/* extern const S12Can_ConfigType CANBus0,CANBus1,CANBus2,CANBus3,CANBus4; */

extern const S12Can_ConfigType S12Can_Configuration[5];

#define CAN0    &S12Can_Configuration[0]
#define CAN1    &S12Can_Configuration[1]
#define CAN2    &S12Can_Configuration[2]
#define CAN3    &S12Can_Configuration[3]
#define CAN4    &S12Can_Configuration[4]


/*
**  CRG
*/
#define BASE_ADDR_CRG   (BASE_ADDR_REGISTERS+(uint16)0x0034)
extern const S12Crg_ConfigType CRG;


/*
**  ECT
*/
#define BASE_ADDR_ECT   ((uint16)0x0040)
extern const S12Ect_ConfigType ECT;


/*
**  IIC
*/

#define BASE_ADDR_IIC0  ((uint16)0xe0)
extern const S12Iic_ConfigType IIC0;


/*
**  MEBI
*/
#define BASE_ADDR_MEBI   (BASE_ADDR_REGISTERS+(uint16)0x0000)

extern const S12Mebi_ConfigType MEBI;


/*
**  MMC
*/
#define BASE_ADDR_MMC   (BASE_ADDR_REGISTERS+(uint16)0x0000)
extern const S12Mmc_ConfigType MMC;


/*
**  PIM
*/
#define BASE_ADDR_PIM   (BASE_ADDR_REGISTERS+(uint16)0x0240)
extern const S12Pim_ConfigType PIM;


/*
**  SCI
*/
#define BASE_ADDR_SCI0  (BASE_ADDR_REGISTERS+(uint16)0x00c8)
#define BASE_ADDR_SCI1  (BASE_ADDR_REGISTERS+(uint16)0x00d0)

#define SCI0    &S12Sci_Configuration[0]
#define SCI1    &S12Sci_Configuration[1]

#define SCI0_RX_BUF_LEN  ((uint8)32)
#define SCI1_RX_BUF_LEN  ((uint8)32)

extern const S12Sci_ConfigType S12Sci_Configuration[2];

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __HW_CFG_H */

