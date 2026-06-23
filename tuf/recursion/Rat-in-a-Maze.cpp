#include <bits/stdc++.h>

using namespace std;

void f (vector<vector<int>> &grid, int row, int col, string& path, vector<string>& ans) {
    if (row == grid.size()-1 && col == grid[0].size()-1) {
        ans.push_back(path);
        return;
    }
    if (!grid[row][col]) return;

    grid[row][col] = 0;
    if (row < grid.size()-1 && grid[row+1][col]) {
        path.push_back('D');
        f(grid, row+1, col, path, ans);
        path.pop_back();
    }
    if (col > 0 && grid[row][col-1]) {
        path.push_back('L');
        f(grid, row, col-1, path, ans);
        path.pop_back();
    }
    if (col < grid[0].size()-1 && grid[row][col+1]) {
        path.push_back('R');
        f(grid, row, col+1, path, ans);
        path.pop_back();
    }
    if (row > 0 && grid[row-1][col]) {
        path.push_back('U');
        f(grid, row-1, col, path, ans);
        path.pop_back();
    }
    grid[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &grid) {
    string path = "";
    vector<string> ans;
    f(grid, 0, 0, path, ans);
    return ans;
}

int main () {
    vector<vector<int>> grid = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1} 
    };

    vector<string> arr = findPath(grid);
    for (auto i: arr) {
        cout << i << endl;
    }
}