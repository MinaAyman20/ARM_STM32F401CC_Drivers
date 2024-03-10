/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/
#include"MCAL/MNVIC/MNVIC_interface.h" // Include interface for NVIC operations
#include"MCAL/MNVIC/MNVIC_config.h" // Include configuration for NVIC
#include "MCAL/MNVIC/STMF401ccPERIPHERALS_INT_ID.h" // Include interrupt IDs


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
#define NVIC_BASE_ADDRESS     0xE000E100 // Base address of NVIC
#define SCB_BASE_ADDRESS      0xE000ED00 // Base address of System Control Block
#define NVIC_IABR_MASK        0x00000001 // Mask for NVIC interrupt active bit
#define SCB_AIRCR_ACTIVEKEY   0x05FA0000 // Active key for SCB AIRCR register
#define PRI_GROUP_SHIFT_VALUE 0x00000008 // Shift value for priority group
#define MSB                   0x00000004 // Most significant bit
#define POSTION               0x00000008 // Position value


/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

// Structure representing NVIC registers
typedef struct
{
    volatile u32 ISER[32]; // Interrupt Set Enable Registers
    volatile u32 ICER[32]; // Interrupt Clear Enable Registers
    volatile u32 ISPR[32]; // Interrupt Set Pending Registers
    volatile u32 ICPR[32]; // Interrupt Clear Pending Registers
    volatile u32 IAPR[32]; // Interrupt Active Bit Registers
    volatile u32 RESERVED[32]; // Reserved registers
    volatile u8  IPR[240]; // Interrupt Priority Registers (byte accessible)
} NVIC_t;

#define NVIC  ((volatile NVIC_t*)( NVIC_BASE_ADDRESS)) // Define NVIC structure instance


// Structure representing System Control Block registers
typedef struct
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;
} SCB_t;

#define SCB ((volatile SCB_t *)SCB_BASE_ADDRESS ) // Define SCB structure instance


/********************************************************************************************************/
/************************************************Variables***********************************************/
/********************************************************************************************************/
static u32 globalStatic_u32GroupConfig; // Global variable to store group configuration



/********************************************************************************************************/
/*****************************************Static Functions Prototype*************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/

MNVIC_enuErrorStatus_t MNVIC_VoidEnablePeripheralInterrupt(u8 Copy_u8INTID)
{
    MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;

    if(Copy_u8INTID >=  NVIC_NUM_INTERRUPTS )
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }
    else
    {
    NVIC->ISER[Copy_u8INTID/32]=1<<(Copy_u8INTID % 32);
    }
    return Ret_enuNVIC_ErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_VoidDisablePeripheralInterrupt(u8 Copy_u8INTID)
{
    MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;

    if(Copy_u8INTID >=  NVIC_NUM_INTERRUPTS )
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }
    else
    {
    NVIC->ICER[Copy_u8INTID/32]=1<<(Copy_u8INTID % 32);
    }
        return Ret_enuNVIC_ErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_VoidSetPending(u8 Copy_u8INTID)
{
    MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;

    if(Copy_u8INTID >=  NVIC_NUM_INTERRUPTS )
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }
    else
    {
    NVIC->ISPR[Copy_u8INTID/32]=1<<(Copy_u8INTID % 32);
    }
      return Ret_enuNVIC_ErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_VoidClearPending(u8 Copy_u8INTID)
{
     MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;

    if(Copy_u8INTID >=  NVIC_NUM_INTERRUPTS )
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }
    else
    {
    NVIC->ICPR[Copy_u8INTID/32]=1<<(Copy_u8INTID % 32);
    }
    return Ret_enuNVIC_ErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_u8GetActive(u8 Copy_u8INTID,u8* Copy_u8pActiveStatus)
{   
     MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;

    if(Copy_u8INTID >= NVIC_NUM_INTERRUPTS )
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }
   else if(Copy_u8pActiveStatus == NULL_PTR)
	{
		Ret_enuNVIC_ErrorStatus=MNVIC_enuNULLPOINTER;
	}

    else
    {
    *Copy_u8pActiveStatus = ( (NVIC->IAPR[Copy_u8INTID/32]) >> (Copy_u8INTID % 32)) & NVIC_IABR_MASK;
    }

    return Ret_enuNVIC_ErrorStatus;   
}

MNVIC_enuErrorStatus_t MNVIC_voidSetGroupPriorityBits(u32 Copy_u8GroupPriorityBits)
{   
     MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;
 if (   Copy_u8GroupPriorityBits != GROUPS_BITS_0 &&
        Copy_u8GroupPriorityBits != GROUPS_BITS_1 &&
        Copy_u8GroupPriorityBits != GROUPS_BITS_2 &&
        Copy_u8GroupPriorityBits != GROUPS_BITS_3 &&
        Copy_u8GroupPriorityBits != GROUPS_BITS_4  ) 
    {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_GROUP_PRI;
    } 
    else
    {
    globalStatic_u32GroupConfig = Copy_u8GroupPriorityBits;
    SCB->AIRCR = globalStatic_u32GroupConfig;
    }
    return Ret_enuNVIC_ErrorStatus;   
    
}

MNVIC_enuErrorStatus_t MNVIC_VoidSetPriority(s8 Copy_s8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority) {    
    MNVIC_enuErrorStatus_t Ret_enuNVIC_ErrorStatus = MNVIC_enuOK;
    
    if (Copy_s8INTID >= NVIC_NUM_INTERRUPTS) {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_INT_ID;
    }

    else if (Copy_u8GroupPriority > GROUP_PRIORITY_15) {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_GROUP_PRI;
    }

    else if (Copy_u8SubPriority > SUB_PRIORITY_15) {
        Ret_enuNVIC_ErrorStatus = MNVIC_enuWRONG_SUBGROUP_PRI;
    }
    else {

        u8 LOC_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((globalStatic_u32GroupConfig - GROUPS_BITS_0) / PRI_GROUP_SHIFT_VALUE);
     
        switch (Copy_s8INTID) {
            case MEMORY_MANAGE_IRQ:
            case BUS_FAULT_IRQ:
            case USAGE_FAULT_IRQ:
                SCB->SHPR1 = (LOC_u8Priority << ((POSTION  * (Copy_s8INTID + 3)) + MSB));
                break;

            case SV_CALL_IRQ:
                SCB->SHPR2 = (LOC_u8Priority << ((POSTION  * (Copy_s8INTID + 7)) + MSB));
                break;

            case PEND_SV_IRQ:
            case SYSTICK_IRQ:
                SCB->SHPR3 = (LOC_u8Priority << ((POSTION  * (Copy_s8INTID + 8)) + MSB));
                break;

            default:
                // Handle custom interrupts
                if (Copy_s8INTID >= 0 && Copy_s8INTID < NVIC_NUM_INTERRUPTS) {
                    NVIC->IPR[Copy_s8INTID] = (LOC_u8Priority << MSB);
                }
                break;
        }
    }
    
    return Ret_enuNVIC_ErrorStatus;
}


