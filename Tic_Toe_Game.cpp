#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>> &board);
void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char player, int row, int col);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' '));

    do {
        initializeBoard(board);
        bool gameWon = false;
        bool gameDraw = false;

        do {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                gameWon = checkWin(board, currentPlayer);
                gameDraw = checkDraw(board);
                currentPlayer = switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move! Try again." << endl;
            }

        } while (!gameWon && !gameDraw);

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

    } while (playAgain());

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(vector<vector<char>> &board, char player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }

    board[row][col] = player;
    return true;
}

bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // Game is not a draw
            }
        }
    }
    return true;  // Game is a draw
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
