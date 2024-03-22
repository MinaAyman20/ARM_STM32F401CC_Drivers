/************************************************************************************************************************/
/*File          :       HLCD_prog.c                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       20/3/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/
#include "HAL/HLCD/HLCD_interface.h"
#include "HAL/HLCD/HLCD_config.h"
#include "HAL/HLCD/HLCD_priv.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "LIB/Bit_Math.h"

typedef enum{
    LCD_enuEnableOff,
    LCD_enuEnableOn
}LCD_enuEnableState;

typedef enum{
    LCD_REQ_IDLE,
    LCD_REQ_BUSY
}LCD_enuReqState;

typedef enum{
    LCD_Write_REQ,
    LCD_Clear_REQ,
    LCD_No_REQ
}LCD_enuReqType;

typedef enum
{
	INIT_STATE,
	OPERATION_STATE,
	OFF_STATE,
}LCD_State;

typedef enum
{   
	INIT_START,
	First_Part_FUNCTION_SET,
	Second_Part_FUNCTION_SET,
	DISPLAY_ON_OFF,
	CLEAR_DISPLAY,
	ENTRY_MODE,
    START_ADDRESS,
	LCD_DONE,
}LCD_InitStates;

typedef enum
{   
	Write_START,
	Write_SetPostion,
    Write_Character,
    Write_Done
}LCD_WriteStates;
typedef enum
{   
	Clear_START,
	Clear_Screen,
    Clear_Done,
}LCD_ClearStates;


typedef struct 
{
    const char*              String        ;
    u8                       String_Size   ;
    HLCD_enuDDRAM_XPosition  X_Postion     ;
    HLCD_enuDDRAM_YPosition  Y_Postion     ;
    LCD_enuReqState          Req_State     ;
    LCD_enuReqType           Req_Type      ;
}LCD_USER_DATA_t;

/************************************Global Variables************************************************************/
static LCD_State          Global_LCDState        = OFF_STATE       ;
static LCD_InitStates     Global_LCDInit_State   = INIT_START      ;
static LCD_enuEnableState Global_LCDEnable_State = LCD_enuEnableOff;
static LCD_WriteStates    Global_LCDWrite_State  = Write_START     ;
static LCD_ClearStates    Global_LCDClear_State  = Clear_START     ;
 u8 remaining_chars = 0;
 static u8 send_higher_nibble=1;
/*******************************************Prototypes of Static Function****************************************/
static void HLCD_vidInitProcess(void);
static void HLCD_vidWriteProc  (void);
static void HLCD_vidClearProc  (void);
/****************************************************************************************************************/
/*******************************************************************************************************************/
static LCD_USER_DATA_t   LCD_strUsrData ;
extern HLCD_strLCDConfigration LCD_PINS[USED_LCD_PIN_NUMS];
/*******************************************End of user Synch Function********************************************/

/*****************************************Ashync****************************************************************/
void HLCD_vidPinInit(void)
{
  
	/* INDEXING PINS TO CONFIGURE */
    u8 Loc_u8PinIndex = 0;
    /* STRUCTURE OF GPIO CONFIGURATION */
    MGPIO_PIN_config_t Pin_cfg;
    
    /* ITERATE THROUGH ALL THE PINS */
	for(Loc_u8PinIndex=0;Loc_u8PinIndex<USED_LCD_PIN_NUMS;Loc_u8PinIndex++){

		Pin_cfg.GPIOPort         = LCD_PINS[Loc_u8PinIndex].LCD_PortNum;
		Pin_cfg.GPIOPin          = LCD_PINS[Loc_u8PinIndex].LCD_PinNum;
		Pin_cfg.GPIOMode         = GPIO_OUTPUT ; 
        Pin_cfg.GPIO_OUTPUTTYPE  = GPIO_PUSHPULL;
        Pin_cfg.GPIOSpeed        = GPIO_HIGH_SPEED;

		/* INITIALIZE GPIO PORTS */
		MGPIO_enuSetPinConfig(& Pin_cfg);
	}

}

void HLCD_voidLCDInitASYNCH(void)
{
	Global_LCDState = INIT_STATE ;
}

static void HLCD_vidStaticSetEnableBit(u8 Copy_u8Value)
{
    MGPIO_enuSetPinValue(LCD_PINS[LCD_ENABLE_PIN].LCD_PortNum, LCD_PINS[LCD_ENABLE_PIN].LCD_PinNum, Copy_u8Value);
}

