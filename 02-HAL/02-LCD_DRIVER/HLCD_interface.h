/************************************************************************************************************************/
/*File          :       HLCD_interface.h                                                                                */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                             */
/************************************************************************************************************************/

#ifndef HAL_HLCD_INTERFACE_H_
#define HAL_HLCD_INTERFACE_H_

#include "MCAL/MGPIO/MGPIO_interface.h"

#define HLCD_enu4BIT_MODE            0
#define HLCD_enu8BIT_MODE            1

#define HLCD_enuDISPLAY_OFF          0 
#define HLCD_enuDISPLAY_ON           1

#define HLCD_enuCURSOR_BLINKING_OFF  0
#define HLCD_enuCURSOR_BLINKING_ON   1

#define HLCD_enuCURSOR_OFF           0
#define HLCD_enuCURSOR_ON            1

#define HLCD_enu5X8                  0
#define HLCD_enu5X11                 1

#define HLCD_enuONE_LINE             0
#define HLCD_enuTWO_LINE             1

#define HLCD_SHIFTING_LEFT           0x18
#define HLCD_SHIFTING_RIGHT          0x1C
#define HLCD_CLEAR_DISPLAY           0x01


#define LCD_D0_PIN                  0
#define LCD_D1_PIN                  1
#define LCD_D2_PIN                  2
#define LCD_D3_PIN                  3
#define LCD_D4_PIN                  4
#define LCD_D5_PIN                  5
#define LCD_D6_PIN                  6
#define LCD_D7_PIN                  7
#define LCD_ENABLE_PIN              8
#define LCD_RW_PIN                  9
#define LCD_RS_PIN                  10


typedef enum
{
 HLCD_enuBlockNumber0,
 HLCD_enuBlockNumber1,
 HLCD_enuBlockNumber2,
 HLCD_enuBlockNumber3,
 HLCD_enuBlockNumber4,
 HLCD_enuBlockNumber5,
 HLCD_enuBlockNumber6,
 HLCD_enuBlockNumber7
}HLCD_enuCGRAM_BlockNumber;

typedef enum
{
 HLCD_enuPosition0,
 HLCD_enuPosition1,
 HLCD_enuPosition2,
 HLCD_enuPosition3,
 HLCD_enuPosition4,
 HLCD_enuPosition5,
 HLCD_enuPosition6,
 HLCD_enuPosition7,
 HLCD_enuPosition8,
 HLCD_enuPosition9,
 HLCD_enuPosition10,
 HLCD_enuPosition11,
 HLCD_enuPosition12,
 HLCD_enuPosition13,
 HLCD_enuPosition14,
 HLCD_enuPosition15
}HLCD_enuDDRAM_YPosition;

typedef enum
{
 HLCD_enuFirstLine,
 HLCD_enuSecondLine
}HLCD_enuDDRAM_XPosition;

typedef enum
{
 HLCD_enuOK,
 HLCD_enuBlockNumberError,
 HLCD_enuDDRAM_XPositionError,
 HLCD_enuDDRAM_YPositionError,
 HLCD_enuNull_Pointer,
 HLCD_enuNotReady,
 HLCD_enuNOK
}HLCD_enuErrorStatus_t;

typedef struct
{
   u32   LCD_PortNum;
   u32   LCD_PinNum;
} HLCD_strLCDConfigration;

typedef struct 
{ 
    HLCD_strLCDConfigration DATABIT0 ;
    HLCD_strLCDConfigration DATABIT1 ;
    HLCD_strLCDConfigration DATABIT2 ;
    HLCD_strLCDConfigration DATABIT3 ;
    HLCD_strLCDConfigration DATABIT4 ;
    HLCD_strLCDConfigration DATABIT5 ;
    HLCD_strLCDConfigration DATABIT6 ;
    HLCD_strLCDConfigration DATABIT7 ;
    HLCD_strLCDConfigration RS       ;
    HLCD_strLCDConfigration RW       ;
    HLCD_strLCDConfigration ENABLE   ;
} HLCD_strLCDPinConfigration         ;


/*********************************************Ashync***********************************************************/
void HLCD_vidPinInit(void);
void HLCD_voidLCDInitASYNCH(void);
HLCD_enuErrorStatus_t HLCD_voidLCD_WriteStringAsync(const char* String,u8 Size ,u8 X_Postion,u8 Y_Postion);
HLCD_enuErrorStatus_t HLCD_voidLCD_ClearScreen(void);

#endif
