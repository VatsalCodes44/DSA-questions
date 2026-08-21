#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        stack<int> st;
        int i = 0;
        int j = k-1;

        int maxx = *max_element(arr.begin(), arr.begin()+k);
        st.push(maxx);

        if (k == arr.size()) {
            vector<int> ans = {maxx};
            return ans;
        }

        i++;
        j++;
        while (j < arr.size()) {
            if (st.top() == maxx) {
                maxx = *max_element(arr.begin()+i, arr.begin()+i+k);
                st.push(maxx);
            }
            else {
                maxx = max(maxx, arr[j]);
                st.push(maxx);
            }
            i++;
            j++;
        }

        vector<int> ans (st.size());
        for (int i = ans.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};