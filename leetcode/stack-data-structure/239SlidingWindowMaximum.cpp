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
    vector<int> maxSlidingWindowDeque(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_back();

            if (dq.empty()) {
                dq.push_back(i);
            }
            else if (arr[i] >= arr[dq.front()]) {
                while (!dq.empty()) dq.pop_front();
                dq.push_front(i);
            }
            else {
                while (! dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
                dq.push_back(i);
            }
            if (i >= k-1) {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<int> nums = {1,-1};
    for (auto i: s.maxSlidingWindowDeque(nums, 1)) {
        cout << i << " ";
    }
}