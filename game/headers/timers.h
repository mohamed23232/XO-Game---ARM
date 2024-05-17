#include <stdint.h>

// Enum to represent timer enable/disable states
typedef enum Timer_Enable {
    Disable = 0,
    Enable
} Timer_Enable_t;

// Enum to represent return status of timer functions
typedef enum Timer_Ret_e {
    TIMER_RET_OK,
    TIMER_RET_ERROR,
} TIMER_Ret_t;

// Enum to represent different timer numbers
typedef enum Timer_e {
    TIMER0 = 0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
} Timer_t;

// Enum to represent different timer configurations
typedef enum Timer_configuration {
    mode32bit = 0,
    modeRTC,
    mode16_bit,
} Timer_Conf_t;

// Enum to represent different timer types
typedef enum Timer_type {
    type_oneShot = 0,
    type_periodic = 1,
    type_capture = 2,
} Timer_type_t;

// Struct to represent timer configuration ( to get the configuration)
typedef struct Timer_config_s {
    Timer_Conf_t Configuration; // Timer configuration (e.g., 32-bit, 16-bit, RTC)
    Timer_type_t TimerType;     // Timer type (e.g., one-shot, periodic, capture)
    Timer_Enable_t Clear;       // Flag to clear the timer
    Timer_Enable_t Set;         // Flag to set the timer
} Timer_config_t;

// Function prototype for initializing a timer with a given configuration and period
TIMER_Ret_t TIMER_init(Timer_config_t *config, Timer_t TimerNum, unsigned long period);

// External variable for timer configuration
extern Timer_config_t TimerCfg;

// Function prototype to reset the value of a timer
void reset_timer(Timer_t TimerNum);

// Function prototype for the Timer 2 interrupt handler
void Timer2A_Handler(void);

// Function prototype to enable a timer
void enable_timer(Timer_t TimerNum); 

// Function prototype to disable a timer
void disable_timer(Timer_t TimerNum); 

// Function prototype to delay program execution by 100ms * count
void Delay100ms(unsigned long count); 
