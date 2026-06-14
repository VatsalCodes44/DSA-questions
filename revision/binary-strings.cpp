#include <bits/stdc++.h>

using namespace std;

void generateBinaryStrings(string &ans, int i, int n) {
    if (i == n) {
        cout << ans << endl;
        return;
    }
    if (ans[i] == '1') {
        ans.push_back('0');
        generateBinaryStrings(ans, i+1, n);
        ans.pop_back();
        return;
    }

    ans.push_back('0');
    generateBinaryStrings(ans, i+1, n);
    ans.pop_back();
    
    ans.push_back('1');
    generateBinaryStrings(ans, i+1, n);
    ans.pop_back();
}

int main () {
    string str = "";
    generateBinaryStrings(str, 0, 3);
}