#include <bits/stdc++.h>

using namespace std;

bool palindrome (string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

void solve (string &str, int i, vector <string> &ans, vector<vector<string>>& ansArr) {
    if (i == str.size()) {
        ansArr.push_back(ans);
        return;
    }
    string substr = "";
    for (int j = i; j < str.size(); j++) {
        substr.push_back(str[j]);
        if (palindrome(substr)) {
            ans.push_back(substr);
            solve(str, j+1, ans, ansArr);
            ans.pop_back();
        }
    }
}

int main () {
    string str = "aabc";
    vector <string> ans;
    vector<vector<string>> ansArr;
    solve(str, 0, ans, ansArr);
    for ( auto i: ansArr) {
        for (auto j: i) {
            cout << j << "  ";
        }
        cout << endl;
    }
}