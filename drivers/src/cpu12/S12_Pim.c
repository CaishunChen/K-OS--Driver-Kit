
#include "S12_Pim.h"
#include "Hw_Cfg.h"

/*
    � Port A, B, E, and K related to the core logic and multiplexed bus interface
    � Port T connected to the timer module
    � The serial port S associated with 2 SCI and 1 SPI modules
    � Port M associated with 4 CAN and 1 BDLC module
    � Port P connected to the PWM and 2 SPI modules, which also can be used as an external interrupt source
    � The standard I/O ports H and J associated with the fifth CAN module and the IIC interface. These ports 
      can also be used as external interrupt sources.
*/

S12Pim_StatusType S12Pim_Init(void)
{
    S12PIM_REG8(MODRR)=PIM.Modrr;

    /* PortT */
    S12PIM_REG8(RDRT)=PIM.RdrT;
    S12PIM_REG8(PERT)=PIM.PerT;
    S12PIM_REG8(PPST)=PIM.PpsT;
    S12PIM_REG8(PTT)=PIM.PtT;
    S12PIM_REG8(DDRT)=PIM.DdrT;

    /* PortS */
    S12PIM_REG8(RDRS)=PIM.RdrS;
    S12PIM_REG8(PERS)=PIM.PerS;
    S12PIM_REG8(PPSS)=PIM.PpsS;
    S12PIM_REG8(WOMS)=PIM.WomsS;
    S12PIM_REG8(PTS)=PIM.PtS; 
    S12PIM_REG8(DDRS)=PIM.DdrS;

    /* PortM */
    S12PIM_REG8(RDRM)=PIM.RdrM;
    S12PIM_REG8(PERM)=PIM.PerM;
    S12PIM_REG8(PPSM)=PIM.PpsM;
    S12PIM_REG8(WOMM)=PIM.WomM;
    S12PIM_REG8(PTM)=PIM.PtM;
    S12PIM_REG8(DDRM)=PIM.DdrM;

    /* PortP */
    S12PIM_REG8(RDRP)=PIM.RdrP;
    S12PIM_REG8(PERP)=PIM.PerP;
    S12PIM_REG8(PPSP)=PIM.PpsP;
    S12PIM_REG8(PIEP)=PIM.PieP;
    S12PIM_REG8(PTP)=PIM.PtP;
    S12PIM_REG8(DDRP)=PIM.DdrP;

    /* PortH */
    S12PIM_REG8(RDRH)=PIM.RdrH;
    S12PIM_REG8(PERH)=PIM.PerH;
    S12PIM_REG8(PPSH)=PIM.PpsH;
    S12PIM_REG8(PIEH)=PIM.PieH;
    S12PIM_REG8(PTH)=PIM.PtH;
    S12PIM_REG8(DDRH)=PIM.DdrH;

    /* PortJ */
    S12PIM_REG8(RDRJ)=PIM.RdrJ;
    S12PIM_REG8(PERJ)=PIM.PerJ;
    S12PIM_REG8(PPSJ)=PIM.PpsJ;
    S12PIM_REG8(PIEJ)=PIM.PieJ;
    S12PIM_REG8(PTJ)=PIM.PtJ;
    S12PIM_REG8(DDRJ)=PIM.DdrJ;

    return S12PIM_OK;
}
