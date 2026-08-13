#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    vector<int> ans(height.size(), -1);
    int prefixMax = height[0];
    for (int i = 1; i < height.size(); i++) {
        prefixMax = max(prefixMax, height[i]);
        ans[i] = prefixMax;
    }

    int n = height.size();
    int suffixMax = height[n-1];
    int total = 0;
    for (int i = n-2; i >= 0; i--) {
        suffixMax = max(suffixMax, height[i]);
        ans[i] = min(suffixMax, ans[i]);
        if (ans[i] > 0) total += ans[i] - height[i];
    }
    return total;
}

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(arr) << endl;
}