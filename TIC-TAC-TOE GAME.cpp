#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    cout << " -------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i+1 << "|";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0]; // Winner found
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i]; // Winner found
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0]; // Winner found
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2]; // Winner found
    }
    // No winner
    return ' ';
}

// Function to check if the board is full (draw)
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board with empty spaces
    char currentPlayer = 'X'; // Player X starts the game
    bool gameEnd = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameEnd) {
        // Display the current board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move! Please try again." << endl;
            continue; // Ask the player to enter their move again
        }

        // Update the board with the player's move
        board[row-1][col-1] = currentPlayer;

        // Check if the current player wins
        char winner = checkWinner(board);
        if (winner != ' ') {
            cout << "Player " << winner << " wins!" << endl;
            gameEnd = true;
        } else if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            gameEnd = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Display the final board
    displayBoard(board);

    // Ask if the players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board and player X starts the new game
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameEnd = false;
        main(); // Start a new game
    }

    return 0;
}

