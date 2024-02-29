#ifndef HAL_LED_HAL_interface_H_
#define HAL_LED_HAL_interface_H_

#include "STD_TYPES.h"
#include "LED_config.h" 

// Define LED status constants
#define LED_STATUS_ON   1
#define LED_STATUS_OFF  0

// Define LED connection types
#define LED_CONN_FORWARD   0
#define LED_CONN_REVERSE   1

// Define LED connection types
#define LED_OK    0
#define LED_NOK   1

// LED configuration structure
typedef struct
{
    u32 Led_Port;           // GPIO port of the LED
    u32 Led_Pin;            // GPIO pin of the LED
    u32 Led_Connection;     // Connection type of the LED (forward or reverse)
    u32 Led_InitStatus;     // Initial status of the LED
} Led_CFG_t;

// Function prototypes


/*
 * Function: HLED_vLedInit
 * ------------------------
 * Initializes all the LEDs configured in the LEDS array.
 * Configures each LED pin as output with push-pull configuration and high-speed setting.
 * This function sets the initial status of each LED according to the configuration.
 * 
 * Parameters: None
 * 
 * Returns: None
 */
void HLED_vLedInit(void);       

/*
 * Function: HLED_vSetLedStatus
 * -----------------------------
 * Sets the status of the specified LED.
 * 
 * Parameters:
 *     LED: The index of the LED in the LEDS array.
 *     Status: The desired status of the LED (LED_STATUS_ON or LED_STATUS_OFF).
 * 
 * Returns: None
 */
void HLED_vSetLedStatus(u32 LED, u8 Status); 

#endif