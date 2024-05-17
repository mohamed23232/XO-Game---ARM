// Including necessary header files
#include "./headers/Nokia5110.h"   // Header file for Nokia 5110 display functions
#include "./headers/TExaS.h"       // Header file for TExaS scope
#include "./headers/timers.h"      // Header file for timer functions
#include "./headers/ports.h"       // Header file for port functions
#include "./headers/screens.h"     // Header file for screen display functions
#include "./headers/operations.h"  // Header file for game operations
#include "./headers/leds.h"        // Header file for LED control
#include "./headers/xo.h"          // Header file for tic-tac-toe game logic
#include "./headers/UART.h"        // Header file for UART communication

// Initializing the game board as a 2D array of integers
int arr[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// Initializing variables used in the game
int time = 1, turn = 0, ok = 0, row, col, uart = 0;
unsigned long SW1, SW2;

int main(void)
{
    // Initializing necessary hardware and software components for the game to function
    PORT_init(&portCfg, GPIO_PORT_B);  // Initialize port B
    UART_Init();                       // Initialize UART
    EnableInterrupts();                // Enable interrupts
    TExaS_Init(SSI0_Real_Nokia5110_Scope); // Initialize TExaS scope for Nokia 5110 display
    Nokia5110_Init();                  // Initialize Nokia 5110 display

    // Setting up LED display and displaying splash screen
    
    splashScreen();                    // Display splash screen (Start Game)
    Delay100ms(20);                    // Wait for 2 seconds
    Choise();                          // Display game choice screen (uart-sws)
    
    // Clearing any switch inputs
    clear_switches();                  // Clear any previous switch inputs
    
    while(1){
        if(SW1 && !SW2){
            uart = 1;                  // If SW1 is pressed, set UART mode
            break;
        } else if(!SW1 && SW2){
            uart = 0;                  // If SW2 is pressed, set Switches mode
            break;
        }
    }
    clear_switches();                  // Clear switch inputs after selection

    // Initializing Timer2 with a frequency of 80 MHz
    TIMER_Init(&TimerCfg, TIMER2, 80000000); // Initialize Timer2 with 80 MHz frequency (1 sec)

    // Setting up initial game state and starting with X's turn
    init();                            // Initialize game state
    turnX();                           // Set the initial turn to player X
    
    while (1)
    {
        Uart_play();                   // Handle UART play if in UART mode
        if(check() == 0) return 0;     // Check if the game has ended, if so, exit
        xo_play();                     // Continue the game play loop
    }
}
