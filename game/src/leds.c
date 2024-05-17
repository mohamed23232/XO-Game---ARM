// Including necessary header files
#include "..\./headers/tm4c123gh6pm.h"
#include "..\./headers/Nokia5110.h"
#include "..\./headers/TExaS.h"
#include "..\./headers/leds.h"
#include "..\./headers/timers.h"
#include "..\\./headers/xo.h"
#include "..\\./headers/operations.h"
#include "..\\./headers/screens.h"

// Declaring external variables used in other parts of the program
extern int time, flag;

/*
  X = PB2     0x04
  O = PB3     0x08
  D = PB7     0x80
*/

// Function to set LED for X
void setLED_X(void)
{
    // Setting bit 2 (X) of GPIO port B high
    GPIO_PORTB_DATA_R |= 0x04;
    // Clearing bit 3 (O) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x08);
    // Clearing bit 7 (D) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x80);
}

// Function to set LED for O
void setLED_O(void)
{
    // Clearing bit 2 (X) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x04);
    // Setting bit 3 (O) of GPIO port B high
    GPIO_PORTB_DATA_R |= 0x08;
    // Clearing bit 7 (D) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x80);
}

// Function to set LED for D
void setLED_D(void)
{
    // Clearing bit 2 (X) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x04);
    // Clearing bit 3 (O) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x08);
    // Setting bit 7 (D) of GPIO port B high
    GPIO_PORTB_DATA_R |= 0x80;
}

// Function to clear all LEDs
void clearLEDS(void)
{
    // Clearing bit 2 (X) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x04);
    // Clearing bit 3 (O) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x08);
    // Clearing bit 7 (D) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x80);
}

// Function to clear only the LED for D
void clearLED_D(void)
{
    // Clearing bit 7 (D) of GPIO port B
    GPIO_PORTB_DATA_R &= ~(0x80);
}

// Function to indicate an error condition with LED blinking and optional buzzer sound
void error(void)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        // Turn on the D LED
        setLED_D();
        // Wait for 100ms
        Delay100ms(1);
        // Turn off the D LED
        clearLED_D();
        // Wait for 100ms
        Delay100ms(1);
    }
    // If flag is set, play a sound or perform an action
    if (flag == 1)
    {
        play_on_timer();
        // Delay for 1 second
        Delay100ms(10);
        // Reset the flag
        flag = 0;
    }
    // Additional error handling such as buzzer can be added here
}

