#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int positiveProd = nums[0];
    int negativeProd = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (positiveProd == 0) {
            positiveProd = max(0, nums[i]);
        }
        else {
            positiveProd *= nums[i];
        }
        if (negativeProd == 0) {
            negativeProd = min(0, nums[i]);
        }
        else {
            negativeProd *= nums[i];
        }

        if (positiveProd >= 0) {
            maxProd = max(maxProd, positiveProd);
        }
        if (negativeProd >= 0) {
            maxProd = max(maxProd, negativeProd);
        }

        if (negativeProd > 0 && positiveProd < 0) {
            int temp1 = negativeProd;
            int temp2 = positiveProd;

            negativeProd = min(temp1, temp2);
            positiveProd = max(temp1, temp2);
        }

        if (negativeProd > 0) {
            positiveProd = max(positiveProd, negativeProd);
            negativeProd = 0;
        }
        if (positiveProd < 0) {
            negativeProd = max(positiveProd, negativeProd);
            positiveProd = 0;
        }
    }

    return maxProd;
}

int main () {
    vector<int> arr = {-2, 0, -1};
    cout << maxProduct(arr);
}