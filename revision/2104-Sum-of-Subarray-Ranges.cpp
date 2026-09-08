#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> v1;
        v1.reserve(nums.size());
        vector<int> v2;
        v2.reserve(nums.size());
        stack <int, vector<int>> st1(move(v1));
        stack <int, vector<int>> st2(move(v2));

        vector<int> nseL(nums.size(), -1), nseR(nums.size(), -1);
        vector<int> ngeL(nums.size(), -1), ngeR(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++) {
            while (!st1.empty() && nums[st1.top()] > nums[i]) st1.pop();
            if (!st1.empty()) nseL[i] = st1.top();
            st1.push(i);
            while (!st2.empty() && nums[st2.top()] < nums[i]) st2.pop();
            if (!st2.empty()) ngeL[i] = st2.top();
            st2.push(i);
        }

        while (!st1.empty()) st1.pop();
        while (!st2.empty()) st2.pop();

        for (int i = nums.size()-1; i >= 0; i--) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) st1.pop();
            if (!st1.empty()) nseR[i] = st1.top();
            st1.push(i);
            while (!st2.empty() && nums[st2.top()] <= nums[i]) st2.pop();
            if (!st2.empty()) ngeR[i] = st2.top();
            st2.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long l = nseL[i] == -1 ? 0 : nseL[i]+1;
            long long r = nseR[i] == -1 ? nums.size()-1 : nseR[i]-1;
            long long n = r-l+1;
            long long mI = i-l+1;
            sum -= nums[i]*mI*(n-mI+1);

            l = ngeL[i] == -1 ? 0 : ngeL[i]+1;
            r = ngeR[i] == -1 ? nums.size()-1 : ngeR[i]-1;
            n = r-l+1;
            mI = i-l+1;
            sum += nums[i]*mI*(n-mI+1);
        }
        return sum;
    }
};