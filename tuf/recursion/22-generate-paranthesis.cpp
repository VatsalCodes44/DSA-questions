#include <bits/stdc++.h>

using namespace std;

void f(int n, int open, int close, string &ans) {
    if (n*2 <= ans.size()) {
        cout << ans << endl;
        if (n == open && n == close) {
        }
        return;
    }

    if (open < n) {
        ans.push_back('(');
        f(n, open+1, close, ans);
        ans.pop_back();
    }
    if (close < open) {
        ans.push_back(')');
        f(n, open, close+1, ans);
        ans.pop_back();
    }
}

int main () {
    string str = "";
    f(3, 0, 0, str);
}