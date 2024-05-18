// Including necessary header files
#include "..\\./headers/tm4c123gh6pm.h"  // Header file for TM4C123GH6PM microcontroller definitions
#include "..\\./headers/Nokia5110.h"     // Header file for Nokia 5110 display functions
#include "..\\./headers/timers.h"        // Header file for timer functions
#include "..\\./headers/xo.h"            // Header file for tic-tac-toe game logic

// Declaring external variables from other files
extern int time, turn;                  // Time and turn variables used in the game
extern unsigned long SW1, SW2;          // Switch states
int flag = 0;                           // Flag variable for game logic (play screen)

// Function to initialize a timer with a given period
TIMER_Ret_t TIMER_Init(Timer_config_t *config, Timer_t TimerNum, unsigned long period)
{ 
    unsigned long volatile delay;

    // Enabling Timer clock for the specified timer
    SYSCTL_RCGCTIMER_R |= (1 << TimerNum); 

    // Waiting for timer to stabilize (dummy delay)
    delay = SYSCTL_RCGCTIMER_R;

    switch(TimerNum)
    {
        case 0:
            TIMER0_CTL_R = (1 << config->Clear);  // disable timer
            TIMER0_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER0_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 0 to the given period - 1
            TIMER0_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER0_TAPR_R = 0;  
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER0_ICR_R = 0x00000001;  
            TIMER0_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI4_R = (NVIC_PRI4_R & 0x00FFFFFF) | 0x80000000; 
            // Enabling the interrupt in the NVIC (IRQ 19 for Timer 0A)
            NVIC_EN0_R = 1 << 19;    
            // Enabling Timer 0
            TIMER0_CTL_R = (1 << config->Set);    		
            break;
        case 1:
            TIMER1_CTL_R = (1 << config->Clear);  // disable timer
            TIMER1_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER1_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 1 to the given period - 1
            TIMER1_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER1_TAPR_R = 0;   
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER1_ICR_R = 0x00000001;  
            TIMER1_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI5_R = (NVIC_PRI5_R & 0x00FFFFFF) | 0x80000000; 
            // Enabling the interrupt in the NVIC (IRQ 21 for Timer 1A)
            NVIC_EN0_R = 1 << 21;    
            // Enabling Timer 1
            TIMER1_CTL_R = (1 << config->Set);    
            break;
        case 2:
            TIMER2_CTL_R = (1 << config->Clear);  // disable timer
            TIMER2_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER2_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 2 to the given period - 1
            TIMER2_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER2_TAPR_R = 0;    
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER2_ICR_R = 0x00000001;  
            TIMER2_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI5_R = (NVIC_PRI5_R & 0x00FFFFFF) | 0x80000000; 
            // Enabling the interrupt in the NVIC (IRQ 23 for Timer 2A)
            NVIC_EN0_R = 1 << 23;    
            // Enabling Timer 2
            TIMER2_CTL_R |= (1 << config->Set);    
            break;
        case 3:
            TIMER3_CTL_R = (1 << config->Clear);  // disable timer
            TIMER3_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER3_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 3 to the given period - 1
            TIMER3_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER3_TAPR_R = 0;   
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER3_ICR_R = 0x00000001;  
            TIMER3_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI8_R = (NVIC_PRI8_R & 0x00FFFFFF) | 0x80000000; 
            // Enabling the interrupt in the NVIC (IRQ 35 for Timer 3A)
            NVIC_EN1_R = 1 << 3;    
            // Enabling Timer 3
            TIMER3_CTL_R = (1 << config->Set);    
            break;
        case 4:
            TIMER4_CTL_R = (1 << config->Clear);  // disable timer
            TIMER4_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER4_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 4 to the given period - 1
            TIMER4_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER4_TAPR_R = 0;   
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER4_ICR_R = 0x00000001;  
            TIMER4_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI17_R = (NVIC_PRI17_R & 0xFF00FFFF) | 0x00800000; 
            // Enabling the interrupt in the NVIC (IRQ 70 for Timer 4A)
            NVIC_EN2_R = 1 << 6;    
            // Enabling Timer 4
            TIMER4_CTL_R = (1 << config->Set);    
            break;
        case 5:
            TIMER5_CTL_R = (1 << config->Clear);  // disable timer
            TIMER5_CFG_R |= config->Configuration;  // setting configuration to 32bit
            TIMER5_TAMR_R |= (1 << config->TimerType); // setting the timer to be periodic
            // Setting the load value for Timer 5 to the given period - 1
            TIMER5_TAILR_R = period - 1;  
            // Disabling any prescaler
            TIMER5_TAPR_R = 0;      
            // Clearing any pending interrupt flags and enabling the interrupt
            TIMER5_ICR_R = 0x00000001;  
            TIMER5_IMR_R = 0x00000001;  
            // Setting the interrupt priority to 4 (lower than default)
            NVIC_PRI23_R = (NVIC_PRI23_R & 0xFF00FFFF) | 0x00800000; 
            // Enabling the interrupt in the NVIC (IRQ 92 for Timer 5A)
            NVIC_EN2_R = 1 << 28;    
            // Enabling Timer 5
            TIMER5_CTL_R = (1 << config->Set);    
            break;
    }  
    return TIMER_RET_OK;
}

