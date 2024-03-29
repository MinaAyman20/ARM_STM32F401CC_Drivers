/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_GPIO.h"

static const char* CMockString_Add_strPinConfg = "Add_strPinConfg";
static const char* CMockString_Copy_pu32Pin = "Copy_pu32Pin";
static const char* CMockString_Copy_u32Pin = "Copy_u32Pin";
static const char* CMockString_Copy_u32Port = "Copy_u32Port";
static const char* CMockString_Copy_u32Value = "Copy_u32Value";
static const char* CMockString_MGPIO_enuSetPinConfig = "MGPIO_enuSetPinConfig";
static const char* CMockString_MGPIO_enuSetPinValue = "MGPIO_enuSetPinValue";
static const char* CMockString_MGPIO_getPinValue = "MGPIO_getPinValue";

typedef struct _CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  MGPIO_enuErrorStatus_t ReturnVal;
  int CallOrder;
  MGPIO_PIN_config_t* Expected_Add_strPinConfg;

} CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE;

typedef struct _CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  MGPIO_enuErrorStatus_t ReturnVal;
  int CallOrder;
  u32 Expected_Copy_u32Port;
  u32 Expected_Copy_u32Pin;
  u32 Expected_Copy_u32Value;

} CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE;

typedef struct _CMOCK_MGPIO_getPinValue_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  MGPIO_enuErrorStatus_t ReturnVal;
  int CallOrder;
  u32 Expected_Copy_u32Port;
  u32 Expected_Copy_u32Pin;
  u32* Expected_Copy_pu32Pin;

} CMOCK_MGPIO_getPinValue_CALL_INSTANCE;

static struct mock_GPIOInstance
{
  char MGPIO_enuSetPinConfig_IgnoreBool;
  MGPIO_enuErrorStatus_t MGPIO_enuSetPinConfig_FinalReturn;
  char MGPIO_enuSetPinConfig_CallbackBool;
  CMOCK_MGPIO_enuSetPinConfig_CALLBACK MGPIO_enuSetPinConfig_CallbackFunctionPointer;
  int MGPIO_enuSetPinConfig_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE MGPIO_enuSetPinConfig_CallInstance;
  char MGPIO_enuSetPinValue_IgnoreBool;
  MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue_FinalReturn;
  char MGPIO_enuSetPinValue_CallbackBool;
  CMOCK_MGPIO_enuSetPinValue_CALLBACK MGPIO_enuSetPinValue_CallbackFunctionPointer;
  int MGPIO_enuSetPinValue_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE MGPIO_enuSetPinValue_CallInstance;
  char MGPIO_getPinValue_IgnoreBool;
  MGPIO_enuErrorStatus_t MGPIO_getPinValue_FinalReturn;
  char MGPIO_getPinValue_CallbackBool;
  CMOCK_MGPIO_getPinValue_CALLBACK MGPIO_getPinValue_CallbackFunctionPointer;
  int MGPIO_getPinValue_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE MGPIO_getPinValue_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_GPIO_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.MGPIO_enuSetPinConfig_CallInstance;
  if (Mock.MGPIO_enuSetPinConfig_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_MGPIO_enuSetPinConfig);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.MGPIO_enuSetPinValue_CallInstance;
  if (Mock.MGPIO_enuSetPinValue_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_MGPIO_enuSetPinValue);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.MGPIO_getPinValue_CallInstance;
  if (Mock.MGPIO_getPinValue_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_MGPIO_getPinValue);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.MGPIO_getPinValue_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_GPIO_Init(void)
{
  mock_GPIO_Destroy();
}

void mock_GPIO_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

MGPIO_enuErrorStatus_t MGPIO_enuSetPinConfig(MGPIO_PIN_config_t* Add_strPinConfg)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_MGPIO_enuSetPinConfig);
  cmock_call_instance = (CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.MGPIO_enuSetPinConfig_CallInstance);
  Mock.MGPIO_enuSetPinConfig_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_enuSetPinConfig_CallInstance);
  if (Mock.MGPIO_enuSetPinConfig_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.MGPIO_enuSetPinConfig_FinalReturn;
    memcpy((void*)(&Mock.MGPIO_enuSetPinConfig_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.MGPIO_enuSetPinConfig_CallbackBool &&
      Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer != NULL)
  {
    MGPIO_enuErrorStatus_t cmock_cb_ret = Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer(Add_strPinConfg, Mock.MGPIO_enuSetPinConfig_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_enuSetPinConfig,CMockString_Add_strPinConfg);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_Add_strPinConfg), (void*)(Add_strPinConfg), sizeof(MGPIO_PIN_config_t), cmock_line, CMockStringMismatch);
  }
  if (Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer(Add_strPinConfg, Mock.MGPIO_enuSetPinConfig_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_MGPIO_enuSetPinConfig(CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE* cmock_call_instance, MGPIO_PIN_config_t* Add_strPinConfg);
void CMockExpectParameters_MGPIO_enuSetPinConfig(CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE* cmock_call_instance, MGPIO_PIN_config_t* Add_strPinConfg)
{
  cmock_call_instance->Expected_Add_strPinConfg = Add_strPinConfg;
}

void MGPIO_enuSetPinConfig_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE));
  CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_enuSetPinConfig_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_enuSetPinConfig_CallInstance, cmock_guts_index);
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)1;
}

