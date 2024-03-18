#include "HAL/HLED/HLED_interface.h"
#include "LIB/STD_TYPES.h"

#define PERIODICITY_SEC 1

#define GREEN  0
#define YELLOW 1
#define RED    2
void TrraficLight(void);
static u8 prev = 0;
static u8 STATE = GREEN; // Maintain the state across function calls

void GREEN_LED_ACTIVATE(void) {
    HLED_vSetLedStatus(Led_GREEN, LED_STATUS_ON);
    HLED_vSetLedStatus(Led_RED, LED_STATUS_OFF);
    HLED_vSetLedStatus(Led_YELLOW, LED_STATUS_OFF);
}

void YELLOW_LED_ACTIVATE(void) {
    HLED_vSetLedStatus(Led_YELLOW, LED_STATUS_ON);
    HLED_vSetLedStatus(Led_GREEN, LED_STATUS_OFF);
    HLED_vSetLedStatus(Led_RED, LED_STATUS_OFF);
}

void RED_LED_ACTIVATE(void) {
    HLED_vSetLedStatus(Led_RED, LED_STATUS_ON);
    HLED_vSetLedStatus(Led_GREEN, LED_STATUS_OFF);
    HLED_vSetLedStatus(Led_YELLOW, LED_STATUS_OFF);
}

void TrraficLight(void) {
    static u32 seconds = 0;
    seconds += PERIODICITY_SEC;

    switch (STATE) {
        case GREEN:
            GREEN_LED_ACTIVATE();
            if (seconds == 10) {
                seconds = 0;
                STATE = YELLOW;
                prev = GREEN;
            }
            break;
        case YELLOW:
            YELLOW_LED_ACTIVATE();
            if ((seconds == 6) && (prev == GREEN)) {
                seconds = 0;
                STATE = RED;
                prev = YELLOW;
            } else if ((seconds == 6) && (prev == RED)) {
                seconds = 0;
                STATE = GREEN;
                prev = YELLOW;
            }
            break;
        case RED:
            RED_LED_ACTIVATE();
            if (seconds == 15) {
                seconds = 0;
                STATE = YELLOW;
                prev = RED;
            }
            break;
        default:
            break;
    }
}
