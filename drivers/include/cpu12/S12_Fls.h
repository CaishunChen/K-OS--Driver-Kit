#if !defined(__S12_FLS_H)
#define __S12_FLS_H

#include "S12_Mmc.h"

/*
**  Global Defines.
*/

/*
**
**  todo: Return-Codes!!!
**
*/

/*
**  Command-Codes.
*/
#define S12FLS_ERASE_VERIFY     ((uint8)0x05)
#define S12FLS_WORD_PROGRAM     ((uint8)0x20)
#define S12FLS_SECTOR_ERASE     ((uint8)0x40)
#define S12FLS_MASS_ERASE       ((uint8)0x41)
 
 
/*
**  Module-Error-Codes.
*/
#define S12FLS_ERR_OK           ((uint8)0)
#define S12FLS_ERR_INIT         ((uint8)1)
#define S12FLS_ERR_PVIOL        ((uint8)2)
#define S12FLS_ERR_ACC          ((uint8)3)
#define S12FLS_ERR_ADDR         ((uint8)4)

/*
**  Global Types.
*/
typedef struct tagS12Fls_Geometry {
    /* todo: BinnenMajuskel!? */
    uint8 num_blocks;
    uint8 pages_per_block;
    uint8 sectors_per_page;
    uint16 bytes_per_sector;
    /* check: ben�tigen wir die 'ROW-SIZE' (64Bytes @ 256K,128Bytes @ 512K) ??? */
} S12Fls_Geometry;

/*
**
**  todo: S12Fls_GetGeometry();
**
*/

void S12Fls_Init(void);
void S12Fls_PageSelect(uint8 page);
uint8 S12Fls_DoCmd(uint8 cmd,uint8 page,uint16 addr,uint16 data);
boolean S12Fls_VerifyErase(uint8 block_num);

uint8 S12Fls_SectorErase(uint8 page,uint16 addr);
uint8 S12Fls_MassErase(uint8 block_num);
uint8 S12Fls_PageErase(uint8 page);     /* todo: Implementieren !!! */

uint8 S12Fls_ProgramWord(uint8 page,uint16 addr,uint16 data);
uint8 S12Fls_BurstProgram(uint8 page,uint16 start_addr,const uint16 *data,uint16 len);

#endif /* __S12_FLS_H */
