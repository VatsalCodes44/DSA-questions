#include <bits/stdc++.h>

using namespace std;

int f(vector<int>& arr, int ones, int zeros, int l, int r) {
    if (l == r) return 0;
    if (ones == zeros) {
        return ones*2;
    }
    int x = 0;
    if (zeros > ones) {
        if (arr[l] == 0) {
            l++;
            zeros--;
            x = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            l--;
            zeros++;
        }
        if (arr[r] == 0) {
            r--;
            zeros--;
            x = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            r++;
            zeros++;
        }
        if (arr[l] == 0 && arr[r] == 0) {
            l++;
            ones--;
            int y = f(arr, ones, zeros, l, r);
            // if (x>0) return x;            
            l--;
            ones++;

            r--;
            ones--;
            int z = f(arr, ones, zeros, l, r);
            // if (x>0) return x;
            r++;
            ones++;

            if (max(y,z) > 0) return max(y,z);
        }
    }
    else {
        if (arr[l] == 1) {
            l++;
            ones--;
            x = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            l--;
            ones++;
        }
        if (arr[r] == 1) {
            r--;
            ones--;
            x = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            r++;
            ones++;
        }
        if (arr[r] == 0 && arr[l] == 0) {
            l++;
            zeros--;
            int y = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            l--;
            zeros++;

            r--;
            zeros--;
            int z = f(arr, ones, zeros, l, r);
            if (x>0) return x;
            r++;
            zeros++;
            if (max(y,z) > 0) return max(y,z);
        }
    }
    return 0;
}
int findMaxLength(vector<int>& nums) {
    int zeros = 0;
    int ones = 0;
    for (auto i: nums) {
        if (i == 1) ones++;
        else zeros++;
    }
    return f(nums, ones, zeros, 0, nums.size()-1);
}

int main () {
    vector<int> arr = {0,1,1,1,1,1,0,0,0};
    cout << findMaxLength(arr);
}