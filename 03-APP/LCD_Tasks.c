#include "HAL/HLCD/HLCD_interface.h"

#define MS_Periodicity 2
// void LCD_WriteName(void)
// {     
//        static u32 MilliSecond = MS_Periodicity ;
       
//        if(MilliSecond < 10000)
//        {  
//           MilliSecond += MS_Periodicity ;
//           // HLCD_voidLCD_WriteStringAsync("Mina" ,4, HLCD_enuFirstLine, HLCD_enuPosition0);
//           // HLCD_voidLCD_WriteStringAsync("Ayman",5, HLCD_enuSecondLine, HLCD_enuPosition0);
//           HLCD_voidLCD_ClearScreen();
//        }
//        else
//        {
//            /* Do Nothing */
//        }
// }

void LCD_WriteName(void)
{         
   HLCD_voidLCD_WriteStringAsync("Mino",4, HLCD_enuFirstLine, HLCD_enuPosition0);    
}