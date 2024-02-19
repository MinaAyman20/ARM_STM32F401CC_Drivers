/*
 * MRCC_prog.c
 *
 *  Created on: Feb 8, 2024
 *      Author: Mina
 */

#include "LIB/STD_TYPES.h"
#include "MCAL/MRCC/MRCC_interface.h"

/*
 * Defines the base address of the RCC (Reset and Clock Control) peripheral.
 */
#define RCC_BASE_ADDRESS           0x40023800

/*
 * Masks to clear specific bits in the RCC registers.
 */
#define AHP_PRESCALLER_CLEARMASK   0xFFFFFF0F
#define APB1_PRESCALLER_CLEARMASK  0xFFFFE3FF
#define APB2_PRESCALLER_CLEARMASK  0xFFFF1FFF
#define PLL_PRESCALLER_MASK        0x0F037FFF

/*
 * Masks for various clock control bits in the RCC registers.
 */
#define SYSCLK_MASK               0x00000003
#define HSI_ON_MASK               0x00000001
#define HSE_ON_MASK               0x00010000
#define PLL_ON_MASK               0x01000000
#define STATUS_HSI_MASK 	       0x00000000
#define STATUS_HSE_MASK			   0x00000004
#define STATUS_PLL_MASK 		   0x00000008

/*
 * Positions of specific bits in the RCC registers.
 */
#define HSION  0
#define HSEON  16
#define PLLON  24
#define PLL_M  0
#define PLL_N  6
#define PLL_P  16
#define PLL_Q  24
#define PLLSRC 22

/*
 * Peripheral enable/disable bit positions for AHB1, AHB2, APB1, and APB2 buses.
 */
#define GPIOAEN    0
#define GPIOBEN    1
#define GPIOCEN    2
#define GPIODEN    3
#define GPIOEEN    4
#define GPIOHEN    7
#define CRCEN      12
#define DMA1EN     21
#define DMA2EN     22
#define OTGFSEN    7
#define TIM2EN     0
#define TIM3EN     1
#define TIM4EN     2
#define TIM5EN     3
#define WWDGEN     11
#define SPI2EN     14
#define SPI3EN     15
#define USART2EN   17
#define I2C1EN     21
#define I2C2EN     22
#define I2C3EN     23
#define PWREN      28
#define TIM1EN     0
#define USART1EN   4
#define USART6EN   5
#define ADC1EN     8
#define SDIOEN     11
#define SPI1EN     12
#define SPI4EN     13
#define SYSCFGEN   14
#define TIM9EN     16
#define TIM10EN    17
#define TIM11EN    18

/*
 * Structure representing the RCC (Reset and Clock Control) peripheral registers.
 */
typedef struct
{
	u32 CR;           /* Clock control register */
	u32 PLLCFGR;      /* PLL configuration register */
	u32 CFGR;         /* Clock configuration register */
	u32 CIR;          /* Clock interrupt register */
	u32 AHB1RSTR;     /* AHB1 peripheral reset register */
	u32 AHB2RSTR;     /* AHB2 peripheral reset register */
	u32 reserved1 ;   /* Reserved */
	u32 reserved2 ;   /* Reserved */
	u32 APB1RSTR;     /* APB1 peripheral reset register */
	u32 APB2RSTR;     /* APB2 peripheral reset register */
	u32 reserved3 ;   /* Reserved */
	u32 reserved4 ;   /* Reserved */
	u32 AHB1ENR;      /* AHB1 peripheral clock enable register */
	u32 AHB2ENR;      /* AHB2 peripheral clock enable register */
	u32 reserved5 ;   /* Reserved */
	u32 reserved6 ;   /* Reserved */
	u32 APB1ENR;      /* APB1 peripheral clock enable register */
	u32 APB2ENR;      /* APB2 peripheral clock enable register */
	u32 reserved7 ;   /* Reserved */
	u32 reserved8 ;   /* Reserved */
	u32 AHB1LPENR;    /* AHB1 peripheral clock enable in low power mode register */
	u32 AHB2LPENR;    /* AHB2 peripheral clock enable in low power mode register */
	u32 reserved9 ;   /* Reserved */
	u32 reserved10 ;  /* Reserved */
	u32 APB1LPENR;    /* APB1 peripheral clock enable in low power mode register */
	u32 APB2LPENR;    /* APB2 peripheral clock enable in low power mode register */
	u32 reserved11 ;  /* Reserved */
	u32 reserved12 ;  /* Reserved */
	u32 BDCR;         /* Backup domain control register */
	u32 CSR;          /* Clock control & status register */
	u32 reserved13 ;  /* Reserved */
	u32 reserved14 ;  /* Reserved */
	u32 SSCGR;        /* Spread spectrum clock generation register */
	u32 PLLI2SCFGR;   /* PLLI2S configuration register */
	u32 reserved15 ;  /* Reserved */
	u32 DCKCFGR;      /* Dedicated Clock Configuration Register */
} RCC_t;

