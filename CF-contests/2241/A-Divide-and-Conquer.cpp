#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x % y == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}