// Interrupt handler for Timer 2A
void Timer2A_Handler(void)
{ 
    // Acknowledge Timer 2A timeout
    TIMER2_ICR_R = 0x00000001;   

    // Increment time variable
    time++;

    // If time has reached 11, set SW1 to 1 and SW2 to 0 indicating a turn change (play)
    if (time == 11)
    {
        flag = 1;
        SW1 = 1;
        SW2 = 0;
        return;
    }

    // Otherwise, switch turns
    select_turn();
}

// Function to reset the value of a timer
void reset_timer(Timer_t TimerNum)
{
    switch(TimerNum)
    {
        case 0:
            TIMER0_TAV_R = 0; // Reset Timer 0
            break;
        case 1:
            TIMER1_TAV_R = 0; // Reset Timer 1
            break;
        case 2:
            TIMER2_TAV_R = 0; // Reset Timer 2
            break;
        case 3:
            TIMER3_TAV_R = 0; // Reset Timer 3
            break;
        case 4:
            TIMER4_TAV_R = 0; // Reset Timer 4
            break;
        case 5:
            TIMER5_TAV_R = 0; // Reset Timer 5
            break;
    }
}

// Function to enable a timer
void enable_timer(Timer_t TimerNum) 
{
    switch(TimerNum)
    {
        case 0:
            TIMER0_CTL_R = 0x00000001; // Enable Timer 0
            break;
        case 1:
            TIMER1_CTL_R = 0x00000001; // Enable Timer 1
            break;
        case 2:
            TIMER2_CTL_R = 0x00000001; // Enable Timer 2
            break;
        case 3:
            TIMER3_CTL_R = 0x00000001; // Enable Timer 3
            break;
        case 4:
            TIMER4_CTL_R = 0x00000001; // Enable Timer 4
            break;
        case 5:
            TIMER5_CTL_R = 0x00000001; // Enable Timer 5
            break;
    }
}

// Function to disable a timer
void disable_timer(Timer_t TimerNum) 
{
    switch(TimerNum)
    {
        case 0:
            TIMER0_CTL_R &= ~(1 << 0); // Disable Timer 0
            break;
        case 1:
            TIMER1_CTL_R &= ~(1 << 0); // Disable Timer 1
            break;
        case 2:
            TIMER2_CTL_R &= ~(1 << 0); // Disable Timer 2
            break;
        case 3:
            TIMER3_CTL_R &= ~(1 << 0); // Disable Timer 3
            break;
        case 4:
            TIMER4_CTL_R &= ~(1 << 0); // Disable Timer 4
            break;
        case 5:
            TIMER5_CTL_R &= ~(1 << 0); // Disable Timer 5
            break;
    }
}

// Function to delay program execution by 100ms * count
void Delay100ms(unsigned long count)
{
    unsigned long volatile time;
  
    while(count > 0)
    {
        time = 727240; // 0.1sec at 80 MHz
        while(time) time--;
        count--;
    }
}
