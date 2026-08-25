#include <bits/stdc++.h>

using namespace std;

vector<string> binaryStrings(string& ans, int i, int n, vector<string>& ansArr) {
    if (i == n) {
        ansArr.push_back(ans);
        return;
    }

    ans.push_back('0');
    binaryStrings(ans, i+1, n, ansArr);
    ans.pop_back();

    if (ans.size() == 0 || (ans.size() > 0 && ans.back() != '1')) {
        ans.push_back('1');
        binaryStrings(ans, i+1, n, ansArr);
        ans.pop_back();
    }
}