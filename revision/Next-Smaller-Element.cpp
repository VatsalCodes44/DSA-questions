#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
        vector<int> v;
        v.reserve(arr.size());
        stack<int, vector<int>> st(move(v));
        vector<int> ans(arr.size(), -1);

        for (int i = arr.size()-1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
