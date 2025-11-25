#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, { '4','5','6'}, {'7','8','9'} };
char player = 'X';

void displayBoard() {
    cout << " ";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " ";
        if (i < 2) cout << "\n ---+---+---\n";
    }
    cout << " ";
}

void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void playerMove() {
    int choice;
    cout << "\nPlayer " << player << ", enter your move (1-9): ";
    cin >> choice;
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = player;
    else {
        cout << "Spot already taken! Try again.";
        playerMove();
    }
}

int main() {
    bool gameOver = false;
    while (!gameOver) {
        displayBoard();
        playerMove();

        if (checkWin()) {
            displayBoard();
            cout << "Player " << player << " wins!";
            gameOver = true;
        } 
        else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!";
            gameOver = true;
        } 
        else {
            switchPlayer();
        }
    }
    return 0;
}
