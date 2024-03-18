#include "SERVICES/SCHED/SCHED_interface.h" //Include the interface for the scheduler module
#include "SERVICES/SCHED/SCHED_config.h"    // Include the configuration for the scheduler module

extern void Runnable_APP1(void);  // Declaration of a function named Runnable_APP1
extern void SW_Runnable(void);     // Declaration of a function named SW_Runnable
extern void Runnable_APP2(void);   // Declaration of a function named Runnable_APP2
extern void TrraficLight(void)  ;  // Declaration of a function named TrraficLight

const Runnable_t Runnable_List[_Runnables_Num] = // Definition of an array of Runnable_t structures
{  
    [LED_APP] = 
    {
        .Name="LED_TOGGLE",
        .PeriodicityMS=1000,
        .CB =&Runnable_APP1,
    },
    [SW_CHECK] =                   // Define a runnable task with the key SW_CHECK
    {
        .Name="SW_CHECK",          // Name of the task
        .PeriodicityMS=10,         // Periodicity of the task in milliseconds
        .CB =&SW_Runnable,         // Callback function associated with the task
    },
    [SW_APP] =                     // Define a runnable task with the key SW_APP
    {
        .Name="SW_APP",            // Name of the task
        .PeriodicityMS=50,         // Periodicity of the task in milliseconds
        .CB =&Runnable_APP2,       // Callback function associated with the task
    },
    [Traffic_APP]=
    {
        .Name="Traffic",            // Name of the task
        .PeriodicityMS=1000,        // Periodicity of the task in milliseconds
        .CB =&TrraficLight,         // Callback function associated with the task
    }
};

 