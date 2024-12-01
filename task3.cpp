#include <iostream>
#include <vector>

using namespace std;

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}
bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Column check
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There is still an empty spot
            }
        }
    }
    return true; // No empty spots, must be a draw
}
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move. Try again.\n";
        return false;
    }
    board[row][col] = player;
    return true;
}
void playGame() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);
    char currentPlayer = 'X'; // Start with player 'X'
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column: 0, 1, 2): ";
        cin >> row >> col;
        if (makeMove(board, row, col, currentPlayer)) {
            gameWon = checkWin(board, currentPlayer);
            
            gameDraw = checkDraw(board);

            if (!gameWon && !gameDraw) {
                // Switch player turns
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    displayBoard(board);

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }
}
int main() {
    bool playAgain = true;
    while (playAgain) {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        char response;
        cin >> response;
        playAgain = (response == 'y' || response == 'Y');
    }

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
