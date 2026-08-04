#include <bits/stdc++.h>

using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int sum = 0;
    int count = 0;
    map<int, int> remainders;
    remainders[0] = 1;

    for (auto i: nums) {
        sum += i;
        int r = sum % k;
        if (r < 0) r = (r + k) % k;

        if (remainders[r] > 0) {
            count += remainders[r];
        }

        remainders[r]++;
    }

    return count;
}