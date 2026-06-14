#include <bits/stdc++.h>

using namespace std;

void f(int n) {
    if (n == 0) return;
    else {
        cout << n%10;
        f(n/10);
    }
}

int main () {
    f(1234);
}