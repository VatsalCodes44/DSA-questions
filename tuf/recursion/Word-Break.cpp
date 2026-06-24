#include <bits/stdc++.h>

using namespace std;

bool findWord(vector<string>& wordDict, string& word) {
    for (auto i: wordDict) {
        if (i == word) return true;
    }
    return false;
}

bool f(vector<string>& wordDict, string word, int i) {
    if (i == word.size()) {
        return true;
    }
    if (i > word.size()) return false;

    string curr = "";
    for (int j = i; j < word.size(); j++) {
        curr.push_back(word[j]);
        if (findWord(wordDict, curr) && f(wordDict, word, j+1)) return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    return f(wordDict, s, 0);
}

int main () {
    string s = "applepineapple";
    vector<string> wordDict = {"apple"};
    cout << boolalpha << wordBreak(s, wordDict) << endl;
}