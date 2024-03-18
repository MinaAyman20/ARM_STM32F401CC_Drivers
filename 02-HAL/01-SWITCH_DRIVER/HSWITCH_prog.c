#include "MCAL/MGPIO/MGPIO_interface.h"
#include "HAL/HSWITCH/HSWITCH_interface.h"
#include "HAL/HSWITCH/HSWITCH_config.h"


extern Switch_CFG_t SWITCHES [];

void HSWITCH_vSwitchInit(void)
{
    u8 LOC_u8IDX;
    MGPIO_PIN_config_t Switch;
    Switch.GPIOMode=GPIO_INPUT;

    for(LOC_u8IDX=0; LOC_u8IDX <_Switch_Num; LOC_u8IDX++ )
    {
        Switch.GPIOPort=SWITCHES[LOC_u8IDX].Switch_Port;
        Switch.GPIOPin=SWITCHES[LOC_u8IDX].Switch_Pin;
        Switch.GPIO_INPUTTYPE=SWITCHES[LOC_u8IDX].Switch_Connection;
        MGPIO_enuSetPinConfig(&Switch);
       // MGPIO_enuSetPinValue(SWITCHES[LOC_u8IDX].Switch_Port,SWITCHES[LOC_u8IDX].Switch_Pin,SWITCHES[LOC_u8IDX].Switch_InitStatus);
    }
    
}
u32 HSWITCH_u32GetSwitchState(u32 Switch) {
    // Define variables
    u32 pinValue;
    MGPIO_enuErrorStatus_t Ret_enuGPIO_ErrorStatus;

    // Read the GPIO pin value
    Ret_enuGPIO_ErrorStatus = MGPIO_getPinValue(SWITCHES[Switch].Switch_Port, SWITCHES[Switch].Switch_Pin, &pinValue);

    // Check if GPIO reading was successful
    if (Ret_enuGPIO_ErrorStatus != MGPIO_enuOK) {
        // Handle error (e.g., return a default switch state or log an error)
       Ret_enuGPIO_ErrorStatus = MGPIO_enuNOK; // Replace DEFAULT_SWITCH_STATE with appropriate value
    }

    // Calculate the switch state based on the connection type
    // For pull-up connections (SWITCH_CONN_PULLUP), the switch is considered pressed when the GPIO pin is low (0) and released when high (1).
    // For pull-down connections (SWITCH_CONN_PULLDOWN), the switch is considered pressed when the GPIO pin is high (1) and released when low (0).
    // XOR operation toggles the switch state if the connection is pull-down, effectively swapping the logic levels.
    // Bitwise AND with 1 ensures that only the least significant bit is considered, masking any other bits.
    u8 switchState = (pinValue ^ SWITCHES[Switch].Switch_Connection) & 1;

    return switchState;
}



HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_u8State)
{
   HSWITCH_enuErrorStatus_t Ret_enuSwitchErrorStatus = HSWITCH_enuOK;
    u32 LOC_SwitchState = 0 ;
    
    if(Add_u8State==NULL_PTR)
	{
		Ret_enuSwitchErrorStatus=HSWITCH_enuNULLPOINTER;
	}
    if (Copy_u8SwitchName <_Switch_Num)
    {
       Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidSwitchNum;
    }
       Ret_enuSwitchErrorStatus = MGPIO_getPinValue(SWITCHES[Copy_u8SwitchName].Switch_Port, SWITCHES[Copy_u8SwitchName].Switch_Pin, &LOC_SwitchState);

        if (SWITCHES[Copy_u8SwitchName].Switch_Connection == SWITCH_CONN_PULLUP)
        {
            if (LOC_SwitchState == GPIO_LOW)
            {
                *Add_u8State = SWITCH_STATUS_PRESSED;
            }
            else if (LOC_SwitchState == GPIO_HIGH)
            {
                *Add_u8State = SWITCH_STATUS_RELEASED;
            }
            else
            {
                Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection; 
            }
        }
        else if (SWITCHES[Copy_u8SwitchName].Switch_Connection == SWITCH_CONN_PULLDOWN)
        {
            if (LOC_SwitchState == GPIO_HIGH)
            {
                *Add_u8State = SWITCH_STATUS_PRESSED;
            }
            else if (LOC_SwitchState == GPIO_LOW)
            {
                *Add_u8State = SWITCH_STATUS_RELEASED;
            }
            else
            {
                Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection; 
            }
        }
        else
        {
            Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection;
        }
    return Ret_enuSwitchErrorStatus;
}