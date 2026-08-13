#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    vector<int> arr(height.size(), -1);
    for (int i = height.size()-1; i >= 0; i--) {
        while (!st.empty() && st.top() < height[i]) {
            st.pop();
        }
        if (!st.empty()) {
            arr[i] = st.top();
        }
        st.push(height[i]);
    }

    int x = 0;
    while (x < height.size() && height[x] <= 0) x++; 
    if (x == height.size()) return 0;
    int curr = height[x];
    int sum = 0;
    int nge = arr[x];
    x++;
    while (x < height.size()) {
        int depth = 0;
        if (nge == -1) {
            int i = x;
            int maxx = height[i];
            for (i; i < height.size(); i++) {
                maxx = max(maxx, height[i]);
            }
            nge = maxx;
        }

        while (height[x] != nge) {
            depth += min(curr, nge)-height[x];
            x++;
        }
        sum += depth;
        nge = arr[x];
        curr = height[x];
        x++;
    }
    return sum;
}

int main () {
    vector<int> arr = {4,2,3};
    cout << trap(arr) << endl;
}