#include <bits/stdc++.h>

using namespace std;

void solve(vector<string>& board, int col, int n, vector<vector<string>>& ans, vector<int> &upperDiag, vector<int> &lowerDiag, vector<int> &leftRow) {
    // basecase
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (!leftRow[row] && !upperDiag[n-1+col-row] && !lowerDiag[row+col]) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiag[n-1+col-row] = 1;
            lowerDiag[row+col] = 1;

            solve(board, col+1, n, ans, upperDiag, lowerDiag, leftRow);

            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiag[n-1+col-row] = 0;
            lowerDiag[row+col] = 0;
        }
    }
    
}

vector<vector<string>> solveNQueens(int n) {
    string str(n, '.');
    vector<string> board(n,str);
    vector<vector<string>> ans;
    vector<int> upperDiag(2*n-1,0);
    vector<int> lowerDiag(2*n-1,0);
    vector<int> leftRow(n,0);
    solve(board, 0, n, ans, upperDiag, lowerDiag, leftRow);
    return ans;
}

int main () {
    vector<vector<string>> ans = solveNQueens(4);
    for (auto i: ans) {
        for (auto j: i) {
            cout << j << endl;
        }
        cout << "-----------------------------------" << endl;
    }
}