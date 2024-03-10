#ifndef D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_MNVIC_INTERFACE_H_
#define D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_MNVIC_INTERFACE_H_

/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/
#include"LIB/STD_TYPES.h"
#include "MCAL/MNVIC/STMF401ccPERIPHERALS_INT_ID.h"


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/

// Constants for configuring interrupt priority grouping
#define GROUPS_BITS_4      0x05FA0700
#define GROUPS_BITS_3      0x05FA0600
#define GROUPS_BITS_2      0x05FA0500
#define GROUPS_BITS_1      0x05FA0400
#define GROUPS_BITS_0      0x05FA0300

// Priorities for interrupt groups and subgroups
#define NO_GROUP_PRIORITY 0
#define GROUP_PRIORITY_0 0
#define GROUP_PRIORITY_1 1
#define GROUP_PRIORITY_2 2
#define GROUP_PRIORITY_3 3
#define GROUP_PRIORITY_4 4
#define GROUP_PRIORITY_5 5
#define GROUP_PRIORITY_6 6
#define GROUP_PRIORITY_7 7
#define GROUP_PRIORITY_8 8
#define GROUP_PRIORITY_9 9
#define GROUP_PRIORITY_10 10
#define GROUP_PRIORITY_11 11
#define GROUP_PRIORITY_12 12
#define GROUP_PRIORITY_13 13
#define GROUP_PRIORITY_14 14
#define GROUP_PRIORITY_15 15

#define NO_SUB_PRIORITY 0
#define SUB_PRIORITY_0 0
#define SUB_PRIORITY_1 1
#define SUB_PRIORITY_2 2
#define SUB_PRIORITY_3 3
#define SUB_PRIORITY_4 4
#define SUB_PRIORITY_5 5
#define SUB_PRIORITY_6 6
#define SUB_PRIORITY_7 7
#define SUB_PRIORITY_8 8
#define SUB_PRIORITY_9 9
#define SUB_PRIORITY_10 10
#define SUB_PRIORITY_11 11
#define SUB_PRIORITY_12 12
#define SUB_PRIORITY_13 13
#define SUB_PRIORITY_14 14
#define SUB_PRIORITY_15 15

/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

// Enumeration for error status during NVIC operations
typedef enum
{
    MNVIC_enuOK                 ,
    MNVIC_enuNOK                ,
    MNVIC_enuWRONG_INT_ID       ,
    MNVIC_enuWRONG_GROUP_PRI    , 
    MNVIC_enuNULLPOINTER        ,
    MNVIC_enuWRONG_SUBGROUP_PRI ,

} MNVIC_enuErrorStatus_t;



/********************************************************************************************************/
/************************************************APIs****************************************************/
/********************************************************************************************************/
/**
 * @brief Enable peripheral interrupt.
 * 
 * This function enables the peripheral interrupt specified by the interrupt ID.
 * 
 * @param Copy_u8INTID: The ID of the interrupt to be enabled.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 */
MNVIC_enuErrorStatus_t MNVIC_VoidEnablePeripheralInterrupt(u8 Copy_u8INTID);

/**
 * @brief Disable peripheral interrupt.
 * 
 * This function disables the peripheral interrupt specified by the interrupt ID.
 * 
 * @param Copy_u8INTID: The ID of the interrupt to be disabled.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 */
MNVIC_enuErrorStatus_t MNVIC_VoidDisablePeripheralInterrupt(u8 Copy_u8INTID);

/**
 * @brief Set pending interrupt.
 * 
 * This function sets the pending status for the specified interrupt ID.
 * 
 * @param Copy_u8INTID: The ID of the interrupt to set pending.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 */
MNVIC_enuErrorStatus_t MNVIC_VoidSetPending(u8 Copy_u8INTID);

/**
 * @brief Clear pending interrupt.
 * 
 * This function clears the pending status for the specified interrupt ID.
 * 
 * @param Copy_u8INTID: The ID of the interrupt to clear pending.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 */
MNVIC_enuErrorStatus_t MNVIC_VoidClearPending(u8 Copy_u8INTID);

/**
 * @brief Get active interrupt status.
 * 
 * This function retrieves the active status of the specified interrupt ID.
 * 
 * @param Copy_u8INTID: The ID of the interrupt to get active status.
 * @param Copy_u8pActiveStatus: Pointer to store the active status.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 *         - MNVIC_enuNULLPOINTER: Null pointer provided for active status storage.
 */
MNVIC_enuErrorStatus_t MNVIC_u8GetActive(u8 Copy_u8INTID,u8* Copy_u8pActiveStatus);

/**
 * @brief Set group priority bits.
 * 
 * This function sets the priority grouping bits for the NVIC.
 * 
 * @param Copy_u8GroupPriorityBits: The value of group priority bits to be set.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_GROUP_PRI: Incorrect group priority bits provided.
 */
MNVIC_enuErrorStatus_t MNVIC_voidSetGroupPriorityBits(u32 Copy_u8GroupPriorityBits);

/**
 * @brief Set priority for interrupt.
 * 
 * This function sets the priority for the specified interrupt.
 * 
 * @param Copy_s8INTID: The ID of the interrupt to set priority.
 * @param Copy_u8GroupPriority: The priority value for the interrupt group.
 * @param Copy_u8SubPriority: The sub-priority value for the interrupt.
 * @return MNVIC_enuErrorStatus_t: Error status indicating success or failure of the operation.
 *         - MNVIC_enuOK: Operation successful.
 *         - MNVIC_enuWRONG_INT_ID: Incorrect interrupt ID provided.
 *         - MNVIC_enuWRONG_GROUP_PRI: Incorrect group priority value provided.
 *         - MNVIC_enuWRONG_SUBGROUP_PRI: Incorrect subgroup priority value provided.
 */
MNVIC_enuErrorStatus_t MNVIC_VoidSetPriority(s8 Copy_s8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);


#endif // D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_MNVIC_INTERFACE_H_