static void HLCD_StaticSendCommand(u8 Copy_u8Command,u8 RW_Value,u8 RS_Value)
{
	
    MGPIO_enuSetPinValue(LCD_PINS[LCD_RW_PIN].LCD_PortNum, LCD_PINS[LCD_RW_PIN].LCD_PinNum, RW_Value);
    MGPIO_enuSetPinValue(LCD_PINS[LCD_RS_PIN].LCD_PortNum, LCD_PINS[LCD_RS_PIN].LCD_PinNum, RS_Value);
    
    #if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D0_PIN].LCD_PortNum, LCD_PINS[LCD_D0_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,0));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D1_PIN].LCD_PortNum, LCD_PINS[LCD_D1_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,1));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D2_PIN].LCD_PortNum, LCD_PINS[LCD_D2_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,2));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D3_PIN].LCD_PortNum, LCD_PINS[LCD_D3_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,3));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D4_PIN].LCD_PortNum, LCD_PINS[LCD_D4_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,4));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D5_PIN].LCD_PortNum, LCD_PINS[LCD_D5_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,5));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D6_PIN].LCD_PortNum, LCD_PINS[LCD_D6_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,6));
    MGPIO_enuSetPinValue(LCD_PINS[LCD_D7_PIN].LCD_PortNum, LCD_PINS[LCD_D7_PIN].LCD_PinNum, GET_BIT(Copy_u8Command,7));
    
    #elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
    if (send_higher_nibble) {
        // Send the higher nibble of data (4 most significant bits)
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D4_PIN].LCD_PortNum, LCD_PINS[LCD_D4_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 4));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D5_PIN].LCD_PortNum, LCD_PINS[LCD_D5_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 5));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D6_PIN].LCD_PortNum, LCD_PINS[LCD_D6_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 6));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D7_PIN].LCD_PortNum, LCD_PINS[LCD_D7_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 7));
    } else {
        // Send the lower nibble of data (4 least significant bits)
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D4_PIN].LCD_PortNum, LCD_PINS[LCD_D4_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 0));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D5_PIN].LCD_PortNum, LCD_PINS[LCD_D5_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 1));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D6_PIN].LCD_PortNum, LCD_PINS[LCD_D6_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 2));
        MGPIO_enuSetPinValue(LCD_PINS[LCD_D7_PIN].LCD_PortNum, LCD_PINS[LCD_D7_PIN].LCD_PinNum, GET_BIT(Copy_u8Command, 3));
    }

    // Toggle the send_higher_nibble variable for next call
      send_higher_nibble = !send_higher_nibble;
#endif

}

void HLCD_vTask(void)
{
    if(Global_LCDState == INIT_STATE )
	{
           HLCD_vidInitProcess();
	}
    else if (Global_LCDState == OPERATION_STATE )
	{
       if(LCD_strUsrData.Req_State == LCD_REQ_BUSY)  //it means that there is a request from user
       {
          switch ( LCD_strUsrData.Req_Type)
          {
            case LCD_No_REQ: 
            // Do Nothing for LCD_No_REQ
            break;
            case LCD_Write_REQ :
             HLCD_vidWriteProc();
            break;
            case LCD_Clear_REQ :
            HLCD_vidClearProc();
            break;

          }
       }
	}

}

void HLCD_vidInitProcess()
{ 
    switch (Global_LCDInit_State)
    {
        case INIT_START:
        {   
            Global_LCDInit_State = First_Part_FUNCTION_SET;
            Global_LCDEnable_State = LCD_enuEnableOff;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
        }
        break;
        
        case First_Part_FUNCTION_SET: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_FUNCTION_SET_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                Global_LCDInit_State = DISPLAY_ON_OFF;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) 
            {
                if (send_higher_nibble) 
                {
                    // Send the higher nibble
                     HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_Fixed1_FunctionSet_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else 
                {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_Fixed1_FunctionSet_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } 
            else 
            {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) 
                {
                    Global_LCDInit_State = Second_Part_FUNCTION_SET;
                }
            }
#endif
        }
        break;
        
        case Second_Part_FUNCTION_SET: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            // No action needed in 8-bit mode for the second part
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_FUNCTION_SET_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_FUNCTION_SET_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = DISPLAY_ON_OFF;
                }
            }
#endif
        }
        break;
        
        case DISPLAY_ON_OFF: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_DISPLAY_ON_OFF_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                Global_LCDInit_State = CLEAR_DISPLAY;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_DISPLAY_ON_OFF_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_DISPLAY_ON_OFF_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = CLEAR_DISPLAY;
                }
            }
