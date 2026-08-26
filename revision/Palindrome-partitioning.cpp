#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string& s) {
    int i = 0;
    while (i < s.size()-i-1) {
        if (s[i] != s[s.size()-i-1]) return false;
        i++;
    }
    return true;
}

void f(string& s, int i, vector<string>& ans, vector<vector<string>>& ansArr) {
    if (i == s.size()) {
        ansArr.push_back(ans);
        return;
    }

    int r = i;
    string temp = "";
    for (r; r < s.size(); r++) {
        temp += s[r];
        if (isPalindrome(temp)) {
            ans.push_back(temp);
            f(s, r+1, ans, ansArr);
            ans.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ansArr;
    vector<string> ans;
    f(s, 0, ans, ansArr);

    return ansArr;
}

int main () {
    string s = "aabaa";
    for (auto i: partition(s)) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}