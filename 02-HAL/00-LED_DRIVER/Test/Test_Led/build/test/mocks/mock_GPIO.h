/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_GPIO_H
#define _MOCK_GPIO_H

#include "unity.h"
#include "GPIO.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_GPIO_Init(void);
void mock_GPIO_Destroy(void);
void mock_GPIO_Verify(void);




#define MGPIO_enuSetPinConfig_IgnoreAndReturn(cmock_retval) MGPIO_enuSetPinConfig_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void MGPIO_enuSetPinConfig_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return);
#define MGPIO_enuSetPinConfig_StopIgnore() MGPIO_enuSetPinConfig_CMockStopIgnore()
void MGPIO_enuSetPinConfig_CMockStopIgnore(void);
#define MGPIO_enuSetPinConfig_ExpectAndReturn(Add_strPinConfg, cmock_retval) MGPIO_enuSetPinConfig_CMockExpectAndReturn(__LINE__, Add_strPinConfg, cmock_retval)
void MGPIO_enuSetPinConfig_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_PIN_config_t* Add_strPinConfg, MGPIO_enuErrorStatus_t cmock_to_return);
typedef MGPIO_enuErrorStatus_t (* CMOCK_MGPIO_enuSetPinConfig_CALLBACK)(MGPIO_PIN_config_t* Add_strPinConfg, int cmock_num_calls);
void MGPIO_enuSetPinConfig_AddCallback(CMOCK_MGPIO_enuSetPinConfig_CALLBACK Callback);
void MGPIO_enuSetPinConfig_Stub(CMOCK_MGPIO_enuSetPinConfig_CALLBACK Callback);
#define MGPIO_enuSetPinConfig_StubWithCallback MGPIO_enuSetPinConfig_Stub
#define MGPIO_enuSetPinValue_IgnoreAndReturn(cmock_retval) MGPIO_enuSetPinValue_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void MGPIO_enuSetPinValue_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return);
#define MGPIO_enuSetPinValue_StopIgnore() MGPIO_enuSetPinValue_CMockStopIgnore()
void MGPIO_enuSetPinValue_CMockStopIgnore(void);
#define MGPIO_enuSetPinValue_ExpectAndReturn(Copy_u32Port, Copy_u32Pin, Copy_u32Value, cmock_retval) MGPIO_enuSetPinValue_CMockExpectAndReturn(__LINE__, Copy_u32Port, Copy_u32Pin, Copy_u32Value, cmock_retval)
void MGPIO_enuSetPinValue_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value, MGPIO_enuErrorStatus_t cmock_to_return);
typedef MGPIO_enuErrorStatus_t (* CMOCK_MGPIO_enuSetPinValue_CALLBACK)(u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value, int cmock_num_calls);
void MGPIO_enuSetPinValue_AddCallback(CMOCK_MGPIO_enuSetPinValue_CALLBACK Callback);
void MGPIO_enuSetPinValue_Stub(CMOCK_MGPIO_enuSetPinValue_CALLBACK Callback);
#define MGPIO_enuSetPinValue_StubWithCallback MGPIO_enuSetPinValue_Stub
#define MGPIO_getPinValue_IgnoreAndReturn(cmock_retval) MGPIO_getPinValue_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void MGPIO_getPinValue_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, MGPIO_enuErrorStatus_t cmock_to_return);
#define MGPIO_getPinValue_StopIgnore() MGPIO_getPinValue_CMockStopIgnore()
void MGPIO_getPinValue_CMockStopIgnore(void);
#define MGPIO_getPinValue_ExpectAndReturn(Copy_u32Port, Copy_u32Pin, Copy_pu32Pin, cmock_retval) MGPIO_getPinValue_CMockExpectAndReturn(__LINE__, Copy_u32Port, Copy_u32Pin, Copy_pu32Pin, cmock_retval)
void MGPIO_getPinValue_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin, MGPIO_enuErrorStatus_t cmock_to_return);
typedef MGPIO_enuErrorStatus_t (* CMOCK_MGPIO_getPinValue_CALLBACK)(u32 Copy_u32Port, u32 Copy_u32Pin, u32* Copy_pu32Pin, int cmock_num_calls);
void MGPIO_getPinValue_AddCallback(CMOCK_MGPIO_getPinValue_CALLBACK Callback);
void MGPIO_getPinValue_Stub(CMOCK_MGPIO_getPinValue_CALLBACK Callback);
#define MGPIO_getPinValue_StubWithCallback MGPIO_getPinValue_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
