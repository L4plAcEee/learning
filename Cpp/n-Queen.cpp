#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<int> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int> &board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void solveNQueens(vector<int> &board, int row, int n, int &solutions) {
    if (row == n) {
        solutions++;
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutions);
        }
    }
}

int main() {
    int n;
    cout << "输入皇后数量 (4~16): ";
    cin >> n;

    if (n < 4 || n > 16) {
        cout << "无效输入。" << endl;
        return 0;
    }

    vector<int> board(n);
    int solutions = 0;

    solveNQueens(board, 0, n, solutions);
    cout << "总解的数量: " << solutions << endl;

    return 0;
}
