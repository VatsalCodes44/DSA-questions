#include <bits/stdc++.h>

using namespace std;

void generateSubseq(string& str, int i, string& ans) {
    if (i == str.size()) {
        cout << ans << endl;
        return;
    }

    generateSubseq(str, i+1, ans);

    ans.push_back(str[i]);
    generateSubseq(str, i+1, ans);
    ans.pop_back();
}

void subSeq(string str) {
    string ans;
    generateSubseq(str, 0, ans);
}

int main () {
    subSeq("abc");
}