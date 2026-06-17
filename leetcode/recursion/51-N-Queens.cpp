#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, int n, vector<string> board) {
    int i = row-1;
    int j = col-1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }

    i = row+1;
    j = col-1;
    while (i < n && j >= 0) {
        if (board[i][j] == 'Q') return false;
        i++;
        j--;
    }

    j = col;
    while (j >= 0) {
        if (board[row][j] == 'Q') return false;
        j--;
    }
    return true;
}

void solve(vector<string>& board, int col, int n, vector<vector<string>>& ans) {
    // basecase
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row,col,n,board)) {
            board[row][col] = 'Q';
            solve(board, col+1, n, ans);
            board[row][col] = '.';
        }
    }
    
}

vector<vector<string>> solveNQueens(int n) {
    string str(n, '.');
    vector<string> board(n,str);
    vector<vector<string>> ans;
    solve(board, 0, n, ans);
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