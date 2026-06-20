#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
    // cout << "hi" << endl;
    // checking in row and col
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == char(n + '0')) return false;
        if (board[row][i] == char(n + '0')) return false;
    }

    // checking in 3x3 grid;
    int rowStart = row - (row % 3);
    int rowEnd = rowStart + 3;
    int colStart = col - (col % 3);
    int colEnd = colStart + 3;

    for (int i = rowStart; i < rowEnd; i++) {
        for (int j = colStart; j < colEnd; j++) {
            if (board[i][j] == char(n + '0')) return false;
        }
    }
    
    return true;
};

bool f(vector<vector<char>>& board, int row, int col) {
    if (row == 9) return true;
    // cout << 1 << endl;
    if (col == 9) {
        return f(board, row+1, 0);
    }

    if (board[row][col] == '.') {
        for (int i = 1; i <= 9; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = char(i + '0');
                if (f(board, row, col+1)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
    }
    else {
        return f(board, row, col+1);
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    f(board, 0, 0);
}

int main () {
    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);
    int count2 = 1;
    for (auto i: board){
        int count = 0;
        for (auto j: i) {
            if (count == 3) {
                cout << "| ";
                count = 0;
            }
            cout << j << " ";
            count++;
        }
        cout << endl;
        if (count2 % 3 == 0) {
            cout << "----------------------" << endl;
        }
        count2++;
    }
}