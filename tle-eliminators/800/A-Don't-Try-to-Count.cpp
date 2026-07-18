#include <bits/stdc++.h>

using namespace std;

bool checkSubstr(string& x, string& s) {
    for(int i = 0; i < x.size(); i++) {
        for (int j = 0; j < s.size(); j++ ) {
            if (x[i+j] != s[j]) break;
            else if (x[i+j] == s[j] && j == s.size()-1) {
                return true;
            }
        }
    }
    return false;
}

void f() {
    int n,m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int z = m+1/n;

    if (x.size() >= m) {
        if (checkSubstr(x,s)) {
            cout << 0 << endl;
            return;
        }
    }
    int count = 1;
    x.append(x);
    while (x.size() <= m) {
        x.append(x);
        count++;
    }

    if (checkSubstr(x, s)) {
        cout << count << endl;
    }
    else {
        cout << -1  << endl;
    }
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        f();
    }
}