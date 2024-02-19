/*
 * MRCC_interface.h
 *
 *  Created on: Feb 8, 2024
 *      Author: Mina
 */

#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_

#include "LIB/STD_TYPES.h"

/*
 * Defines the internal frequency of the clock.
 */
#define INTERNAL_FREQ_CLOCK   16000000

/*
 * Defines the external frequency of the clock.
 */
#define EXTERNAL_FREQ_CLOCK   25000000

/*
 * Enumeration defining the system clock sources.
 */
typedef enum
{
	SYSCLK_HSI = 0x00000000,
	SYSCLK_HSE = 0x00000001,
	SYSCLK_PLL = 0x00000002
} SysClockSource_t;

/*
 * Enumeration defining the PLL clock sources.
 */
typedef enum
{
	PLLCLK_HSI = 0x00000000,
	PLLCLK_HSE = 0x00400000
} PLLClockSource_t;

/*
 * Enumeration defining the prescalers for the AHB bus.
 */
typedef enum
{
	AHP_SYSCLK_PRESCALLER_2   =   0x00000080 ,
	AHP_SYSCLK_PRESCALLER_4   =   0x00000090 ,
	AHP_SYSCLK_PRESCALLER_8   =   0x000000A0 ,
	AHP_SYSCLK_PRESCALLER_16  =   0x000000B0 ,
	AHP_SYSCLK_PRESCALLER_64  =   0x000000C0 ,
	AHP_SYSCLK_PRESCALLER_128 =   0x000000D0 ,
	AHP_SYSCLK_PRESCALLER_256 =   0x000000E0 ,
	AHP_SYSCLK_PRESCALLER_512 =   0x000000F0 
} AHP_PRESCALLERS;

/*
 * Enumeration defining the prescalers for the APB1 bus.
 */
typedef enum
{
	APB1_SYSCLK_PRESCALLER_2 =   0x00001000 ,
	APB1_SYSCLK_PRESCALLER_4 =   0x00001400 ,
	APB1_SYSCLK_PRESCALLER_8 =   0x00001800 ,
	APB1_SYSCLK_PRESCALLER_16 =  0x00001C00 
} APB1_PRESCALLERS;

/*
 * Enumeration defining the prescalers for the APB2 bus.
 */
typedef enum
{
	APB2_SYSCLK_PRESCALLER_2 =   0x00008000 ,
	APB2_SYSCLK_PRESCALLER_4 =   0x0000A000 ,
	APB2_SYSCLK_PRESCALLER_8 =   0x0000C000 ,
	APB2_SYSCLK_PRESCALLER_16 =  0x0000E000 
} APB2_PRESCALLERS;

/*
 * Enumeration defining the various peripherals.
 */
typedef enum
{
	/* AHB1_BUS PERIPHERALS*/
	MRCC_GPIOA ,
	MRCC_GPIOB ,
	MRCC_GPIOC ,
	MRCC_GPIOD ,
	MRCC_GPIOE ,
	MRCC_GPIOH ,
	MRCC_CRC   ,
	MRCC_DMA1  ,
	MRCC_DMA2  ,

	/* AHB2_BUS PERIPHERALS*/
	MRCC_USB_OTGFS,

	/* APB1_BUS PERIPHERALS */
	MRCC_TIM2  ,
	MRCC_TIM3  ,
	MRCC_TIM4  ,
	MRCC_TIM5  ,
	MRCC_WWDG  ,
	MRCC_SPI2  ,
	MRCC_SPI3  ,
	MRCC_USART2,
	MRCC_I2C1  ,
	MRCC_I2C2  ,
	MRCC_I2C3  ,
	MRCC_PWR   ,

	/* APB2_BUS PERIPHERALS */
	MRCC_TIM1   ,
	MRCC_USART1 ,
	MRCC_USART6 ,
	MRCC_ADC1   ,
	MRCC_SDIO   ,
	MRCC_SPI1   ,
	MRCC_SPI4   ,
	MRCC_SYSCFG ,
	MRCC_TIM9   ,
	MRCC_TIM10  ,
	MRCC_TIM11  
} Peripherals_t;

