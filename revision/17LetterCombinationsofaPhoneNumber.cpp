#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<char, string> mpp;
    Solution () {
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
    }
    void f(string& digits, int i, string& ans, vector<string>& ansArr ) {
        if (ans.size() == digits.size()) {
            ansArr.push_back(ans);
            return;
        }

        for (int j = 0; j < mpp[digits[i]].size(); j++) {
            ans.push_back(mpp[digits[i]][j]);
            f(digits, i+1, ans, ansArr);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string ans;
        vector<string> ansArr;
        f(digits, 0, ans, ansArr);
        return ansArr;
    }
};