/*
 * Macro to access the RCC registers.
 */
#define RCC  ((volatile RCC_t*)( RCC_BASE_ADDRESS))






MRCC_enuErrorStatus_t MRCC_EnableSysClock (u8 Copy_u8SYSCLK)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
	switch ( Copy_u8SYSCLK )
	{
	case SYSCLK_HSE :
		RCC->CR |= (1 << HSEON);
	break;
	case SYSCLK_HSI :
		RCC->CR |= (1 << HSION);
	break;
	case SYSCLK_PLL :
		RCC->CR |= (1 << PLLON);
	break;
	default :  Ret_enuRCC_ErrorStatus = MRCC_enuNOK;
	break;
	}
    return Ret_enuRCC_ErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_SelectSysClock  (u8 Copy_u8SYSCLK)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
    u32 LOC_u32RegValue = 0;

switch (Copy_u8SYSCLK) {
    case SYSCLK_HSE: {
        if ((RCC->CR & HSE_ON_MASK) == HSE_ON_MASK) {
            LOC_u32RegValue = RCC->CFGR;
            LOC_u32RegValue &= ~(SYSCLK_MASK);
            LOC_u32RegValue |= (u32)Copy_u8SYSCLK;
            RCC->CFGR = LOC_u32RegValue;
        } else {
            Ret_enuRCC_ErrorStatus = MRCC_enuNOK;
        }
        break;
    }


	case SYSCLK_HSI: {
        if ((RCC->CR & HSI_ON_MASK) == HSI_ON_MASK) {
            LOC_u32RegValue = RCC->CFGR;
            LOC_u32RegValue &= ~(SYSCLK_MASK);
            LOC_u32RegValue |= Copy_u8SYSCLK;
            RCC->CFGR = LOC_u32RegValue;

        } else {
            Ret_enuRCC_ErrorStatus = MRCC_enuNOK;
        }
        break;
    }


	case SYSCLK_PLL: {
        if ((RCC->CR & PLL_ON_MASK) == PLL_ON_MASK) {
            LOC_u32RegValue = RCC->CFGR;
            LOC_u32RegValue &= ~(SYSCLK_MASK);
            LOC_u32RegValue |= Copy_u8SYSCLK;
            RCC->CFGR = LOC_u32RegValue;
        } else {
            Ret_enuRCC_ErrorStatus = MRCC_enuNOK;
        }
        break;
    }  
}

return Ret_enuRCC_ErrorStatus;
}



