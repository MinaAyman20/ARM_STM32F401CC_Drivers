/************************************************************************************************************************/
/*File          :       HLCD_config.h                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/

#ifndef HAL_HLCD_CONFIG_H_
#define HAL_HLCD_CONFIG_H_


/*
 *  DISPLAY_MODE  Options
 *  1-HLCD_enuDISPLAY_ON 
 *  2-HLCD_enuDISPLAY_OFF
 */

#define HLCD_DISPLAY_MODE               HLCD_enuDISPLAY_ON

/*
 *  CURSOR_MODE  Options
 *  1-HLCD_enuCURSOR_ON,
 *  2-HLCD_enuCURSOR_OFF
 * 
 */
#define HLCD_CURSOR_MODE                HLCD_enuCURSOR_ON

/*
 *  CURSOR_BLINKING_MODE  Options
 *  1-HLCD_enuCURSOR_BLINKING_ON
 *  2-HLCD_enuCURSOR_BLINKING_OFF
 */
#define HLCD_CURSOR_BLINKING_MODE       HLCD_enuCURSOR_BLINKING_ON

/*
 *  BIT_MODE  Options
 *  1-HLCD_enu4BIT_MODE
 *  2-HLCD_enu8BIT_MODE
 */
#define HLCD_BIT_MODE                    HLCD_enu4BIT_MODE

/*
 *  FONT_MODE  Options
 *  1-HLCD_enu5X8
 *  2-HLCD_enu5X11
 */
#define HLCD_FONT_MODE                   HLCD_enu5X8

/*
 *  LINE_MODE  Options
 *  1-HLCD_enuONE_LINE  
 *  2-HLCD_enuTWO_LINE  
 */
#define HLCD_LINES_MODE                  HLCD_enuTWO_LINE  


#define   NUMBER_OF_LCD_PINS_8BIT             8
#define   NUMBER_OF_LCD_PINS_4BIT             4
#define   NUMBER_OF_LCD_COLUMNS              16
#define   USED_LCD_PIN_NUMS                  11




#endif 
