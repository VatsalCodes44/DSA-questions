#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size() ;

    reverse(nums.begin(), nums.begin()+ (nums.size()- k ));
    reverse(nums.end()-k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main () {
    vector<int> arr = {1,2,3,4,5,6,7};
    rotate(arr, 11);
    for (auto i: arr) {
        cout << i << " ";
    }
}