MRCC_enuErrorStatus_t MRCC_EnablePeripheral (Peripherals_t  Copy_u8Peripheral)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;

	switch ( Copy_u8Peripheral)
	{
	//AHB1 BUS
	case MRCC_GPIOA  :  RCC -> AHB1ENR |= (1<<GPIOAEN) ;break;
	case MRCC_GPIOB  :  RCC -> AHB1ENR |= (1<<GPIOBEN) ;break;
	case MRCC_GPIOC  :  RCC -> AHB1ENR |= (1<<GPIOCEN) ;break;
	case MRCC_GPIOD  :  RCC -> AHB1ENR |= (1<<GPIODEN) ;break;
	case MRCC_GPIOE  :  RCC -> AHB1ENR |= (1<<GPIOEEN) ;break;
	case MRCC_GPIOH  :  RCC -> AHB1ENR |= (1<<GPIOHEN) ;break;
	case MRCC_CRC    :  RCC -> AHB1ENR |= (1<<CRCEN)   ;break;
	case MRCC_DMA1   :  RCC -> AHB1ENR |= (1<<DMA1EN)  ;break;
	case MRCC_DMA2   :  RCC -> AHB1ENR |= (1<<DMA2EN)  ;break;

	//AHB2 BUS
	case MRCC_USB_OTGFS:  RCC -> AHB2ENR |=(1<<OTGFSEN);break;

	//APB1 BUS

	case MRCC_TIM2   :   RCC -> APB1ENR |=(1<<TIM2EN)  ;break;
	case MRCC_TIM3   :   RCC -> APB1ENR |=(1<<TIM3EN)  ;break;
	case MRCC_TIM4   :   RCC -> APB1ENR |=(1<<TIM4EN)  ;break;
	case MRCC_TIM5   :   RCC -> APB1ENR |=(1<<TIM5EN)  ;break;
	case MRCC_WWDG   :   RCC -> APB1ENR |=(1<<WWDGEN)  ;break;
	case MRCC_SPI2   :   RCC -> APB1ENR |=(1<<SPI2EN)  ;break;
	case MRCC_SPI3   :   RCC -> APB1ENR |=(1<<SPI3EN)  ;break;
	case MRCC_USART2 :   RCC -> APB1ENR |=(1<<USART2EN);break;
	case MRCC_I2C1   :   RCC -> APB1ENR |=(1<<I2C1EN)  ;break;
	case MRCC_I2C2   :   RCC -> APB1ENR |=(1<<I2C2EN)  ;break;
	case MRCC_I2C3   :   RCC -> APB1ENR |=(1<<I2C3EN)  ;break;
	case MRCC_PWR    :   RCC -> APB1ENR |=(1<<PWREN)   ;break;

	//APB2 BUS

	case MRCC_TIM1   :   RCC -> APB2ENR |=(1<<TIM1EN)  ;break;
	case MRCC_USART1 :   RCC -> APB2ENR |=(1<<USART1EN);break;
	case MRCC_USART6 :   RCC -> APB2ENR |=(1<<USART6EN);break;
	case MRCC_ADC1   :   RCC -> APB2ENR |=(1<<ADC1EN)  ;break;
	case MRCC_SDIO   :   RCC -> APB2ENR |=(1<<SDIOEN)  ;break;
	case MRCC_SPI4   :   RCC -> APB2ENR |=(1<<SPI4EN)  ;break;
	case MRCC_SPI1   :   RCC -> APB2ENR |=(1<<SPI1EN)  ;break;
	case MRCC_SYSCFG:    RCC -> APB2ENR |=(1<<SYSCFGEN);break;
	case MRCC_TIM9   :   RCC -> APB2ENR |=(1<<TIM9EN)  ;break;
	case MRCC_TIM10  :   RCC -> APB2ENR |=(1<<TIM10EN) ;break;
	case MRCC_TIM11  :   RCC -> APB2ENR |=(1<<TIM11EN) ;break;

	default :  Ret_enuRCC_ErrorStatus = MRCC_enuNOK   ;break;
	}
	return Ret_enuRCC_ErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_DisablePeripheral(Peripherals_t Copy_u8Peripheral)
{
    MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;

    switch (Copy_u8Peripheral)
    {
        // AHB1 BUS
        case MRCC_GPIOA  :  RCC->AHB1ENR &= ~(1 << GPIOAEN) ; break;
        case MRCC_GPIOB  :  RCC->AHB1ENR &= ~(1 << GPIOBEN) ; break;
        case MRCC_GPIOC  :  RCC->AHB1ENR &= ~(1 << GPIOCEN) ; break;
        case MRCC_GPIOD  :  RCC->AHB1ENR &= ~(1 << GPIODEN) ; break;
        case MRCC_GPIOE  :  RCC->AHB1ENR &= ~(1 << GPIOEEN) ; break;
        case MRCC_GPIOH  :  RCC->AHB1ENR &= ~(1 << GPIOHEN) ; break;
        case MRCC_CRC    :  RCC->AHB1ENR &= ~(1 << CRCEN)   ; break;
        case MRCC_DMA1   :  RCC->AHB1ENR &= ~(1 << DMA1EN)  ; break;
        case MRCC_DMA2   :  RCC->AHB1ENR &= ~(1 << DMA2EN)  ; break;

        // AHB2 BUS
        case MRCC_USB_OTGFS:  RCC->AHB2ENR &= ~(1 << OTGFSEN); break;

        // APB1 BUS
        case MRCC_TIM2   :   RCC->APB1ENR &= ~(1 << TIM2EN)  ;  break;
        case MRCC_TIM3   :   RCC->APB1ENR &= ~(1 << TIM3EN)  ;  break;
        case MRCC_TIM4   :   RCC->APB1ENR &= ~(1 << TIM4EN)  ;  break;
        case MRCC_TIM5   :   RCC->APB1ENR &= ~(1 << TIM5EN)  ;  break;
        case MRCC_WWDG   :   RCC->APB1ENR &= ~(1 << WWDGEN)  ;  break;
        case MRCC_SPI2   :   RCC->APB1ENR &= ~(1 << SPI2EN)  ;  break;
        case MRCC_SPI3   :   RCC->APB1ENR &= ~(1 << SPI3EN)  ;  break;
        case MRCC_USART2 :   RCC->APB1ENR &= ~(1 << USART2EN);  break;
        case MRCC_I2C1   :   RCC->APB1ENR &= ~(1 << I2C1EN)  ;  break;
        case MRCC_I2C2   :   RCC->APB1ENR &= ~(1 << I2C2EN)  ;  break;
        case MRCC_I2C3   :   RCC->APB1ENR &= ~(1 << I2C3EN)  ;  break;
        case MRCC_PWR    :   RCC->APB1ENR &= ~(1 << PWREN)   ;  break;

        // APB2 BUS
        case MRCC_TIM1   :   RCC->APB2ENR &= ~(1 << TIM1EN)  ;  break;
        case MRCC_USART1 :   RCC->APB2ENR &= ~(1 << USART1EN);  break;
        case MRCC_USART6 :   RCC->APB2ENR &= ~(1 << USART6EN);  break;
        case MRCC_ADC1   :   RCC->APB2ENR &= ~(1 << ADC1EN)  ;  break;
        case MRCC_SDIO   :   RCC->APB2ENR &= ~(1 << SDIOEN)  ;  break;
        case MRCC_SPI4   :   RCC->APB2ENR &= ~(1 << SPI4EN)  ;  break;
        case MRCC_SPI1   :   RCC->APB2ENR &= ~(1 << SPI1EN)  ;  break;
        case MRCC_SYSCFG :   RCC->APB2ENR &= ~(1 << SYSCFGEN);  break;
        case MRCC_TIM9   :   RCC->APB2ENR &= ~(1 << TIM9EN)  ;  break;
        case MRCC_TIM10  :   RCC->APB2ENR &= ~(1 << TIM10EN) ;  break;
        case MRCC_TIM11  :   RCC->APB2ENR &= ~(1 << TIM11EN) ;  break;

        default :  Ret_enuRCC_ErrorStatus = MRCC_enuNOK     ;  break;
    }
    return Ret_enuRCC_ErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_ConfigureAHPPrescaller  (AHP_PRESCALLERS Copy_enmPrescaller)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
	u32 LOC_u32RegValue=0;
	
	   LOC_u32RegValue = RCC->CFGR;
	   LOC_u32RegValue &=AHP_PRESCALLER_CLEARMASK;
	   LOC_u32RegValue |=Copy_enmPrescaller;
	   RCC->CFGR = LOC_u32RegValue;

	return Ret_enuRCC_ErrorStatus;

}
MRCC_enuErrorStatus_t MRCC_ConfigureAPB1Prescaller (APB1_PRESCALLERS Copy_enmPrescaller)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
		   u32 LOC_u32RegValue=0;

		   LOC_u32RegValue = RCC->CFGR;
		   LOC_u32RegValue &=APB1_PRESCALLER_CLEARMASK;
		   LOC_u32RegValue |=Copy_enmPrescaller;
		   RCC->CFGR = LOC_u32RegValue;

		return Ret_enuRCC_ErrorStatus;

}

