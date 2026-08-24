#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double poww(double x, long long n) {
        if (n == 0) return 1;
        if (n%2 == 0) {
            double y = poww(x, n/2);
            return y*y;
        }
        else return x*poww(x, n-1);
    }
    double myPow(double x, int n) {
        double ans = poww(abs(x), abs((long long)n));

        if (n < 0) {
            ans = 1/ans;
        }

        if (x < 0) {
            if (n % 2 != 0) {
                ans *= -1;
            }
        }
        return ans;
    }
};