/************************************************************************************************************************/
/*File          :       HLCD_priv.h                                                                                    */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/

#ifndef HAL_HLCD_PRIV_H_
#define HAL_HLCD_PRIV_H_

#include "LIB/STD_TYPES.h"

// Command for function set in 8-bit mode
#define HLCD_FUNCTION_SET_8BIT_CMD      ((u32) ((0 << 7) | (0 << 6) | (1 << 5) | (HLCD_BIT_MODE << 4) | \
                                              (HLCD_LINES_MODE  << 3) | (HLCD_FONT_MODE << 2) | \
                                              (0 << 1) | (0 << 0)))

// Command for display on/off control in 8-bit mode
#define HLCD_DISPLAY_ON_OFF_8BIT_CMD    ((u32) ((0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | \
                                              (1  << 3) | ( HLCD_DISPLAY_MODE << 2) | \
                                              (HLCD_CURSOR_MODE << 1) | (HLCD_CURSOR_BLINKING_MODE << 0)))

// Command for clearing display in 8-bit mode
#define HLCD_CLEAR_DISPLAY_8BIT_CMD     ((u32) 0b00000001)

// Command for setting start address in 8-bit mode
#define HLCD_STARTADDRESS_8BIT_CMD      ((u32) 0b00000010)

// Command for setting entry mode in 8-bit mode
#define HLCD_ENTRY_MODE_8BIT_CMD        ((u32) 0b00000110)


// Command for function set in 4-bit mode
#define HLCD_FUNCTION_SET_4BIT_CMD      ((u32) ((0 << 7) | (0<< 6) | (1 << 5) | (HLCD_BIT_MODE<< 4) | \
                                              (HLCD_LINES_MODE<< 3) | (HLCD_FONT_MODE<< 2) | (0 << 1) | ( 0<< 0)))

// Command for display on/off control in 4-bit mode
#define HLCD_DISPLAY_ON_OFF_4BIT_CMD    ((u32) ((0 << 7) | (0 << 6) | (0 << 5) | (0<< 4) | \
                                              (1  << 3) | ( HLCD_DISPLAY_MODE  << 2) | (HLCD_CURSOR_MODE  << 1) | (HLCD_CURSOR_BLINKING_MODE  << 0)))

// Command for clearing display in 4-bit mode
#define HLCD_CLEAR_DISPLAY_4BIT_CMD     ((u32) 0b00000001)

// Command for setting start address in 4-bit mode
#define HLCD_STARTADDRESS_4BIT_CMD      ((u32) 0b00000010)

// Command for setting entry mode in 4-bit mode
#define HLCD_ENTRY_MODE_4BIT_CMD        ((u32) 0b00000110)


// Fixed value for function set in 4-bit mode
#define HLCD_Fixed1_FunctionSet_4BIT_CMD       (u32) 0x02

#define LCD_RESETVALUE   0
#define LCD_ENABLEVALUE  1
#define LOW_NIBBLE(byte)   ((byte) & 0x0F)   // Extracts the low nibble (4 least significant bits) from a byte
#define HIGH_NIBBLE(byte)  ((byte) & 0xF0)  // Extracts the high nibble (4 most significant bits) from a byte


#endif