MRCC_enuErrorStatus_t MRCC_ConfigureAPB2Prescaller (APB2_PRESCALLERS  Copy_enmPrescaller)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
			   u32 LOC_u32RegValue=0;

			   LOC_u32RegValue = RCC->CFGR;
			   LOC_u32RegValue &=APB2_PRESCALLER_CLEARMASK;
			   LOC_u32RegValue |=Copy_enmPrescaller;
			   RCC->CFGR = LOC_u32RegValue;

			return Ret_enuRCC_ErrorStatus;

}

MRCC_enuErrorStatus_t MRCC_enuReadSysClock(u8* Add_pu8SysClockStatus)
{
   MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
   
   if(((RCC->CFGR & STATUS_HSI_MASK)==STATUS_HSI_MASK))
   {
	*Add_pu8SysClockStatus= SYSCLK_HSI;
   }
   else if(((RCC->CFGR & STATUS_HSE_MASK)==STATUS_HSE_MASK))
   {
	*Add_pu8SysClockStatus= SYSCLK_HSE;
   }
   else if(((RCC->CFGR & STATUS_PLL_MASK)==STATUS_PLL_MASK))
   {
	*Add_pu8SysClockStatus= SYSCLK_PLL;
   }
   else
   {
	 Ret_enuRCC_ErrorStatus = MRCC_enuNOK;
   }

   return  Ret_enuRCC_ErrorStatus;

}

