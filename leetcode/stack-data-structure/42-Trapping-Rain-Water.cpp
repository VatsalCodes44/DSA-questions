#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    vector<int> nge(height.size(), -1);
    for (int i = height.size()-1; i >= 0; i--) {
        while (!st.empty() && st.top() <= height[i]) {
            st.pop();
        }
        while (st.size() > 1) st.pop();
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(height[i]);
    }

    while (!st.empty()) st.pop();

    nge[0] = -1;

    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && st.top() <= height[i]) {
            st.pop();
        }
        while (st.size() > 1) st.pop();
        nge[i] = min((st.empty() ? -1 : st.top()), nge[i]);
        st.push(height[i]);
    }

    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
        if (nge[i] == -1 || nge[i] == -1) continue;
        ans += nge[i] - height[i];
    }
    return ans;
}

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(arr) << endl;
}