#include <bits/stdc++.h>

using namespace std;


// Brute force
double myPowBruteForce(double x, int n) {
    double ans = 1;

    bool negative = n < 0 ? true : false;

    n = abs(n);

    for (int i = 0; i < n; i++) {
        ans *= x;
    }

    if (negative) {
        return 1/ans;
    }

    return ans;
}

int main () {
    cout << myPowBruteForce(6, 2);
}