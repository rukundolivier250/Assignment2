


#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

class Power4Game {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    Power4Game() : board(ROWS, std::vector<char>(COLS, ' ')), currentPlayer('X') {}

    void printBoard() {
        std::cout << "  1 2 3 4 5 6 7" << std::endl;
        for (int i = 0; i < ROWS; ++i) {
            std::cout << "|";
            for (int j = 0; j < COLS; ++j) {
                std::cout << board[i][j] << "|";
            }
            std::cout << std::endl;
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << board[i][j] << " ";
        }
        std::cout << "---------------" << std::endl;
    }

    bool isValidMove(int col) {
        return col >= 0 && col < COLS && board[0][col] == ' ';
        cout << endl;
    }
}

    void makeMove(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == ' ') {
                board[i][col] = currentPlayer;
                break;
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check horizontally
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    bool checkWin() {
        // Check horizontally
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i][j + 1] == currentPlayer &&
                    board[i][j + 2] == currentPlayer &&
                    board[i][j + 3] == currentPlayer) {
                    return true;
    // Check vertically
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

        // Check vertically
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j] == currentPlayer &&
                    board[i + 2][j] == currentPlayer &&
                    board[i + 3][j] == currentPlayer) {
                    return true;
    // Check diagonally (from bottom left to top right)
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i - k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // TODO: Check diagonals

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == ' ') {
                    return false;
    // Check diagonally (from top left to bottom right)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return false;
}

    void play() {
        while (true) {
            printBoard();

            int col;
            do {
                std::cout << "Player " << currentPlayer << ", enter column (1-7): ";
                std::cin >> col;
                col--;  // Adjust for 0-based indexing
            } while (!isValidMove(col));

            makeMove(col);

            if (checkWin()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            } else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a draw!" << std::endl;
int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, '.'));

    char currentPlayer = 'X';
    int moves = 0;

    while (true) {
        printBoard(board);

        int col;
        cout << "Player " << currentPlayer << ", enter your column (0-" << COLS - 1 << "): ";
        cin >> col;

        if (col < 0 || col >= COLS) {
            cout << "Invalid column. Try again." << endl;
            continue;
        }

        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == '.') {
                board[i][col] = currentPlayer;
                break;
            }
            if (i == 0) {
                cout << "Column is full. Try again." << endl;
                continue;
            }
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;

            switchPlayer();
        if (moves == ROWS * COLS) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
    }
};

int main() {
    Power4Game game;
    game.play();
    return 0;
}
