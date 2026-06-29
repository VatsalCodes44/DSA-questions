#include <bits/stdc++.h>

using namespace std;

void bs(int i, int n, string& ans) {
    if (i == n) {
        cout << ans << endl;
        return;
    }

    if (ans.back() == '1') {
        ans.push_back('0');
        bs(i+1, n, ans);
        ans.pop_back();
        return;
    }

    ans.push_back('0');
    bs(i+1, n, ans);
    ans.pop_back();

    ans.push_back('1');
    bs(i+1, n, ans);
    ans.pop_back();
}

int main () {
    string s = "";
    bs(0, 3, s);
}