#include "HAL/HSWITCH/HSWITCH_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "LIB/STD_TYPES.h"


void Runnable_APP2(void)
{
    u8 static LOC_SwitchStatus = SWITCH_STATUS_RELEASED;
  //  SWITCH_getState( Switch_1, &LOC_SwitchStatus);
   LOC_SwitchStatus = HSWITCH_u32GetSwitchState(Switch_1);
    if (LOC_SwitchStatus == SWITCH_STATUS_PRESSED)
    {
        HLED_vSetLedStatus(Led_Switch, LED_STATUS_ON);
    }
    else
    {
        HLED_vSetLedStatus(Led_Switch, LED_STATUS_OFF);
    }
}