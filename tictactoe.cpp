// Include the necessary libraries
#include <iostream>
#include <cstdlib>
using namespace std;

// Define the board size and the symbols for the players
const int SIZE = 3;
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';

// Declare the functions for the game logic
void displayBoard(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], char turn);
bool isFull(char board[SIZE][SIZE]);
bool isWin(char board[SIZE][SIZE], char turn);
char switchTurn(char turn);

// The main function
int main()
{
    // Initialize the board with empty spaces
    char board[SIZE][SIZE] = {{EMPTY, EMPTY, EMPTY},
                              {EMPTY, EMPTY, EMPTY},
                              {EMPTY, EMPTY, EMPTY}};

    // Initialize the turn to X
    char turn = X;

    // Display the board
    displayBoard(board);

    // Loop until the board is full or someone wins
    while (!isFull(board) && !isWin(board, turn))
    {
        // Ask the current player to make a move
        makeMove(board, turn);

        // Display the board
        displayBoard(board);

        // Switch the turn to the other player
        turn = switchTurn(turn);
    }

    // Check the game result
    if (isWin(board, switchTurn(turn)))
    {
        // The previous player won
        cout << "Player " << switchTurn(turn) << " wins!\n";
    }
    else
    {
        // The board is full and no one wins
        cout << "It's a tie!\n";
    }

    // Exit the program
    return 0;
}

// The function to display the board
void displayBoard(char board[SIZE][SIZE])
{
    // Loop through the rows
    for (int i = 0; i < SIZE; i++)
    {
        // Loop through the columns
        for (int j = 0; j < SIZE; j++)
        {
            // Print the board element
            cout << board[i][j];

            // Print a vertical line if not the last column
            if (j < SIZE - 1)
            {
                cout << "|";
            }
        }

        // Print a newline
        cout << "\n";

        // Print a horizontal line if not the last row
        if (i < SIZE - 1)
        {
            cout << "-+-+-\n";
        }
    }

    // Print a newline
    cout << "\n";
}

// The function to make a move
void makeMove(char board[SIZE][SIZE], char turn)
{
    // Declare the variables for the row and column
    int row, col;

    // Loop until a valid move is made
    while (true)
    {
        // Ask the player to enter the row and column
        cout << "Player " << turn << ", enter the row and column (1-3) separated by a space: ";
        cin >> row >> col;

        // Adjust the row and column to start from 0
        row--;
        col--;

        // Check if the row and column are valid
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
        {
            // Check if the board element is empty
            if (board[row][col] == EMPTY)
            {
                // Place the turn symbol on the board
                board[row][col] = turn;

                // Break out of the loop
                break;
            }
            else
            {
                // The board element is already occupied
                cout << "That position is already taken. Try again.\n";
            }
        }
        else
        {
            // The row and column are out of range
            cout << "Invalid input. Try again.\n";
        }
    }
}

// The function to check if the board is full
bool isFull(char board[SIZE][SIZE])
{
    // Loop through the board elements
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Check if any element is empty
            if (board[i][j] == EMPTY)
            {
                // Return false
                return false;
            }
        }
    }

    // Return true
    return true;
}

// The function to check if someone wins
bool isWin(char board[SIZE][SIZE], char turn)
{
    // Check the rows
    for (int i = 0; i < SIZE; i++)
    {
        // Initialize a counter
        int count = 0;

        // Loop through the columns
        for (int j = 0; j < SIZE; j++)
        {
            // Check if the board element matches the turn
            if (board[i][j] == turn)
            {
                // Increment the counter
                count++;
            }
        }

        // Check if the counter equals the size
        if (count == SIZE)
        {
            // Return true
            return true;
        }
    }

    // Check the columns
    for (int j = 0; j < SIZE; j++)
    {
        // Initialize a counter
        int count = 0;

        // Loop through the rows
        for (int i = 0; i < SIZE; i++)
        {
            // Check if the board element matches the turn
            if (board[i][j] == turn)
            {
                // Increment the counter
                count++;
            }
        }

        // Check if the counter equals the size
        if (count == SIZE)
        {
            // Return true
            return true;
        }
    }

    // Check the main diagonal
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        // Check if the board element matches the turn
        if (board[i][i] == turn)
        {
            // Increment the counter
            count++;
        }
    }

    // Check if the counter equals the size
    if (count == SIZE)
    {
        // Return true
        return true;
    }

    // Check the secondary diagonal
    count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        // Check if the board element matches the turn
        if (board[i][SIZE - i - 1] == turn)
        {
            // Increment the counter
            count++;
        }
    }

    // Check if the counter equals the size
    if (count == SIZE)
    {
        // Return true
        return true;
    }

    // Return false
    return false;
}

// The function to switch the turn
char switchTurn(char turn)
{
    // Check if the turn is X
    if (turn == X)
    {
        // Return O
        return O;
    }
    else
    {
        // Return X
        return X;
    }
}
