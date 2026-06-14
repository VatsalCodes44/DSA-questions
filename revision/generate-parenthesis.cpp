#include <bits/stdc++.h>

using namespace std;

void f(vector<string> &ans, string& str, int open, int close, int i, int n) {
    if (i == n*2) {
        ans.push_back(str);
        return;
    }
    if (open < n) {
        str.push_back('(');
        open++;
        f(ans, str, open, close, i+1, n);
        open--, 
        str.pop_back();
    }
    if (close < open) {
        str.push_back(')');
        close++;
        f(ans, str, open, close, i+1, n);
        close--, 
        str.pop_back(); 
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string str;
    f(ans, str, 0, 0, 0, n);
    return ans;
}