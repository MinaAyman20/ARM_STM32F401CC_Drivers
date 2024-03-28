#ifndef D__PIO_ARM_WS_SERVICES_SCHED_DRIVER_INC_MCAL_MUSART_MUSART_INTERFACE_H_
#define D__PIO_ARM_WS_SERVICES_SCHED_DRIVER_INC_MCAL_MUSART_MUSART_INTERFACE_H_

/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "MCAL/MUSART/MUSART_priv.h"

/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
#define USART_DISABLE  0
#define USART_ENABLE   1

#define USART_1  0
#define USART_2  1
#define USART_6  2

#define USART_8Bit_WORDLENGTH           0
#define USART_9Bit_WORDLENGTH           1

#define USART_OVER_SAMPLING_16          0
#define USART_OVER_SAMPLING_8           1

#define USART_PARITY_DISABLE            0
#define USART_PARITY_ENABLE             1

#define USART_EVEN_PARITY               0
#define USART_ODD_PARITY                1

#define  USART_STOPBIT_HALF        0x00001000
#define  USART_STOPBIT_ONE         0x00000000
#define  USART_STOPBIT_ONEHALF     0x00003000
#define  USART_STOPBIT_TWO         0x00002000

/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/
typedef enum
{
    MUSART_enuOK                 , // Enumeration for operation success
    MUSART_enuNOK                , // Enumeration for operation failure
    MUSART_enuWRONG_UARTID       ,
    MUSART_enuNULL_POINTER       ,
   
}MUSART_enuErrorStatus;            // Enumeration for error status


/********************************************************************************************************/
/************************************************APIs****************************************************/
/********************************************************************************************************/

void MUSART_enuInit(void);
MUSART_enuErrorStatus MUSART_enuSendByteSync(u32 USART_ID, u8 USART_BYTE);
MUSART_enuErrorStatus MUSART_enuRecieveByteSync(u32 USART_ID, u8* USART_BYTE);
MUSART_enuErrorStatus MUSART_enuSendBufferAsync(u32 USART_ID,u8* USART_BUFFER,u16 LENGTH,TxCB CB);
MUSART_enuErrorStatus MUSART_enuRecieveBufferAsync(u32 USART_ID,u8* USART_BUFFER,u16 LENGTH,RxCB CB);
void MUSART_vTxDone(void);
void MUSART_vIsRx(void);
















#endif 