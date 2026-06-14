// n = 5
// 5
// 4
// 3
// 2
// 1
// 2
// 3
// 4
// 5

#include <bits/stdc++.h>

using namespace std;

void f(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    f(n-1);
    cout << n << endl;
}

int main () {
    f(5);
}