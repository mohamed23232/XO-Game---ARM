// Function to get the first available position that can be selected
void getFirst(void);

// Function to make a move in the game
void move(void);

// Function to update the game state after each move
// Returns an integer indicating the status of the update
int update(void);

// Function to check if there's a winner or if the game is a draw
// Returns an integer indicating the game status: win, draw, or ongoing
int checkWinner(void);

// Function to check the overall game status
// Returns an integer indicating the game status
int check(void);

// Function to handle the main gameplay logic for the tic-tac-toe game
void xo_play(void);

// Function to handle the gameplay logic when using UART for communication
void Uart_play(void);

// Function to select the turn of the players
void select_turn(void);

// Function to clear the state of the switches
void clear_switches(void);
