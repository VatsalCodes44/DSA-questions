#include <bits/stdc++.h>

using namespace std;

void f() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max = 0;
    int count = 0;

    for (auto i: s) {
        if (i == '*') {
            count = 0;
        }
        else count++;
        if (count > max) {
            max = count;
        }
    }
    cout << (max+1)/2 << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        f();
    }
}