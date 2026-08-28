#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBePlaced(vector<vector<char>>& board, int r, int c, int n) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == char('0' + n))
                return false;
            if (board[i][c] == char('0' + n))
                return false;
        }

        int rowStart = r - (r % 3);
        int colStart = c - (c % 3);

        for (int i = rowStart; i < rowStart + 3; i++) {
            for (int j = colStart; j < colStart + 3; j++) {
                if (board[i][j] == char('0' + n))
                    return false;
            }
        }

        return true;
    }
    bool f(vector<vector<char>>& board, int r, int c) {
        if (c == 9 && r == 8)
            return true;
        if (c == 9) {
            c = 0;
            r++;
        }

        if (board[r][c] != '.') {
            if (f(board, r, c + 1))
                return true;
            return false;
        }

        for (int i = 1; i <= 9; i++) {
            if (canBePlaced(board, r, c, i)) {
                board[r][c] = char('0' + i);
                if (f(board, r, c + 1))
                    return true;
                board[r][c] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { f(board, 0, 0); }
};

int main () {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution s;
    s.solveSudoku(board);

    for (int r = 0; r < 9; r++) {
        if (r % 3 == 0) {
            cout << "+-------+-------+-------+\n";
        }
        for (int c = 0; c < 9; c++) {
            if (c % 3 == 0) {
                cout << "| ";
            }
            cout << board[r][c] << ' ';
        }
        cout << "|\n";
    }
    cout << "+-------+-------+-------+\n";
}