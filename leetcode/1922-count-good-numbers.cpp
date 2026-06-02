#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

long long poww(long long x, long long n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        return poww((x * x) % M, n/2);
    }
    else {
        return (x * poww(x, n-1)) % M;
    }
}

int countGoodNumbers (long long n) {
    long long even = (n + 1) / 2;
    long long odd = n / 2;

    long long ans1 = poww(5, even);
    long long ans2 = poww(4, odd);

    int ans = (int) ((ans1 * ans2) % M);

    return ans;
}

int main () {
    cout << countGoodNumbers(2983569263972389929LL) << endl;
}