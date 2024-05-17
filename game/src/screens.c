// Including necessary header files
#include "..\./headers/tm4c123gh6pm.h"
#include "..\./headers/Nokia5110.h"
#include "..\./headers/timers.h"
#include "..\./headers/shapes.h"
#include "..\./headers/leds.h"
#include "..\./headers/screens.h"

// Declaring external integer array of size 3x3
extern int arr[3][3];
extern int time, turn;

// Defining macros for square height, vertical line height, and playAgain screen height
#define SQUAREHEIGHT     ((unsigned char)square[22])
#define playAgainH       ((unsigned char)playAgain[22])
#define seeH             ((unsigned char)see[22])
#define TURNXOBOXH       ((unsigned char)turnxbox[22])
#define TURNTIMERBOXH    ((unsigned char)t1[22])
#define XOH              ((unsigned char)xo[22])

/*
  0 empty
  1 x
  2 o
  3 selected
*/

// Function to start the game
void startGame(void)
{
  // Initializing variables
  int i, j, outerY = 15, outerX = 1;

  // Clearing Nokia5110 buffer
  Nokia5110_ClearBuffer();

  // Nested loop to iterate over all elements of array arr
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      unsigned char *tmp;

      // Checking value at current index of array arr
      if(arr[i][j] == 0) tmp = square;
      else if(arr[i][j] == 1) tmp = X;
      else if(arr[i][j] == 2) tmp = O;
      else if(arr[i][j] == 3) tmp = Select;

      // Displaying the corresponding shape at the correct position on Nokia5110 screen
      Nokia5110_PrintBMP(j * SQUAREHEIGHT + outerX, (SQUAREHEIGHT - 1) + (outerY * i) + 2, tmp, 0);
      Nokia5110_DisplayBuffer();

      // Updating X-coordinate for the next shape to be displayed in the same row
      outerX += 1;
    }

    // Resetting X-coordinate and updating Y-coordinate for the next row of shapes to be displayed
    outerX = 1;
  }
}

// Function to display O's turn on Nokia5110 screen
void turnO(void)
{
  startGame();

  // Set LED for O
  setLED_O();

  // Displaying "O" at the correct positions on Nokia5110 screen
  Nokia5110_PrintBMP(84 - TURNXOBOXH, TURNXOBOXH - 1, turnobox, 0);
  Nokia5110_DisplayBuffer();

  // Printing time elapsed since starting the game
  printTime();
}

// Function to display X's turn on Nokia5110 screen
void turnX(void)
{
  startGame();

  // Set LED for X
  setLED_X();

  // Displaying "X" at the correct positions on Nokia5110 screen
  Nokia5110_PrintBMP(84 - TURNXOBOXH, TURNXOBOXH - 1, turnxbox, 0);
  Nokia5110_DisplayBuffer();

  // Printing time elapsed since starting the game
  printTime();
}

// Function to display splash screen on Nokia5110 screen
void splashScreen(void)
{
  Nokia5110_PrintBMP(0, 47, xo, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display play screen on Nokia5110 screen
void play_on_timer(void)
{
  Nokia5110_PrintBMP(0, 47, play, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display choice screen on Nokia5110 screen
void Choise(void)
{
  Nokia5110_PrintBMP(0, 47, uart_sws, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display draw on Nokia5110 screen
void draw(void)
{
  // Set LED for D (Draw)
  setLED_D();

  // Displaying the draw image
  Nokia5110_PrintBMP(0, 47, Draw, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display winner X on Nokia5110 screen
void winner_x(void)
{
  // Set LED for X
  setLED_X();

  // Displaying the winner
  Nokia5110_PrintBMP(0, 47, Winner_x, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display winner O on Nokia5110 screen
void winner_o(void)
{
  // Set LED for O
  setLED_O();

  // Displaying the winner
  Nokia5110_PrintBMP(0, 47, Winner_o, 0);
  Nokia5110_DisplayBuffer();
}

// Function to display play again option on Nokia5110 screen
void play_again(void)
{
  // Set LED for D (Draw)
  setLED_D();

  // Clearing Nokia5110 screen and displaying play again option
  Nokia5110_ClearBuffer();
  Nokia5110_PrintBMP(0, playAgainH - 1, playAgain, 0);
  Nokia5110_DisplayBuffer();
}

// Function to print the current time on the Nokia5110 display
void printTime(void)
{
  switch (time)
  {
    case 1:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t1, 0);
      break;
    case 2:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t2, 0);
      break;
    case 3:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t3, 0);
      break;
    case 4:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t4, 0);
      break;
    case 5:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t5, 0);
      break;
    case 6:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t6, 0);
      break;
    case 7:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t7, 0);
      break;
    case 8:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t8, 0);
      break;
    case 9:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t9, 0);
      break;
    case 10:
      Nokia5110_PrintBMP(84 - TURNTIMERBOXH, 55 - TURNTIMERBOXH, t10, 0);
      break;
  }
  Nokia5110_DisplayBuffer();
}
