#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    bool sign = true;
    long long n, d;
    if (dividend > 0 && divisor < 0) sign = false;
    if (dividend < 0 && divisor > 0) sign = false;
    
    n = dividend < 0 ? ((long long)dividend)*-1 : dividend;
    d = divisor < 0 ? ((long long)divisor)*-1 : divisor;
    long long ans = 0;
    while (n >= d) {
        long long count = 0;
        while (d<<(count+1) <= n) count++;
        ans+= (1LL<<count);
        n = n - (d << count);
    }
    if (ans >= ((1LL << 31)) && sign) return INT_MAX;
    if (ans >= (1LL << 31) && !sign) return INT_MIN;
    return sign ? (int) ans : (int)(ans*-1);
}

int main () {
    int a = -2147483648;
    int b = -1;

    cout << divide(a,b) << endl;
}