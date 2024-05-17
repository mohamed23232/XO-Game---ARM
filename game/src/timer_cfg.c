#include "..\\./headers/timers.h"

// Timer configuration structure for TimerCfg
Timer_config_t TimerCfg = {
    .Configuration = mode32bit,      // Set the timer mode to 32-bit
    .TimerType = type_periodic + 1,  // Set the timer type to periodic (1)
    .Clear = Disable,                // Disable the clear functionality
    .Set = Enable,                   // Enable the set functionality
};
