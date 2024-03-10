#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"

void delay_ms(u32 ms)
 {
    for (volatile u32 i = 0; i < ms * 16000; ++i)
    {

    }
}
void EXTI0_IRQHandler(void)
{
   HLED_vSetLedStatus(Led_Start,LED_STATUS_ON);
     MNVIC_VoidSetPending(EXTI1_IRQ);
      delay_ms(500); /*500 = 5 Sec*/
}
void EXTI1_IRQHandler(void)
{
   HLED_vSetLedStatus(Led_Start,LED_STATUS_OFF);
}

int main(void)
{ 
  MRCC_EnablePeripheral(MRCC_GPIOA);
  HLED_vLedInit();
  MNVIC_VoidEnablePeripheralInterrupt(EXTI0_IRQ);
  MNVIC_VoidEnablePeripheralInterrupt(EXTI1_IRQ);
  MNVIC_voidSetGroupPriorityBits(GROUPS_BITS_1);

MNVIC_VoidSetPriority(EXTI0_IRQ,GROUP_PRIORITY_1,SUB_PRIORITY_1);
MNVIC_VoidSetPriority(EXTI1_IRQ,GROUP_PRIORITY_0,SUB_PRIORITY_1);
  MNVIC_VoidSetPending(EXTI0_IRQ);





  while (1)
    { 
  
  
      
    }
    return 0 ;
}

