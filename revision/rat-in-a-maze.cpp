#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    bool checkBounds(vector<vector<int> > &grid, int r, int c) {
        if (r < 0 || c < 0 || c >= grid.size() || r >= grid.size()) return false;
        return true;
    }
    void f(vector<vector<int> > &grid, int r, int c, string& ans, vector<string>& ansArr) {

        if (r == c && r == grid.size()-1) {
            ansArr.push_back(ans);
            return;
        }

        grid[r][c] = 0;

        // right
        if (checkBounds(grid, r, c+1) && grid[r][c+1]) {
            ans.push_back('R');
            f(grid, r, c+1, ans, ansArr);
            ans.pop_back();
        }

        // left
        if (checkBounds(grid, r, c-1) && grid[r][c-1]) {
            ans.push_back('L');
            f(grid, r, c-1, ans, ansArr);
            ans.pop_back();
        }

        // up
        if (checkBounds(grid, r-1, c) && grid[r-1][c]) {
            ans.push_back('U');
            f(grid, r-1, c, ans, ansArr);
            ans.pop_back();
        }

        // down
        if (checkBounds(grid, r+1, c) && grid[r+1][c]) {
            ans.push_back('D');
            f(grid, r+1, c, ans, ansArr);
            ans.pop_back();
        }

        grid[r][c] = 1;
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        string ans;
        vector<string> ansArr;

        f(grid, 0, 0, ans, ansArr);

        return ansArr;
    }
};