void MGPIO_enuSetPinConfig_CMockStopIgnore(void)
{
  if(Mock.MGPIO_enuSetPinConfig_IgnoreBool)
    Mock.MGPIO_enuSetPinConfig_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_enuSetPinConfig_CallInstance);
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)0;
}

void MGPIO_enuSetPinConfig_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_PIN_config_t* Add_strPinConfg, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE));
  CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_enuSetPinConfig_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_enuSetPinConfig_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_enuSetPinConfig_CallInstance, cmock_guts_index);
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_MGPIO_enuSetPinConfig(cmock_call_instance, Add_strPinConfg);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_to_return) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
}

void MGPIO_enuSetPinConfig_AddCallback(CMOCK_MGPIO_enuSetPinConfig_CALLBACK Callback)
{
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)0;
  Mock.MGPIO_enuSetPinConfig_CallbackBool = (char)1;
  Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer = Callback;
}

void MGPIO_enuSetPinConfig_Stub(CMOCK_MGPIO_enuSetPinConfig_CALLBACK Callback)
{
  Mock.MGPIO_enuSetPinConfig_IgnoreBool = (char)0;
  Mock.MGPIO_enuSetPinConfig_CallbackBool = (char)0;
  Mock.MGPIO_enuSetPinConfig_CallbackFunctionPointer = Callback;
}

MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue(u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_MGPIO_enuSetPinValue);
  cmock_call_instance = (CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.MGPIO_enuSetPinValue_CallInstance);
  Mock.MGPIO_enuSetPinValue_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_enuSetPinValue_CallInstance);
  if (Mock.MGPIO_enuSetPinValue_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.MGPIO_enuSetPinValue_FinalReturn;
    memcpy((void*)(&Mock.MGPIO_enuSetPinValue_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.MGPIO_enuSetPinValue_CallbackBool &&
      Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer != NULL)
  {
    MGPIO_enuErrorStatus_t cmock_cb_ret = Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer(Copy_u32Port, Copy_u32Pin, Copy_u32Value, Mock.MGPIO_enuSetPinValue_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_enuSetPinValue,CMockString_Copy_u32Port);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Copy_u32Port), (void*)(&Copy_u32Port), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_enuSetPinValue,CMockString_Copy_u32Pin);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Copy_u32Pin), (void*)(&Copy_u32Pin), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_enuSetPinValue,CMockString_Copy_u32Value);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Copy_u32Value), (void*)(&Copy_u32Value), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  if (Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer(Copy_u32Port, Copy_u32Pin, Copy_u32Value, Mock.MGPIO_enuSetPinValue_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_MGPIO_enuSetPinValue(CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE* cmock_call_instance, u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value);
void CMockExpectParameters_MGPIO_enuSetPinValue(CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE* cmock_call_instance, u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value)
{
  memcpy((void*)(&cmock_call_instance->Expected_Copy_u32Port), (void*)(&Copy_u32Port),
         sizeof(u32[sizeof(Copy_u32Port) == sizeof(u32) ? 1 : -1])); /* add u32 to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_Copy_u32Pin), (void*)(&Copy_u32Pin),
         sizeof(u32[sizeof(Copy_u32Pin) == sizeof(u32) ? 1 : -1])); /* add u32 to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_Copy_u32Value), (void*)(&Copy_u32Value),
         sizeof(u32[sizeof(Copy_u32Value) == sizeof(u32) ? 1 : -1])); /* add u32 to :treat_as_array if this causes an error */
}

void MGPIO_enuSetPinValue_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE));
  CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_enuSetPinValue_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_enuSetPinValue_CallInstance, cmock_guts_index);
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)1;
}

void MGPIO_enuSetPinValue_CMockStopIgnore(void)
{
  if(Mock.MGPIO_enuSetPinValue_IgnoreBool)
    Mock.MGPIO_enuSetPinValue_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_enuSetPinValue_CallInstance);
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)0;
}

void MGPIO_enuSetPinValue_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE));
  CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_enuSetPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_enuSetPinValue_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_enuSetPinValue_CallInstance, cmock_guts_index);
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_MGPIO_enuSetPinValue(cmock_call_instance, Copy_u32Port, Copy_u32Pin, Copy_u32Value);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_to_return) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
}

void MGPIO_enuSetPinValue_AddCallback(CMOCK_MGPIO_enuSetPinValue_CALLBACK Callback)
{
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)0;
  Mock.MGPIO_enuSetPinValue_CallbackBool = (char)1;
  Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer = Callback;
}

