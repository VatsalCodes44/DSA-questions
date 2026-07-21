#include <bits/stdc++.h>

using namespace std;

vector<int> singleNumber(vector<int>& nums){
    //your code goes here
    int xorr = 0;
    for (auto i : nums) {
        xorr^=i;
    }

    int y = (xorr&(xorr-1))^xorr;

    int b1 = 0;
    int b2 = 0;

    for (auto i : nums) {
        if ((i & y) != 0) {
            b1^=i;
        }
        else {
            b2^=i;
        }
    }
    vector <int> ans;
    if (b1 > b2) {
        ans.push_back(b2);
        ans.push_back(b1);
    }
    else {
        ans.push_back(b1);
        ans.push_back(b2);
    }
    return ans;
}

int main () {
    vector <int> arr = {1, 1, 2, 2, 3, 5};
    for (auto i : singleNumber(arr)) {
        cout << i << " ";
    }
}