#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HSWITCH/HSWITCH_interface.h"

int main(void)
{ 
  MRCC_EnablePeripheral(MRCC_GPIOA);
  MRCC_EnablePeripheral(MRCC_GPIOB);
  HLED_vLedInit();
  HSWITCH_vSwitchInit();

  
  u32 state = SWITCH_STATUS_RELEASED;
  while (1)
    { 
     /* HSWITCH_enuGetSwitchState(Switch_1,&state);
      if(state == SWITCH_STATUS_PRESSED)
      {
        HLED_vSetLedStatus(Led_Start,LED_STATUS_ON);
      }
      else
      {
         HLED_vSetLedStatus(Led_Start,LED_STATUS_OFF);
      }*/
     // while (HSWITCH_enuGetSwitchState(Switch_1,&state));
      
      state = HSWITCH_u32GetSwitchState(Switch_1);
      if(state == SWITCH_STATUS_PRESSED)
      {
        HLED_vSetLedStatus(Led_Start,LED_STATUS_ON);
      }
      else
      {
         HLED_vSetLedStatus(Led_Start,LED_STATUS_OFF);
      }
    }
   






}