void MGPIO_enuSetPinValue_Stub(CMOCK_MGPIO_enuSetPinValue_CALLBACK Callback)
{
  Mock.MGPIO_enuSetPinValue_IgnoreBool = (char)0;
  Mock.MGPIO_enuSetPinValue_CallbackBool = (char)0;
  Mock.MGPIO_enuSetPinValue_CallbackFunctionPointer = Callback;
}

MGPIO_enuErrorStatus_t MGPIO_getPinValue(u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MGPIO_getPinValue_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_MGPIO_getPinValue);
  cmock_call_instance = (CMOCK_MGPIO_getPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.MGPIO_getPinValue_CallInstance);
  Mock.MGPIO_getPinValue_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_getPinValue_CallInstance);
  if (Mock.MGPIO_getPinValue_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.MGPIO_getPinValue_FinalReturn;
    memcpy((void*)(&Mock.MGPIO_getPinValue_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.MGPIO_getPinValue_CallbackBool &&
      Mock.MGPIO_getPinValue_CallbackFunctionPointer != NULL)
  {
    MGPIO_enuErrorStatus_t cmock_cb_ret = Mock.MGPIO_getPinValue_CallbackFunctionPointer(Copy_u32Port, Copy_u32Pin, Copy_pu32Pin, Mock.MGPIO_getPinValue_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_getPinValue,CMockString_Copy_u32Port);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Copy_u32Port), (void*)(&Copy_u32Port), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_getPinValue,CMockString_Copy_u32Pin);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Copy_u32Pin), (void*)(&Copy_u32Pin), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_MGPIO_getPinValue,CMockString_Copy_pu32Pin);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_Copy_pu32Pin), (void*)(Copy_pu32Pin), sizeof(u32), cmock_line, CMockStringMismatch);
  }
  if (Mock.MGPIO_getPinValue_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.MGPIO_getPinValue_CallbackFunctionPointer(Copy_u32Port, Copy_u32Pin, Copy_pu32Pin, Mock.MGPIO_getPinValue_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_MGPIO_getPinValue(CMOCK_MGPIO_getPinValue_CALL_INSTANCE* cmock_call_instance, u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin);
void CMockExpectParameters_MGPIO_getPinValue(CMOCK_MGPIO_getPinValue_CALL_INSTANCE* cmock_call_instance, u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin)
{
  memcpy((void*)(&cmock_call_instance->Expected_Copy_u32Port), (void*)(&Copy_u32Port),
         sizeof(u32[sizeof(Copy_u32Port) == sizeof(u32) ? 1 : -1])); /* add u32 to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_Copy_u32Pin), (void*)(&Copy_u32Pin),
         sizeof(u32[sizeof(Copy_u32Pin) == sizeof(u32) ? 1 : -1])); /* add u32 to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_Copy_pu32Pin = Copy_pu32Pin;
}

void MGPIO_getPinValue_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_getPinValue_CALL_INSTANCE));
  CMOCK_MGPIO_getPinValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_getPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_getPinValue_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_getPinValue_CallInstance, cmock_guts_index);
  Mock.MGPIO_getPinValue_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.MGPIO_getPinValue_IgnoreBool = (char)1;
}

void MGPIO_getPinValue_CMockStopIgnore(void)
{
  if(Mock.MGPIO_getPinValue_IgnoreBool)
    Mock.MGPIO_getPinValue_CallInstance = CMock_Guts_MemNext(Mock.MGPIO_getPinValue_CallInstance);
  Mock.MGPIO_getPinValue_IgnoreBool = (char)0;
}

void MGPIO_getPinValue_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin, MGPIO_enuErrorStatus_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_MGPIO_getPinValue_CALL_INSTANCE));
  CMOCK_MGPIO_getPinValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_MGPIO_getPinValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.MGPIO_getPinValue_CallInstance = CMock_Guts_MemChain(Mock.MGPIO_getPinValue_CallInstance, cmock_guts_index);
  Mock.MGPIO_getPinValue_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_MGPIO_getPinValue(cmock_call_instance, Copy_u32Port, Copy_u32Pin, Copy_pu32Pin);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(MGPIO_enuErrorStatus_t[sizeof(cmock_to_return) == sizeof(MGPIO_enuErrorStatus_t) ? 1 : -1])); /* add MGPIO_enuErrorStatus_t to :treat_as_array if this causes an error */
}

void MGPIO_getPinValue_AddCallback(CMOCK_MGPIO_getPinValue_CALLBACK Callback)
{
  Mock.MGPIO_getPinValue_IgnoreBool = (char)0;
  Mock.MGPIO_getPinValue_CallbackBool = (char)1;
  Mock.MGPIO_getPinValue_CallbackFunctionPointer = Callback;
}

void MGPIO_getPinValue_Stub(CMOCK_MGPIO_getPinValue_CALLBACK Callback)
{
  Mock.MGPIO_getPinValue_IgnoreBool = (char)0;
  Mock.MGPIO_getPinValue_CallbackBool = (char)0;
  Mock.MGPIO_getPinValue_CallbackFunctionPointer = Callback;
}

