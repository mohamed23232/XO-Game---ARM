// Including necessary header files
#include "..\./headers/screens.h"
#include "..\./headers/operations.h"
#include "..\./headers/timers.h"
#include "..\./headers/UART.h"
#include "..\./headers/leds.h"
#include "..\./headers/xo.h"
#include "..\./headers/Nokia5110.h"


// Declaring global variables
extern int arr[3][3], turn,row,col,uart,time,ok,SW1,SW2;


// Function to make a move
void move(void)
{
	if(arr[row][col] == 3) arr[row][col] = 0;
  // Moving to the next empty place
    col = (col + 1) % 3;
    row = (col == 0) ? (row + 1) % 3 : row;
  // Assigning the current position to be selected
  if(arr[row][col]==0)arr[row][col] = 3;
}

// Function to update the game after each move
int update(void)
{
  int w;
	if(arr[row][col]!=3) error();
  // If it's player 1's turn, updating the board with player 1's move
  if(turn == 0 && arr[row][col] == 3)
  {
    arr[row][col] = 1;
		  turn ^= 1;

	}
  // If it's player 2's turn, updating the board with player 2's move
  else if (arr[row][col] == 3 && turn == 1)
  {
    arr[row][col] = 2;
		  turn ^= 1;
	}

  // Checking if there's a winner
  w = checkWinner();

	// if The match is ended
	if(w != 0) 
	{
		startGame(); // Call the function to see how the match ended
		disable_timer(TIMER2); // Disable timer 2
		Delay100ms(10); // Wait for 1 second before announcing the result 
	}

  // Displaying the winner or draw message if there's a winner or if it's a draw
  if(w == 1)
  {
    winner_x();
		if(uart==1)
		UART_OutString(" X WON THE GAME \n");
  }
  else if(w == 2)
  {
    winner_o();
				if(uart==1)

				UART_OutString(" O WON THE GAME \n");

  }
  else if(w == 3)
  {
		
    draw();
				if(uart==1)

				UART_OutString(" DRAW!! \n");

  }

  // Returning 1 if there's a winner, else continuing the game
  if (w != 0) return 1;

  // Getting the first place to be selected and updating the turn
  //getFirst();
  return 0;	
}

// Function to check if there's a winner or if it's a draw
int checkWinner(void)
{
	int i;
  int flag = 1;
    for (i = 0; i < 3; i++) {
        if (arr[i][0]==arr[i][1] &&  arr[i][1]==arr[i][2] && arr[i][0]!=0)
            return arr[i][0];
        if (arr[0][i]==arr[1][i] &&  arr[1][i]==arr[2][i] && arr[0][i]!=0)
            return arr[0][i];
        if (arr[i][0]==0 ||  arr[i][1]==0 || arr[i][2]==0)flag=0;
        if (arr[0][i]==0 ||  arr[1][i]==0 || arr[2][i]==0)flag=0;

    }
    if (arr[0][0] ==arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0]!=0)
        return arr [0][0];
    if (arr[0][2] == arr[1][1] &&  arr[1][1] ==arr[2][0] && arr[0][2]!=0)
        return arr[0][2];
    if(flag)return 3;
    return 0;
}


int check(void){
while (ok)
		{
			if (SW1 && !SW2)
			{
				uart = 0;
				Choise();
	
	// Clearing any switch inputs
	
	clear_switches();
	
	while(1){
		if(SW1 && !SW2){
			uart =1;
			break;
		}else if(!SW1 && SW2){
			uart = 0;
			break;
		}
	}
				init();
				enable_timer(TIMER2);
				turnX();
			}
			else if (SW2 && !SW1)
			{
			//	end_game();
				Nokia5110_Clear();
				return 0;
			}
		}
	return 1;
}

void xo_play(void){
if (SW2 && !SW1)
		{
			// If SW2 is pressed, indicating a move selection, clear the switches and make a move
			clear_switches();
			move();
			select_turn();
		}
		else if (SW1 && !SW2)
		{
			// If SW1 is pressed, indicating a turn change or timer expiration, perform necessary actions
			clear_switches();
			reset_timer(TIMER2);

			time = 1;

			// If a player has won or the game has tied, display the play again option and set ok to true to wait for restart or quit
			if (update())
			{
				Delay100ms(30);
				play_again();
				clear_switches();
				ok = 1;
			}

			// If the game is still ongoing, switch turns
			else
			{
				select_turn();
			}
			
		}

}

void Uart_play(void){
if(uart==1){
			unsigned char n;
		if(ok){

					UART_OutString(" A-> Exit  X-> play again: ");
		}
			else{
			if(turn ==0) 		UART_OutString("X's turn:..... \n");
			else UART_OutString("O's turn:..... \n");
			UART_OutString(" A-> Move  X-> Play: ");
			}
		
						UART_OutString("\n");

			n = UART_InChar();
			
   		UART_OutChar(n);

		UART_OutString("\n\r");
		
			switch(n){
			case 'a':
				SW1=0;
				SW2=1;
			break;
			case 'x':
				SW2=0;
				SW1=1;
			break;	
		}
		}
}
// Function to initialize game state

void init(void)
{
	int i, j;

	// Initializing every element in the game board array as 0
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr[i][j] = 0;
		}
	}

	// Setting initial row,column, turn, and switch values
	row = 0;
	col = 0;
	turn = 0;
	SW1 = 0;
	SW2 = 0;
	ok = 0;
	time = 1;

	// Setting the center element of the board as 3 to indicate it is unavailable for moves
	arr[0][0] = 3;
}
// Function to switch turns between X and O

void select_turn(void)
{
	if(turn)
		turnO();
	else
		turnX();
}

// Function to clear any switch inputs
void clear_switches(void)
{
	SW1 = 0;
	SW2 = 0;
}
