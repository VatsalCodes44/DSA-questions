#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = 0;
        int minSumWindow = INT_MAX;
        int sum = 0;
        int totalSum = 0;
        while (r < cardPoints.size()) {
            sum += cardPoints[r];
            totalSum += cardPoints[r];
            if (r-l+1 == cardPoints.size()-k) {
                minSumWindow = min(minSumWindow, sum);
                sum -= cardPoints[l];
                l++;
            }
            r++;
        }
        if (k == cardPoints.size()) return totalSum;
        return totalSum - minSumWindow;
    }
};

class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;
        int rSum = 0;
        int maxSum = 0;

        int l = 0;
        int r = cardPoints.size()-1;

        for (l; l < k; l++) {
            lSum += cardPoints[l];
        }
        l--;
        maxSum = lSum;

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

int main () {
    vector <int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    Solution2 s;
    s.maxScore(arr, k);
}
