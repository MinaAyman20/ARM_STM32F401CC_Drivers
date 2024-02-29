#include "build/test/mocks/mock_GPIO.h"
#include "src/LED.h"
#include "C:/Ruby30/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






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

    testled.GPIOMode = 0x01;

    testled.GPIO_OUTPUTTYPE = 0;

    testled.GPIOSpeed = 0x02;

    testled.GPIO_INPUTTYPE = 0x00;

    int i = 0;



    for(i = 0; i<_Led_Num;i++)

    {

        testled.GPIOPort = LEDS[i].Led_Port;

        testled.GPIOPin = LEDS[i].Led_Pin;

        MGPIO_enuSetPinConfig_CMockExpectAndReturn(29, &testled, MGPIO_enuOK);

        MGPIO_enuSetPinValue_CMockExpectAndReturn(30, LEDS[i].Led_Port, LEDS[i].Led_Pin, LEDS[i].Led_InitStatus, MGPIO_enuOK);

    }



    HLED_vLedInit();

    mock_GPIO_Verify();

 }



void test_HLED_vSetLedStatus_ValidParamters(void) {



    u32 expected_port = 0;

    u32 expected_pin = 0x00000000;

    u8 expected_status = 1;

    u8 expected_connection = 0;

    u8 expected_calculated_value = expected_connection ^ expected_status;





    MGPIO_enuSetPinValue_CMockExpectAndReturn(46, expected_port, expected_pin, expected_calculated_value, MGPIO_enuOK);





    HLED_vSetLedStatus(0, 1);

}



void test_LED_TurnOn(void) {



    MGPIO_enuSetPinValue_CMockExpectAndReturn(54, LEDS[0].Led_Port, LEDS[0].Led_Pin, 1, MGPIO_enuOK);





    HLED_vSetLedStatus(0, 1);

}



void test_LED_TurnOff(void) {



    MGPIO_enuSetPinValue_CMockExpectAndReturn(62, LEDS[0].Led_Port, LEDS[0].Led_Pin, 0, MGPIO_enuOK);





    HLED_vSetLedStatus(0, 0);

}

void test_LED_InvalidStatus(void) {





    MGPIO_enuSetPinValue_CMockExpectAndReturn(95, LEDS[0].Led_Port, LEDS[0].Led_Pin, 9, MGPIO_enuNOK);





    HLED_vSetLedStatus(0, 9);

}
