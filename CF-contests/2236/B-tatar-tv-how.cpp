#include <bits/stdc++.h>

using namespace std;

void f() {
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;
    
    for (int i = 0; i < n-k; i++) {
        if (str[i] != '0') {
            str[i] = '0';
            if (str[i+k] == '0') {
                str[i+k] = '1';
            }
            else {
                str[i+k] = '0';
            }
        }
    }

    for (auto i : str) {
        if (i == '1') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main () {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        f();
    }
}