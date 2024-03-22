/************************************************************************************************************************/
/*File          :       HLCD_config.c                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/

#include "HAL/HLCD/HLCD_interface.h" 
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "HAL/HLCD/HLCD_config.h"

HLCD_strLCDConfigration LCD_PINS[USED_LCD_PIN_NUMS] = {

    [LCD_D0_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN0
    },
    [LCD_D1_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN1
    },
    [LCD_D2_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN2
    },

    [LCD_D3_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN3
    },
    [LCD_D4_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN4
    },
    [LCD_D5_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN5
    },
    [LCD_D6_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN6
    },
    [LCD_D7_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN7
    },
    [LCD_ENABLE_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN8
    },
    [LCD_RW_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN9
    },
    [LCD_RS_PIN] = {
        .LCD_PortNum = GPIO_PORTA,
        .LCD_PinNum  = GPIO_PIN10
    } 
};