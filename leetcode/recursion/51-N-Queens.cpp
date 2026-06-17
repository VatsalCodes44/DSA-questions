#include <bits/stdc++.h>

using namespace std;

void f(vector<string>& arr, int r, int n, vector<vector<string>>& ans) {
    // basecase
    if (r == n) {
        vector<string> abc;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'Q') {
                    str.push_back('Q');
                }
                else {
                    str.push_back('.');
                }
            }
            abc.push_back(str);
        }
        ans.push_back(abc);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (arr[r][c] != '0') {
            continue;
        }
        arr[r][c] = 'Q';

        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            arr[r][i] = char(((arr[r][i] - '0')+1) + '0');
        }
        
        for (int j = 0; j < n; j++) {
            if (j == r) continue;
            arr[j][c] = char(((arr[j][c] - '0')+1) + '0');
        }
        
        int i = r+1; 
        int j = c+1;
        while (i < n && j < n) {
            arr[i][j] = char(((arr[i][j] - '0')+1) + '0');
            i++;
            j++;
        }

        i = r-1; 
        j = c-1;
        while (i >= 0 && j >= 0) {
            arr[i][j] = char(((arr[i][j] - '0')+1) + '0');
            i--;
            j--;
        }

        i = r-1; 
        j = c+1;
        while (i >= 0 && j < n) {
            arr[i][j] = char(((arr[i][j] - '0')+1) + '0');
            i--;
            j++;
        }

        i = r+1; 
        j = c-1;
        while (i < n && j >= 0) {
            arr[i][j] = char(((arr[i][j] - '0')+1) + '0');
            i++;
            j--;
        }
        
        f(arr, r+1, n, ans);

        arr[r][c] = '0';

         for (int i = 0; i < n; i++) {
            if (i == c) continue;
            arr[r][i] = char(((arr[r][i] - '0')-1) + '0');
        }
        
        for (int j = 0; j < n; j++) {
            if (j == r) continue;
            arr[j][c] = char(((arr[j][c] - '0')-1) + '0');
        }
        
        i = r+1; 
        j = c+1;
        while (i < n && j < n) {
            arr[i][j] = char(((arr[i][j] - '0')-1) + '0');
            i++;
            j++;
        }

        i = r-1; 
        j = c-1;
        while (i >= 0 && j >= 0) {
            arr[i][j] = char(((arr[i][j] - '0')-1) + '0');
            i--;
            j--;
        }

        i = r-1; 
        j = c+1;
        while (i >= 0 && j < n) {
            arr[i][j] = char(((arr[i][j] - '0')-1) + '0');
            i--;
            j++;
        }

        i = r+1; 
        j = c-1;
        while (i < n && j >= 0) {
            arr[i][j] = char(((arr[i][j] - '0')-1) + '0');
            i++;
            j--;
        }
        
    }
}    
// r = 0; j = 0;
//    0 1 2 3   
// 0 |q|.|.|.|
// 1 |.|.| | |
// 2 |.| |.| |
// 3 |.| | |.|

vector<vector<string>> solveNQueens(int n) {
    string str = "";
    for (int i = 0; i < n; i++) {
        str.push_back('0');
    }
    vector<string> board(n,str);
    vector<vector<string>> ans;
    f(board, 0, n, ans);
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