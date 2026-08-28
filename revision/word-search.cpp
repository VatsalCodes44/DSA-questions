#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
bool hasNeighbor(vector<vector<char>>& board, int r, int c, char target) {
    int R = board.size(), C = board[0].size();
    return (r > 0   && board[r-1][c] == target) ||
           (r < R-1 && board[r+1][c] == target) ||
           (c > 0   && board[r][c-1] == target) ||
           (c < C-1 && board[r][c+1] == target);
}

bool explore(vector<vector<char>>& board, int row, int col, const string& word, int idx) {
    if (idx == (int)word.size()) return true;
    if (row < 0 || row >= (int)board.size()) return false;
    if (col < 0 || col >= (int)board[0].size()) return false;
    if (board[row][col] != word[idx]) return false;

    if (idx + 1 < (int)word.size() && !hasNeighbor(board, row, col, word[idx+1]))
        return false;

    board[row][col] = '.';

    bool found = explore(board, row-1, col, word, idx+1)
              || explore(board, row+1, col, word, idx+1)
              || explore(board, row, col-1, word, idx+1)
              || explore(board, row, col+1, word, idx+1);

    board[row][col] = word[idx];
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int R = board.size(), C = board[0].size();

    int freq[128] = {};
    for (auto& row : board)
        for (char c : row) freq[(int)c]++;
    for (char c : word)
        if (--freq[(int)c] < 0) return false;

    auto countChar = [&](char c) {
        int cnt = 0;
        for (auto& row : board)
            cnt += count(row.begin(), row.end(), c);
        return cnt;
    };
    if (countChar(word.front()) > countChar(word.back()))
        reverse(word.begin(), word.end());

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (explore(board, i, j, word, 0)) return true;

    return false;
}
};

int main () {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    Solution s;
    cout << s.exist(board, word);
}