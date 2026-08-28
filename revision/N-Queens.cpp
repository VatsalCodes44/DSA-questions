#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isSafe(int row, int col, vector<int>& rowHash, vector<int>& upperD, vector<int>& lowerD) {
        if (rowHash[row]) return false;
        if (lowerD[row + col]) return false;
        if (upperD[rowHash.size() - 1 + col - row]) return false;
        return true;
    }

    void f(vector<string>& board, int col, vector<vector<string>>& ans, vector<int>& rowHash, vector<int>& upperD, vector<int>& lowerD) {
        if (col == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (isSafe(i, col, rowHash, upperD, lowerD)) {
                board[i][col] = 'Q';
                rowHash[i] = 1;
                upperD[rowHash.size() - 1 + col - i] = 1;
                lowerD[i + col] = 1;
                f(board, col+1, ans, rowHash, upperD, lowerD);
                rowHash[i] = 0;
                upperD[rowHash.size() - 1 + col - i] = 0;
                lowerD[i + col] = 0;
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string row = "";
        for (int i = 0; i < n; i++) row += '.';
        vector<string> board(n, row);
        vector<vector<string>> ans;

        vector<int> rowHash(n, 0);
        vector<int> upperD((2*n-1)*2, 0);
        vector<int> lowerD((2*n-1)*2, 0);
        
        f(board, 0, ans, rowHash, upperD, lowerD);
        return ans;
    }
};

int main () {
    Solution s;
    s.solveNQueens(4);
}