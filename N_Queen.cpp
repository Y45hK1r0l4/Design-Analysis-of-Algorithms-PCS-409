#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<string>& board) {
    for (const string& row : board)
        cout << row << "\n";
    cout << "\n";
}

bool isSafe(int row, int col, vector<string>& board, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, vector<string>& board, int n) {
    if (row == n) {
        printBoard(board); // found one valid solution
        return;
    }
            
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';          // place queen
            solve(row + 1, board, n);       // move to next row
            board[row][col] = '.';          // backtrack
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));  // n x n board initialized with '.'
    solve(0, board, n);
    return 0;
}
