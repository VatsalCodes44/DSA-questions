#include <bits/stdc++.h>

using namespace std;

bool explore(vector<vector<char>>& board, int row, int col, string& word, string& curr) {
    if (curr.size() == word.size()) {
        return true;
    }

    if (curr.size() == 0) {
        if (board[row][col] != word[0]) return false;
    }

    char x = board[row][col];
    board[row][col] = '.';
    curr.push_back(x);

    if (row > 0 && board[row-1][col] != '.' && board[row-1][col] == word[curr.size()] && explore(board, row-1, col, word, curr)) return true; //up
    if (row < board.size()-1 && board[row+1][col] != '.' && board[row+1][col] == word[curr.size()] && explore(board, row+1, col, word, curr)) return true; //down
    if (col > 0 && board[row][col-1] != '.' && board[row][col-1] == word[curr.size()] && explore(board, row, col-1, word, curr)) return true; //left
    if (col < board[0].size()-1 && board[row][col+1] != '.' && board[row][col+1] == word[curr.size()] && explore(board, row, col+1, word, curr)) return true; //right
    
    
    board[row][col] = x;
    
    // comparing the curr string with word here again beacuse it is necessar can't explain in words use debugger with WORD = "ABCCED" we will se that first
    // we will never reach he first (if (curr.size() == word.size())) when curr becomes "ABCCED"
    if (curr.size() == word.size()) {
        return true;
    }

    curr.pop_back();
    return false;

}

bool exist(vector<vector<char>>& board, string word) {
    string curr = "";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (explore(board, i, j, word, curr)) return true;
        }
    }
    return false;
}

int main () {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << boolalpha << exist(board, word) << endl;
}