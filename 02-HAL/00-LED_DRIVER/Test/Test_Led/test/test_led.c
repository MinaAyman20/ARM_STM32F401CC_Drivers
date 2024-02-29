#ifdef TEST

#include "unity.h"

#include "LED.h"
#include "mock_GPIO.h"
Led_CFG_t LEDS[_Led_Num];
void setUp(void)
{
}

void tearDown(void)
{
}

void test_HLED_vLedInit_ValidParameters(void)
 {
    MGPIO_PIN_config_t testled;
    testled.GPIOMode = GPIO_OUTPUT;
    testled.GPIO_OUTPUTTYPE = GPIO_PUSHPULL;
    testled.GPIOSpeed = GPIO_HIGH_SPEED;
    testled.GPIO_INPUTTYPE = GPIO_NO_PULLUPPULLDOWN;
    int i = 0;
    
    for(i = 0; i<_Led_Num;i++)
    {
        testled.GPIOPort = LEDS[i].Led_Port;
        testled.GPIOPin = LEDS[i].Led_Pin;
        MGPIO_enuSetPinConfig_ExpectAndReturn(&testled,MGPIO_enuOK);
        MGPIO_enuSetPinValue_ExpectAndReturn(LEDS[i].Led_Port,LEDS[i].Led_Pin,LEDS[i].Led_InitStatus,MGPIO_enuOK);
    }  
    // Call the function to be tested
    HLED_vLedInit(); // Assuming HLED_vLedInit() is the function to be tested
    mock_GPIO_Verify();
 }

void test_HLED_vSetLedStatus_ValidParamters(void) {
    // Define expected parameters for the GPIO function call
    u32 expected_port = GPIO_PORTA;
    u32 expected_pin = GPIO_PIN0;
    u8 expected_status = GPIO_HIGH;
    u8 expected_connection = LED_CONN_FORWARD;
    u8 expected_calculated_value = expected_connection ^ expected_status;

    // Expectation: MGPIO_enuSetPinValue should be called with the expected parameters
    MGPIO_enuSetPinValue_ExpectAndReturn(expected_port, expected_pin, expected_calculated_value, MGPIO_enuOK);

    // Call the function under test
    HLED_vSetLedStatus(0, LED_STATUS_ON);
}

void test_LED_TurnOn(void) {
    // Expectation: GPIO function should be called with the correct parameters to turn the LED on
    MGPIO_enuSetPinValue_ExpectAndReturn(LEDS[0].Led_Port,LEDS[0].Led_Pin, LED_STATUS_ON, MGPIO_enuOK);

    // Call the function to turn the LED on
    HLED_vSetLedStatus(0, LED_STATUS_ON);
}

void test_LED_TurnOff(void) {
    // Expectation: GPIO function should be called with the correct parameters to turn the LED off
    MGPIO_enuSetPinValue_ExpectAndReturn(LEDS[0].Led_Port,LEDS[0].Led_Pin, LED_STATUS_OFF, MGPIO_enuOK);

    // Call the function to turn the LED off
    HLED_vSetLedStatus(0, LED_STATUS_OFF);
}


void test_LED_InvalidStatus(void) {
    // Expectation: GPIO function should not be called as an invalid status is provided
    // Expectation: GPIO function call with invalid status should return MGPIO_enuNOK
    MGPIO_enuSetPinValue_ExpectAndReturn(LEDS[0].Led_Port, LEDS[0].Led_Pin, 9, MGPIO_enuNOK);
    
    // Call the function with an invalid status
    HLED_vSetLedStatus(0, 9);
}







#endif // TEST
