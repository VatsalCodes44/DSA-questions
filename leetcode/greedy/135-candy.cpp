#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int candy = 1;
        int lastPeakValue = 1;
        int lastPeak = 0;
        int count = 1;
        int i = 1;

        while (i < ratings.size()) {
            while (i < ratings.size() && ratings[i - 1] < ratings[i]) {
                candy++;
                count += candy;
                lastPeak = i;
                lastPeakValue = candy;
                i++;
            }

            candy = 0;
            while (i < ratings.size() && ratings[i - 1] > ratings[i]) {
                candy++;
                count += candy;
                i++;
            }

            if (lastPeak != -1) {
                count -= lastPeakValue;
                count += max(lastPeakValue, candy + 1);
                lastPeak = -1;
            }

            candy = 1;
            while (i < ratings.size() && ratings[i - 1] == ratings[i]) {
                count++;
                lastPeak = i;
                lastPeakValue = candy;
                i++;
            }
        }
        return count;
    }
};

int main () {
    vector<int> arr = {1,0,2};
    Solution s;
    cout << s.candy(arr);
}