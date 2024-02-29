#include "src/STD_TYPES.h"
typedef enum{

 MGPIO_enuOK,

 MGPIO_enuNOK,

 MGPIO_enuPortError,

 MGPIO_enuPinError,

 MGPIO_enuOutputTypeError,

 MGPIO_enuSpeedError,

 MGPIO_enuValueError,

 MGPIO_enuWrongConfig

}MGPIO_enuErrorStatus_t;





typedef struct

{

    u32 GPIOPort;

 u32 GPIOPin;

    u32 GPIOMode;

 u32 GPIO_OUTPUTTYPE;

 u32 GPIO_INPUTTYPE;

 u32 GPIOSpeed;



}MGPIO_PIN_config_t;

MGPIO_enuErrorStatus_t MGPIO_enuSetPinConfig (MGPIO_PIN_config_t* Add_strPinConfg);

MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue(u32 Copy_u32Port, u32 Copy_u32Pin, u32 Copy_u32Value);

MGPIO_enuErrorStatus_t MGPIO_getPinValue(u32 Copy_u32Port, u32 Copy_u32Pin, u32 *Copy_pu32Pin);
