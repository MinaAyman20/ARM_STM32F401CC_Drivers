#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "MCAL/MSYSTICK/MSYSTICK_interface.h"

void LED (void)
{
  static u32 Status = 0; 

    if (Status == 0)
    {
        HLED_vSetLedStatus(Led_Start, LED_STATUS_ON);
        Status = 1;
    }
    else
    {
        HLED_vSetLedStatus(Led_Start, LED_STATUS_OFF);
        Status = 0;
    }
}
int main(void)
{ 
  MRCC_EnablePeripheral(MRCC_GPIOA);
  HLED_vLedInit();
  MSYSTICK_vidInit();
  MSYSTICK_enuSetTimeMS(1000);
  MSYSTICK_enuSetCallback(LED);
  MSYSTICK_enuStart(SYSTICK_PERIODIC);


  while (1)
    { 
  
    }
    return 0 ;
}

