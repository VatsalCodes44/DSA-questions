#include <bits/stdc++.h>

using namespace std;

int secondLargestElement(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) return -1; 
    int largest = nums[0];
    int secondLargest = INT_MIN;
    for (auto i: nums) {
        if (i > largest) {
            secondLargest = largest;
            largest = i;
        }
        else if (secondLargest < i && i < largest) secondLargest = i;
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
    
}

int main () {
    vector<int> nums = {8, 8, 7, 6, 5};
    cout << secondLargestElement(nums) << endl;
}