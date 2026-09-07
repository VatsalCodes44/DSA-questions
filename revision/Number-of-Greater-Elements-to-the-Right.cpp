#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int> &arr, int idx) {
        int count = 0;
        for (int i = idx+1; i < arr.size(); i++) {
            if (arr[i] > arr[idx]) count++;
        }
        return count;
    }
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
       vector<int> ans2(indices.size());
        for (int i = 0; i < indices.size(); i++) {
            ans2[i] = f(arr,indices[i]);
        }

        return ans2;
    }
};