#endif
        }
        break;
        
        case CLEAR_DISPLAY: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_CLEAR_DISPLAY_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                Global_LCDInit_State = ENTRY_MODE;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_CLEAR_DISPLAY_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_CLEAR_DISPLAY_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = ENTRY_MODE;
                }
            }
#endif
        }
        break;
        
        case ENTRY_MODE: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_ENTRY_MODE_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                Global_LCDInit_State = START_ADDRESS;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_ENTRY_MODE_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_ENTRY_MODE_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = START_ADDRESS;
                }
            }
#endif
        }
        break;
      
        case START_ADDRESS: 
        {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_STARTADDRESS_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                Global_LCDInit_State = LCD_DONE;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_STARTADDRESS_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_STARTADDRESS_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = LCD_DONE;
                }
            }
#endif
        }
        break;
        
        case LCD_DONE: 
        {
            Global_LCDState = OPERATION_STATE;           
        }
        break;
    }
}


HLCD_enuErrorStatus_t HLCD_voidLCD_WriteStringAsync(const char* String,u8 Size ,u8 X_Postion,u8 Y_Postion)
{
  HLCD_enuErrorStatus_t  Ret_enuLCDErrorStatus = HLCD_enuOK ;

    if(String == NULL){
        Ret_enuLCDErrorStatus = HLCD_enuNull_Pointer;
    }
    
    if(X_Postion > HLCD_enuSecondLine)
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_XPositionError ;
	}
	else if(Y_Postion >  HLCD_enuPosition15 )
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_YPositionError ;
	}
    else
    {      
        if(Global_LCDState == OPERATION_STATE && LCD_strUsrData.Req_State == LCD_REQ_IDLE)
        {     
                LCD_strUsrData.String      = String          ;
                LCD_strUsrData.X_Postion   = X_Postion       ;   
                LCD_strUsrData.Y_Postion   = Y_Postion       ;  
                LCD_strUsrData.String_Size = Size            ;    
                LCD_strUsrData.Req_State   = LCD_REQ_BUSY    ;
                LCD_strUsrData.Req_Type    = LCD_Write_REQ   ;
                Global_LCDWrite_State      = Write_START     ;
                remaining_chars = LCD_strUsrData.String_Size ;  
                 
        }
        else
        {
             Ret_enuLCDErrorStatus = HLCD_enuNotReady ; 
        } 
    }
    return Ret_enuLCDErrorStatus ; 
}

 void HLCD_vidWriteProc(void)
 { 
    switch (Global_LCDWrite_State)
    {
        case Write_START :
        {
            Global_LCDWrite_State = Write_SetPostion    ;
            Global_LCDEnable_State = LCD_enuEnableOff   ;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
        }
        break;

        case Write_SetPostion:
      {
        u8 Copy_u8Location = 0;
        if (LCD_strUsrData.X_Postion == HLCD_enuFirstLine) {
            Copy_u8Location = LCD_strUsrData.Y_Postion;
        } else {
            // Increment 0x40 to the address to go to the first position of the second line
            Copy_u8Location = LCD_strUsrData.Y_Postion + 0x40;
        }

        // Send command to go to position in DDRAM
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
        if (Global_LCDEnable_State == LCD_enuEnableOff) {
            HLCD_StaticSendCommand(Copy_u8Location + 128, LCD_RESETVALUE, LCD_RESETVALUE);
            Global_LCDEnable_State = LCD_enuEnableOn;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
        } else {
            Global_LCDEnable_State = LCD_enuEnableOff;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
            Global_LCDWrite_State = Write_Character;
        }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
        if (Global_LCDEnable_State == LCD_enuEnableOff)
        {
            if (send_higher_nibble) {
                // Send the higher nibble
                HLCD_StaticSendCommand(HIGH_NIBBLE(Copy_u8Location + 128), LCD_RESETVALUE, LCD_RESETVALUE);
            } else {
                // Send the lower nibble
                HLCD_StaticSendCommand(LOW_NIBBLE(Copy_u8Location + 128), LCD_RESETVALUE, LCD_RESETVALUE);
            }

            Global_LCDEnable_State = LCD_enuEnableOn;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
        } 
        else
        {
            Global_LCDEnable_State = LCD_enuEnableOff;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
            if (send_higher_nibble) {
                Global_LCDWrite_State = Write_Character;
            }
        }
#endif
      }
    break;
case Write_Character:
{
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
    if (remaining_chars > 0) 
    {
        if (Global_LCDEnable_State == LCD_enuEnableOff) 
        {
            HLCD_StaticSendCommand(LCD_strUsrData.String[LCD_strUsrData.String_Size - remaining_chars],LCD_RESETVALUE,LCD_ENABLEVALUE);
            Global_LCDEnable_State = LCD_enuEnableOn;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
        } 
        else
        { 
            Global_LCDEnable_State = LCD_enuEnableOff;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
            remaining_chars--;
        }
    } 
    else 
    {
        Global_LCDWrite_State = Write_Done; 
    }

#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
    if (remaining_chars > 0) {
        if (Global_LCDEnable_State == LCD_enuEnableOff) {
            if (send_higher_nibble) {
                // Send the higher nibble
                HLCD_StaticSendCommand(HIGH_NIBBLE(LCD_strUsrData.String[LCD_strUsrData.String_Size - remaining_chars]), LCD_RESETVALUE, LCD_ENABLEVALUE);
            } else {
                // Send the lower nibble
                HLCD_StaticSendCommand(LOW_NIBBLE(LCD_strUsrData.String[LCD_strUsrData.String_Size - remaining_chars]), LCD_RESETVALUE, LCD_ENABLEVALUE);
                remaining_chars--;
            }

            Global_LCDEnable_State = LCD_enuEnableOn;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
        } else {
            Global_LCDEnable_State = LCD_enuEnableOff;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
        }
    } else {
        // Code executed when remaining_chars is zero
        Global_LCDWrite_State = Write_Done;
        Global_LCDEnable_State = LCD_enuEnableOff;  // Turn off LCD enable state
        HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
    }
#endif

}
break;

case Write_Done :
{
         LCD_strUsrData.Req_State   = LCD_REQ_IDLE  ;
         LCD_strUsrData.Req_Type    = LCD_No_REQ    ; 
}
break;
    }
 }

