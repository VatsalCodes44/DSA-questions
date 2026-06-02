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


// optimal solution
double pow (double x, long n) {
    if (n==0) return 1;
    if (n%2 == 0) {
        return pow(x*x, n/2);
    }
    else return x*pow(x, n-1);
}
double myPow(double x, int n) {
    double ans = 1;


    bool negative = n < 0 ? true : false;

    long nm = n < 0 ? (long)(n)*-1 : n;

    ans = pow (x, nm);

    if (negative) return 1/ans;
    return ans;
}
int main (){}