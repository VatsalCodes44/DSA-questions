#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0, rSum = 0;

        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }

        int l = k-1;
        int r = cardPoints.size()-1;

        int maxSum = lSum;

        while (l >= 0) {
            lSum -= cardPoints[l];
            l--;
            rSum += cardPoints[r];
            r--;

            maxSum = max(maxSum, lSum + rSum);
        }
        return maxSum;
    }
};