HLCD_enuErrorStatus_t HLCD_voidLCD_ClearScreen(void)
{
    HLCD_enuErrorStatus_t  Ret_enuLCDErrorStatus = HLCD_enuOK ;

    if(Global_LCDState == OPERATION_STATE && LCD_strUsrData.Req_State == LCD_REQ_IDLE)
        {      
                LCD_strUsrData.Req_State   = LCD_REQ_BUSY  ;
                LCD_strUsrData.Req_Type    = LCD_Clear_REQ ;       
                Global_LCDClear_State      = Clear_START   ;    
        }
        else
        {
                Ret_enuLCDErrorStatus = HLCD_enuNotReady ; 
        }
        return Ret_enuLCDErrorStatus;
}

void HLCD_vidClearProc  (void)
{
   switch(Global_LCDClear_State)
   {
    case Clear_START:
    {
            Global_LCDClear_State   = Clear_Screen       ;
            Global_LCDEnable_State  = LCD_enuEnableOff   ;
            HLCD_vidStaticSetEnableBit(LCD_enuEnableOff) ;
    }
    break;
    case Clear_Screen:
    {
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                HLCD_StaticSendCommand(HLCD_CLEAR_DISPLAY_8BIT_CMD, LCD_RESETVALUE, LCD_RESETVALUE);
                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                 Global_LCDInit_State = Clear_Done;
            }
#elif HLCD_BIT_MODE == HLCD_enu4BIT_MODE
            if (Global_LCDEnable_State == LCD_enuEnableOff) {
                if (send_higher_nibble) {
                    // Send the higher nibble
                    HLCD_StaticSendCommand(HIGH_NIBBLE(HLCD_CLEAR_DISPLAY_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                } else {
                    // Send the lower nibble
                    HLCD_StaticSendCommand(LOW_NIBBLE(HLCD_CLEAR_DISPLAY_4BIT_CMD), LCD_RESETVALUE, LCD_RESETVALUE);
                }

                Global_LCDEnable_State = LCD_enuEnableOn;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOn);
            } else {
                Global_LCDEnable_State = LCD_enuEnableOff;
                HLCD_vidStaticSetEnableBit(LCD_enuEnableOff);
                if (send_higher_nibble) {
                    Global_LCDInit_State = Clear_Done;
                }
            }
#endif
        }
    break;
    case Clear_Done:
         LCD_strUsrData.Req_State   = LCD_REQ_IDLE  ;
         LCD_strUsrData.Req_Type    = LCD_No_REQ    ; 
    break;
   }

}


 /***************************************End Of Asynch Functions *********************************************/
 