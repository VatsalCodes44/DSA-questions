#include <bits/stdc++.h>

using namespace std;

bool explore(vector<vector<char>>& board, int row, int col, string& word, int i) {
    if (i == word.size()) {
        return true;
    }

    if (row < 0 || row >= board.size()) return false; // out of bounds
    if (col < 0 || col >= board[0].size()) return false; // out of bounds

    if (word[i] != board[row][col]) return false;
    board[row][col] = '.'; // mark visited

    bool found = explore(board, row-1, col, word, i+1) // up
    || explore(board, row+1, col, word, i+1) // down
    || explore(board, row, col-1, word, i+1) // left
    || explore(board, row, col+1, word, i+1); // right

    board[row][col] = word[i];
    return found;

}

bool exist(vector<vector<char>>& board, string& word) {
    string curr = "";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (explore(board, i, j, word, 0)) return true;
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