/*
 * Enumeration defining the possible error statuses.
 */
typedef enum
{
    MRCC_enuOK                   ,
    MRCC_enuNOK                  ,
	MRCC_enuInvalidPLL_CLKSRC    ,
	MRCC_enuINVALID_N_VALUE_ERROR,
	MRCC_enuINVALID_M_VALUE_ERROR,
    MRCC_enuINVALID_P_VALUE_ERROR,
    MRCC_enuINVALID_Q_VALUE_ERROR
} MRCC_enuErrorStatus_t;

/**
 * @brief Enables the specified system clock source.
 * 
 * This function enables the system clock based on the specified source.
 * 
 * @param Copy_u8SYSCLK The desired system clock source:
 *                      - SYSCLK_HSE: High-Speed External clock
 *                      - SYSCLK_HSI: High-Speed Internal clock
 *                      - SYSCLK_PLL: Phase-Locked Loop clock
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                                - MRCC_enuOK: Operation successful
 *                                - MRCC_enuNOK: Invalid system clock source specified
 */
MRCC_enuErrorStatus_t MRCC_EnableSysClock(u8 Copy_u8SysClk);


/**
 * @brief Selects the system clock source.
 * 
 * This function selects the system clock source among HSE (High-Speed External),
 * HSI (High-Speed Internal), and PLL (Phase-Locked Loop).
 * 
 * @param Copy_u8SYSCLK The desired system clock source:
 *                      - SYSCLK_HSE: High-Speed External clock
 *                      - SYSCLK_HSI: High-Speed Internal clock
 *                      - SYSCLK_PLL: Phase-Locked Loop clock
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                                - MRCC_enuOK: Operation successful
 *                                - MRCC_enuNOK: Selected clock source is not enabled
 */
MRCC_enuErrorStatus_t MRCC_SelectSysClock(u8 Copy_u8SysClk);

/**
 * @brief Reads the current system clock status.
 * 
 * This function reads the current status of the system clock and stores it in the provided pointer.
 * 
 * @param Add_pu8SysClockStatus Pointer to a variable where the system clock status will be stored.
 *                              Possible values are SYSCLK_HSI, SYSCLK_HSE, or SYSCLK_PLL.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                                - MRCC_enuOK: Operation successful
 *                                - MRCC_enuNOK: Unable to determine system clock status
 */
MRCC_enuErrorStatus_t MRCC_enuReadSysClock(u8* Add_pu8SysClockStatus);

/**
 * @brief Enables the clock for a specific peripheral.
 * 
 * This function enables the clock signal to the specified peripheral.
 * 
 * @param Copy_u8Peripheral The peripheral to enable:
 *                          - For AHB1 bus: MRCC_GPIOA, MRCC_GPIOB, MRCC_GPIOC, MRCC_GPIOD, MRCC_GPIOE,
 *                            MRCC_GPIOH, MRCC_CRC, MRCC_DMA1, MRCC_DMA2
 *                          - For AHB2 bus: MRCC_USB_OTGFS
 *                          - For APB1 bus: MRCC_TIM2, MRCC_TIM3, MRCC_TIM4, MRCC_TIM5, MRCC_WWDG,
 *                            MRCC_SPI2, MRCC_SPI3, MRCC_USART2, MRCC_I2C1, MRCC_I2C2, MRCC_I2C3,
 *                            MRCC_PWR
 *                          - For APB2 bus: MRCC_TIM1, MRCC_USART1, MRCC_USART6, MRCC_ADC1, MRCC_SDIO,
 *                            MRCC_SPI4, MRCC_SPI1, MRCC_SYSCFG, MRCC_TIM9, MRCC_TIM10, MRCC_TIM11
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                                - MRCC_enuOK: Operation successful
 *                                - MRCC_enuNOK: Invalid peripheral specified
 */
