#include <iostream>
using namespace std;

const int SIZE = 3;

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--" << endl;
    }
}

bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    while (true) {
        char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            printBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter the row (0, 1, 2): ";
            cin >> row;
            cout << "Player " << currentPlayer << ", enter the column (0, 1, 2): ";
            cin >> col;

            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayer(currentPlayer);
            }
        }

        string playAgain;
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;
        if (playAgain != "yes") {
            break;
        }
    }

    return 0;
}
