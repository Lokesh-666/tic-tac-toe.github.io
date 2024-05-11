// C++ program to implement tic-tac-toe game in C++

#include <iostream>
using namespace std;

// Function to draw the Tic-Tac-Toe Board
void drawBoard(char board[3][3]){
    cout << "--------------------\n";
    for(int i = 0; i<3; i++){
        cout << "| ";
        for(int j = 0; j<3; j++){
            cout << board[i][j] << " | ";
        }
        cout << "\n--------------------\n";
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) 
{ 
	// Check rows, columns, and diagonals 
	for (int i = 0; i < 3; i++) { 
		if (board[i][0] == player && board[i][1] == player 
			&& board[i][2] == player) 
			return true; // If any row has all same elements, return true
		if (board[0][i] == player && board[1][i] == player 
			&& board[2][i] == player) 
			return true; // If any column has all same elements, return true
	} 
	if (board[0][0] == player && board[1][1] == player 
		&& board[2][2] == player) 
		return true; // If diagonal from top-left to bottom-right has all same elements, return true
	if (board[0][2] == player && board[1][1] == player 
		&& board[2][0] == player) 
		return true; // If diagonal from top-right to bottom-left has all same elements, return true
	return false; // Otherwise, return false
} 

// Main function
int main(){
    // Initialise the board and the players
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player = 'X'; // Player X starts the game
    int row, col;
    int turn; // Variable to keep track of the turns

    cout << "Welcome to Tic-Tac-Toe!\n"; 

    // Game loop
    for(turn = 0; turn < 9; turn++){
        // Draw the board
        drawBoard(board);

        // Prompt for valid input
        while(true){
            cout << "Player " << player << ", enter row (0-2) and column (0-2): "; 
            cin >> row >> col ;
            // Check if the input is valid
            if(board[row][col] == ' ') // If the selected cell is empty
                break; // Valid input, exit the loop
            else {
                cout <<"Invalid input!\n"; 
                continue; // Loop continues to prompt for input
            }
        }

        // Make the move
        board[row][col] = player;

        // Check if the player wins
        if(checkWin(board, player)){
            drawBoard(board);
            cout<<"Player "<<player<<" wins!\n";
            break; // Exit the loop after someone wins
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X'; // Toggle between X and O
    }

    // End of the game
    drawBoard(board);

    // Check for a draw
    if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')){
        cout << "It's a draw!\n";
    }

    return 0;
}
