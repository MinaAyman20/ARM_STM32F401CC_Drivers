/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/

#include "SERVICES/SCHED/SCHED_interface.h"   // Include the interface for the scheduler module
#include "SERVICES/SCHED/SCHED_config.h"      // Include the configuration for the scheduler module
#include "MCAL/MSYSTICK/MSYSTICK_interface.h" // Include the interface for the system tick module
#include "MCAL/MNVIC/MNVIC_interface.h"


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
// There are no defines in this section

/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/
// There are no types defined in this section

extern const Runnable_t Runnable_List[_Runnables_Num]; // Declaration of an external array of runnable tasks

/********************************************************************************************************/
/************************************************Variables***********************************************/
/********************************************************************************************************/
static volatile u32 PendingTicks = 0; // Declaration of a static volatile variable to keep track of pending system ticks

/********************************************************************************************************/
/*****************************************Static Functions Prototype*************************************/
/********************************************************************************************************/
// There are no static function prototypes in this section
static void SCHED(void);
void Sched_TickCallBack(void);
/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/

/*SCHED_enuErrorStatus SCHED_RegisterRunnable(Runnable_t *Runnable)
{
    //check if Runnable not a Null Pointer and check if the place of Priority is free and there is no Runnable in it 
    if(Runnable && Rinfo[Runnable->Priority].Runnable == NULL)
    {
          Rinfo[Runnable->Priority].Runnable = Runnable;
          Rinfo[Runnable->Priority].RemainingTimeMS = Runnable ->First_DelayMS;
    }

}*/

// Definition of the scheduler function
static void SCHED(void)
{
    u32 idx;
    static u32 TimeStamp = 0; // Static variable to keep track of time

    for (idx = 0; idx < _Runnables_Num; idx++)
    {
        if ((Runnable_List[idx].CB) && ((TimeStamp % Runnable_List[idx].PeriodicityMS) == 0))
        {
            Runnable_List[idx].CB(); // Call the callback function of the runnable task
        }
    }
    TimeStamp += SCHED_TICK_MS; // Increment the timestamp by the scheduler tick time
}

// Callback function for system tick
void Sched_TickCallBack(void)
{
    PendingTicks++; // Increment the pending ticks counter
}

// Initialization function for the scheduler
void SCHED_INIT(void)
{   
    MNVIC_VoidEnablePeripheralInterrupt(SYSTICK_IRQ);
    MSYSTICK_vidInit(); // Initialize the system tick module

    MSYSTICK_enuSetTimeMS(SCHED_TICK_MS); // Set the time interval for system ticks

    MSYSTICK_enuSetCallback(Sched_TickCallBack); // Set the callback function for system ticks
}

// Start function for the scheduler
void SCHED_START(void)
{
    MSYSTICK_enuStart(SYSTICK_PERIODIC); // Start the system tick module in periodic mode

    while (1)
    {
        if (PendingTicks) // If there are pending ticks
        {
            PendingTicks--; // Decrement the pending ticks counter
            SCHED();        // Call the scheduler function
        }
    }
}