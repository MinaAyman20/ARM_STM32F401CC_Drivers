/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_GPIO.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_HLED_vLedInit_ValidParameters(void);
extern void test_HLED_vSetLedStatus_ValidParamters(void);
extern void test_LED_TurnOn(void);
extern void test_LED_TurnOff(void);
extern void test_LED_InvalidStatus(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_GPIO_Init();
}
static void CMock_Verify(void)
{
  mock_GPIO_Verify();
}
static void CMock_Destroy(void)
{
  mock_GPIO_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_led.c");
  run_test(test_HLED_vLedInit_ValidParameters, "test_HLED_vLedInit_ValidParameters", 16);
  run_test(test_HLED_vSetLedStatus_ValidParamters, "test_HLED_vSetLedStatus_ValidParamters", 37);
  run_test(test_LED_TurnOn, "test_LED_TurnOn", 52);
  run_test(test_LED_TurnOff, "test_LED_TurnOff", 60);
  run_test(test_LED_InvalidStatus, "test_LED_InvalidStatus", 92);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