MRCC_enuErrorStatus_t MRCC_EnablePeripheral(Peripherals_t Copy_u8SysClk);

/**
 * @brief Disables the clock for the specified peripheral.
 * 
 * This function disables the clock for the specified peripheral.
 * 
 * @param Copy_u8Peripheral The peripheral to disable clock for, specified by Peripherals_t enum.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                               - MRCC_enuOK: Operation successful
 *                               - MRCC_enuNOK: Unable to disable clock for the peripheral
 */
MRCC_enuErrorStatus_t MRCC_DisablePeripheral(Peripherals_t Copy_u8SysClk);

/**
 * @brief Configures the AHB bus prescaler.
 * 
 * This function configures the AHB bus prescaler.
 * 
 * @param Copy_enmPrescaller The prescaler value to set, specified by the AHP_PRESCALLERS enum.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                               - MRCC_enuOK: Operation successful
 */
MRCC_enuErrorStatus_t MRCC_ConfigureAHPPrescaller  (AHP_PRESCALLERS Copy_enmPrescaller);

/**
 * @brief Configures the APB1 bus prescaler.
 * 
 * This function configures the APB1 bus prescaler.
 * 
 * @param Copy_enmPrescaller The prescaler value to set, specified by the APB1_PRESCALLERS enum.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                               - MRCC_enuOK: Operation successful
 */
MRCC_enuErrorStatus_t MRCC_ConfigureAPB1Prescaller (APB1_PRESCALLERS Copy_enmPrescaller);
/**
 * @brief Configures the APB2 bus prescaler.
 * 
 * This function configures the APB2 bus prescaler.
 * 
 * @param Copy_enmPrescaller The prescaler value to set, specified by the APB2_PRESCALLERS enum.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                               - MRCC_enuOK: Operation successful
 */
MRCC_enuErrorStatus_t MRCC_ConfigureAPB2Prescaller (APB2_PRESCALLERS  Copy_enmPrescaller);

/*
 * Function: MRCC_SetPllClkSrc
 * ----------------------------
 * Sets the source of the PLL (Phase-Locked Loop) clock in a microcontroller.
 *
 * RCC_PLLClkSrc: The desired PLL clock source (PLLCLK_HSI or PLLCLK_HSE).
 *
 * returns: MRCC_enuErrorStatus_t indicating whether the operation was successful or if there was an error.
 */
MRCC_enuErrorStatus_t MRCC_SetPllClkSrc(PLLClockSource_t RCC_PLLClkSrc);

/**
 * @brief Configures the PLL clock.
 * 
 * This function configures the PLL clock according to the specified parameters.
 * 
 * @param Copy_u32NValue The PLL multiplication factor (N), ranging from 192 to 432.
 * @param Copy_u32MValue The PLL input division factor (M), ranging from 2 to 63.
 * @param Copy_u32PValue The PLL main division factor (P), which can be 2, 4, 6, or 8.
 * @param Copy_u32QValue The PLL output division factor (Q), ranging from 2 to 15.
 * @return MRCC_enuErrorStatus_t The status of the operation:
 *                               - MRCC_enuOK: Operation successful
 *                               - MRCC_enuINVALID_N_VALUE_ERROR: Invalid N value
 *                               - MRCC_enuINVALID_M_VALUE_ERROR: Invalid M value
 *                               - MRCC_enuINVALID_P_VALUE_ERROR: Invalid P value
 *                               - MRCC_enuINVALID_Q_VALUE_ERROR: Invalid Q value
 *                               - MRCC_enuNOK: Operation failed
 */
MRCC_enuErrorStatus_t MRCC_ConfigurePLLCLK(u32 Copy_u32NValue ,u32 Copy_u32MValue,u32 Copy_u32PValue,u32 Copy_u32QValue);
#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
