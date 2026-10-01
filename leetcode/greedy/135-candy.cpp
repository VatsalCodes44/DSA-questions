#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        while (i < ratings.size()) {
            if (ratings[i] == ratings[i-1]) {
                sum++;
                i++;
                continue;
            }

            // peak starts, may be its an increasing slope
            int peak = 1;
            while (i < ratings.size() && ratings[i] > ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 0;
            while (i < ratings.size() && ratings[i] < ratings[i-1]) {
                down++;
                sum += down; 
                i++;
            }

            if (down >= peak) sum += abs(down-peak+1);
        }

        return sum;
    }
};

int main () {
    vector<int> arr = {1,0,2};
    Solution s;
    cout << s.candy(arr);
}