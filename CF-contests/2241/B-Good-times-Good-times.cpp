#include <bits/stdc++.h>

using namespace std;

bool good(long n) {
    long long x =10;
    long long y = 10;

    while (n) {
        long long a = n%10;
        n/=10;
        if (x == 10 || x == a) {
            x=a;
        }
        else if (y ==10 || y == a) {
            y = a;
        }
        else {
            return false;
        }
    }
    return true;
}

void f() {
    long long x;
    cin >> x;
    for (long long y = 2; y <= 1000000000; y++) {
        if (good(y)) {
            if (good(x*y)) {
                cout << y << endl;
                return;
            }
        }
    }

}

int main () {
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        f();
    }
}