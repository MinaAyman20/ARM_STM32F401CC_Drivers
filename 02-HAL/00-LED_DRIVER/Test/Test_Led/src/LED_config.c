#include "GPIO.h"
#include "LED.h"
#include "LED_config.h"



const Led_CFG_t LEDS[_Led_Num] =
{
    [Led_Start]=
    {
        .Led_Port=GPIO_PORTA,
        .Led_Pin=GPIO_PIN0,
        .Led_Connection=LED_CONN_FORWARD,
        .Led_InitStatus=LED_STATUS_OFF
    }
};