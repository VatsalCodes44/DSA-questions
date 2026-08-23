#include <bits/stdc++.h>

using namespace std;

string binary(int x) {
    string ans = "";
    while (x>=1) {
        ans += (char)('0' + x%2);
        x/=2;
    }
    while (ans.size()%8 != 0) {
        ans += '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool isPalindromic(string s) {
    string str = "";
    for (auto i: s) {
        str+= binary(i);
    }

    int i = 0;
    while (i <= str.size()-i-1) {
        if (str[i] != str[str.size()-i-1]) return false;
        i++;
    }
    return true;
}

int main () {
    cout << boolalpha << isPalindromic("ff");
}