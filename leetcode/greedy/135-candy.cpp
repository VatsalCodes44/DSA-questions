#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr(1, ratings.size());

        for (int i = 1; i < arr.size(); i++) {
            if (ratings[i-1] < ratings[i]) {
                arr[i] = arr[i-1]+1;
            }
        }

        int curr = 1;
        for (int i = arr.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                curr++;
                arr[i] = max(curr, arr[i]);
            }
            else curr = 1;
        }

        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            count += arr[i];
        }

        return count;
    }
};


int main () {
    vector<int> arr = {1,0,2};
    Solution s;
    cout << s.candy(arr);
}