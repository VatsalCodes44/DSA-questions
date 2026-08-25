#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void f(int n, int open, int close, string& ans, vector<string>& ansArr) {
        if (close == n) {
            ansArr.push_back(ans);
            return;
        }

        if (open < n) {
            ans.push_back('(');
            f(n, open+1, close, ans, ansArr);
            ans.pop_back();
        }

        if (close < open) {
            ans.push_back(')');
            f(n, open, close+1, ans, ansArr);
            ans.pop_back();
        }
    }
     vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> ansArr;
        f(n, 0, 0, ans, ansArr);
        return ansArr;
    }
};

