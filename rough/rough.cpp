#include <bits/stdc++.h>

using namespace std;



int divv(int dividend, int divisor) {
    bool positive = true;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        positive = false;
    }

    long long d1 = abs(1LL * (dividend));
    long long d2 = abs(1LL * (divisor));


    long long sum = 0;

    while (d1>=d2) {
        long long i = 0;
        while ((d2*(1LL<<(i+1))) <= d1) {
            i++;
        }
        sum += (1LL << i);
        d1 -= d2*(1LL<<i);
        i=0;
    }

    if(dividend == INT_MIN && positive) return INT_MAX;
    if(dividend == INT_MAX && !positive) return INT_MIN;
    
    if (!positive) {
        sum = sum*-1;
    }

    return sum;
}

int main () {
    cout << divv(INT_MIN,1) << endl;
}

int longestSubarray(vector<int> & nums, int target) {
     int left = 0, right = 0;
    int len = 0;
    int maxLen = 0;
    int sum = 0;

    while (right < nums.size()) {
        sum += nums[right];
        right++;

        while (sum > target) {
            sum-=nums[left];
            left++;
        }

        if (sum == target) {
            maxLen = max(maxLen, (right-left)+1);
        }
    }

    return maxLen ;
}