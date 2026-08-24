#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int poww (long long x, long long n) {
        long long mod = 1000000007;
        if (n == 0) return 1;
        else if (n % 2 == 0) {
            long long y = poww(x, n/2);
            return ((y%mod) * (y%mod))%mod;
        }
        else {
            return ((x%mod)*(poww(x%mod, n-1)%mod)) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long mod = 1000000007;

        long long ans = ((poww(5, even)%mod) * (poww(4, odd)%mod))%mod;

        return ans;
    }
};