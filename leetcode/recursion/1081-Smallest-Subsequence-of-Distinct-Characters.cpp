#include <bits/stdc++.h>
using namespace std;

void countSort (string& s) {
    vector<int> arr(26, 0);
    for (int i = 0; i < s.size(); i++) {
        arr[s[i]-'a']++;
    }
    int x = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < arr[i]; j++) {
            s[x] = ('a' + i);
            x++;
        }
    }
}



int main () {
    string s = "bcaba";
    countSort(s);
    cout << s << endl;
    cout << (0^1) << endl;;
}