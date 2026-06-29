#include <bits/stdc++.h>

using namespace std;

void f (int i, int n, int open, int close, string& ans){
    if (i/2 == n) {
        cout << ans << endl;
        return;
    }

    if (open < n) {
        ans.push_back('(');
        f (i+1, n, open+1, close, ans);
        ans.pop_back();
    }

    if (close < open) {
        ans.push_back(')');
        f(i+1, n, open, close+1, ans);
        ans.pop_back();
    }
}

int main () {
    string ans = "";
    f(0, 3, 0, 0, ans);
}