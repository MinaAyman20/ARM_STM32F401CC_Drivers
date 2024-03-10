#ifndef D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_STMF401CCPERIPHERALS_INT_ID_H_
#define D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_STMF401CCPERIPHERALS_INT_ID_H_

/**
 * @brief Enumeration of Interrupt Request (IRQ) types.
 * 
 * This enumeration defines the various interrupt types supported by the system,
 * along with their associated interrupt numbers. Negative values are used for 
 * system interrupts, while positive values are reserved for peripheral interrupts.
 * The enumeration also includes reserved interrupts.
 */
typedef enum {
    PEND_SV_IRQ = -6,               // PendSV Interrupt
    SYSTICK_IRQ = -5,               // SysTick Interrupt
    SV_CALL_IRQ = -4,               // SVCall Interrupt
    MEMORY_MANAGE_IRQ = -3,         // Memory Management Fault Interrupt
    BUS_FAULT_IRQ = -2,             // Bus Fault Interrupt
    USAGE_FAULT_IRQ = -1,           // Usage Fault Interrupt
    WWDG_IRQ ,                      // Window Watchdog Interrupt
    EXTI16_IRQ ,                    // EXTI Line 16 Interrupt
    EXTI21_IRQ ,                    // EXTI Line 21 Interrupt
    EXTI22_IRQ ,                    // EXTI Line 22 Interrupt
    FLASH_IRQ,                      // Flash global Interrupt
    RCC_IRQ ,                       // RCC global Interrupt
    EXTI0_IRQ ,                     // EXTI Line0 Interrupt
    EXTI1_IRQ ,                     // EXTI Line1 Interrupt
    EXTI2_IRQ ,                     // EXTI Line2 Interrupt
    EXTI3_IRQ ,                     // EXTI Line3 Interrupt
    EXTI4_IRQ ,                     // EXTI Line4 Interrupt
    DMA1_STREAM0_IRQ ,              // DMA1 Stream0 global Interrupt
    DMA1_STREAM1_IRQ ,              // DMA1 Stream1 global Interrupt
    DMA1_STREAM2_IRQ ,              // DMA1 Stream2 global Interrupt
    DMA1_STREAM3_IRQ,               // DMA1 Stream3 global Interrupt
    DMA1_STREAM4_IRQ ,              // DMA1 Stream4 global Interrupt
    DMA1_STREAM5_IRQ ,              // DMA1 Stream5 global Interrupt
    DMA1_STREAM6_IRQ ,              // DMA1 Stream6 global Interrupt
    ADC_IRQ ,                       // ADC1, ADC2 and ADC3 global Interrupts
    RESERVED1,                      // Reserved Interrupt
    RESERVED2,                      // Reserved Interrupt
    RESERVED3,                      // Reserved Interrupt
    RESERVED4,                      // Reserved Interrupt
    EXTI9_IRQ ,                     // External Line[9:5] Interrupts
    TIM1_BRK_TIM9_IRQ ,             // TIM1 Break interrupt and TIM9 global interrupt
    TIM1_UP_TIM10_IRQ ,             // TIM1 Update Interrupt and TIM10 global interrupt
    TIM1_TRG_COM_TIM11_IRQ ,        // TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt
    TIM1_CC_IRQ,                    // TIM1 Capture Compare Interrupt
    TIM2_IRQ,                       // TIM2 global Interrupt
    TIM3_IRQ ,                      // TIM3 global Interrupt
    TIM4_IRQ ,                      // TIM4 global Interrupt
    I2C1_EV_IRQ ,                   // I2C1 Event Interrupt
    I2C1_ER_IRQ ,                   // I2C1 Error Interrupt
    I2C2_EV_IRQ ,                   // I2C2 Event Interrupt
    I2C2_ER_IRQ ,                   // I2C2 Error Interrupt
    SPI1_IRQ ,                      // SPI1 global Interrupt
    SPI2_IRQ ,                      // SPI2 global Interrupt
    USART1_IRQ,                     // USART1 global Interrupt
    USART2_IRQ ,                    // USART2 global Interrupt
    RESERVED5,                      // Reserved Interrupt
    EXTI15_10_IRQ ,                 // External Line[15:10] Interrupts
    EXTI17_IRQ ,                    // EXTI Line 17 Interrupt
    EXTI18_IRQ,                     // EXTI Line 18 Interrupt
    RESERVED6,                      // Reserved Interrupt
    RESERVED7,                      // Reserved Interrupt
    RESERVED8,                      // Reserved Interrupt
    RESERVED9,                      // Reserved Interrupt
    DMA1_STREAM7_IRQ ,              // DMA1 Stream7 global Interrupt
    RESERVED10,                     // Reserved Interrupt
    SDIO_IRQ ,                      // SDIO global Interrupt
    TIM5_IRQ ,                      // TIM5 global Interrupt
    SPI3_IRQ,                       // SPI3 global Interrupt
    RESERVED11,                     // Reserved Interrupt
    RESERVED12,                     // Reserved Interrupt
    RESERVED13,                     // Reserved Interrupt
    RESERVED14,                     // Reserved Interrupt
    DMA2_STREAM0_IRQ ,              // DMA2 Stream0 global Interrupt
    DMA2_STREAM1_IRQ,               // DMA2 Stream1 global Interrupt
    DMA2_STREAM2_IRQ ,              // DMA2 Stream2 global Interrupt
    DMA2_STREAM3_IRQ ,              // DMA2 Stream3 global Interrupt
    DMA2_STREAM4_IRQ ,              // DMA2 Stream4 global Interrupt
    RESERVED15,                     // Reserved Interrupt
    RESERVED16,                     // Reserved Interrupt
    RESERVED17,                     // Reserved Interrupt
    RESERVED18,                     // Reserved Interrupt
    RESERVED19,                     // Reserved Interrupt
    RESERVED20,                     // Reserved Interrupt
    OTG_FS_IRQ ,                    // USB On The Go FS global Interrupt
    DMA2_STREAM5_IRQ,               // DMA2 Stream5 global Interrupt
    DMA2_STREAM6_IRQ ,              // DMA2 Stream6 global Interrupt
    DMA2_STREAM7_IRQ ,              // DMA2 Stream7 global Interrupt
    USART6_IRQ ,                    // USART6 global Interrupt
    I2C3_EV_IRQ ,                   // I2C3 event interrupt
    I2C3_ER_IRQ ,                   // I2C3 error interrupt
    RESERVED21,                     // Reserved Interrupt
    RESERVED22,                     // Reserved Interrupt
    RESERVED23,                     // Reserved Interrupt
    RESERVED24,                     // Reserved Interrupt
    RESERVED25,                     // Reserved Interrupt
    RESERVED26,                     // Reserved Interrupt
    RESERVED27,                     // Reserved Interrupt
    FPU_IRQ ,                       // Floating point unit interrupt
    RESERVED28,                     // Reserved Interrupt
    RESERVED29,                     // Reserved Interrupt
    SPI4_IRQ,                       // SPI4 global Interrupt
    NVIC_NUM_INTERRUPTS             // Total number of interrupts
} IRQ_Type;

#endif // D__PIO_ARM_WS_MCAL_MNVIC_DRIVER_INC_MCAL_MNVIC_STMF401CCPERIPHERALS_INT_ID_H_