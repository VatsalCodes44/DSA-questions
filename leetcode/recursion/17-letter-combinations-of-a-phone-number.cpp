#include <bits/stdc++.h>

using namespace std;

void lC(string &digits, int i, string &ans, vector <string> &ansArr, vector<string> &mappings) {
    if (digits[i] == '1') return;
    if (i == digits.size()) {
        ansArr.push_back(ans);
        return;
    }

    int digitInMapping = digits[i] - '2';
    string str = mappings[digitInMapping];
    for (int j = 0; j < str.size(); j++) {
        ans.push_back(str[j]);
        lC(digits, i+1, ans, ansArr, mappings);
        ans.pop_back();
    } 

}

vector<string> letterCombinations(string& digits) {
    vector <string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv" "wxyz"};  
    string ans = "";
    vector<string> ansArr;
    lC(digits, 0, ans, ansArr, mappings);
    return ansArr;
}

int main () {
    auto arr = letterCombinations("23");
    for (auto i: arr) {
        cout << i << endl;
    }
}