MRCC_enuErrorStatus_t MRCC_SetPllClkSrc(PLLClockSource_t RCC_PLLClkSrc)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
	if( (RCC_PLLClkSrc != PLLCLK_HSI) && (RCC_PLLClkSrc != PLLCLK_HSE))
	{
		Ret_enuRCC_ErrorStatus= MRCC_enuInvalidPLL_CLKSRC;
	}
	else
	{
		/*Do Nothing*/
	}
	if(Ret_enuRCC_ErrorStatus==  MRCC_enuOK)
	{
		RCC -> PLLCFGR |= RCC_PLLClkSrc;
	}
	else
	{
	   /*Do Nothing*/
	}
	return Ret_enuRCC_ErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_ConfigurePLLCLK(u32 Copy_u32NValue ,u32 Copy_u32MValue,u32 Copy_u32PValue,u32 Copy_u32QValue)
{
	MRCC_enuErrorStatus_t Ret_enuRCC_ErrorStatus = MRCC_enuOK;
	u32 LOC_u32RegValue=0;

	if(Copy_u32NValue >= 432 || Copy_u32NValue <= 192 )
	{
		Ret_enuRCC_ErrorStatus = MRCC_enuINVALID_N_VALUE_ERROR;
	}
	if(Copy_u32MValue >= 63 || Copy_u32MValue <= 2 )
	{
		Ret_enuRCC_ErrorStatus = MRCC_enuINVALID_M_VALUE_ERROR;
	}
	if(Copy_u32QValue >= 15 || Copy_u32QValue <= 2 )
	{
		Ret_enuRCC_ErrorStatus = MRCC_enuINVALID_Q_VALUE_ERROR;
	}
	if(Copy_u32PValue != 2 || Copy_u32PValue != 4 || Copy_u32PValue != 6 || Copy_u32PValue != 8)
	{
		Ret_enuRCC_ErrorStatus = MRCC_enuINVALID_P_VALUE_ERROR;
	}
   
if (Ret_enuRCC_ErrorStatus == MRCC_enuOK)
{
    
			  
		       LOC_u32RegValue = RCC->PLLCFGR;
			   LOC_u32RegValue &= ~ (PLL_PRESCALLER_MASK);
			   LOC_u32RegValue |=(Copy_u32NValue << PLL_N) | (Copy_u32MValue << PLL_M) | (Copy_u32PValue << PLL_P) | (Copy_u32QValue << PLL_Q) ;
			   RCC->PLLCFGR = LOC_u32RegValue;			   
}
}

