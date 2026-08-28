#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col) {
        for (int i = col; i >= 0; i--) {
            if (board[row][i] == 'Q') return false;
        }

        int r = row;
        int c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;
        while (c >= 0 && r < board.size()) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void f(vector<string>& board, int col, vector<vector<string>>& ans) {
        if (col == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 'Q';
                f(board, col+1, ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row = "";
        for (int i = 0; i < n; i++) row += '.';
        vector<string> board(n, row);
        vector<vector<string>> ans;
        f(board, 0, ans);
        return ans;
    }
};

int main () {
    Solution s;
    s.solveNQueens(4);
}