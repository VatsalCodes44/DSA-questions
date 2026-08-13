#include <bits/stdc++.h>

using namespace std;

vector<int> countNGE(vector<int> &arr) {
    stack<int> st;
    vector<int> ans(arr.size(), 0);
    for (int i = arr.size()-1; i >= 0; i--) {
        vector<int> temp;
        while (!st.empty() && st.top() < arr[i]) {
            temp.push_back(st.top());
            st.pop();
        }
        ans[i] = st.size();
        st.push(arr[i]);
        for (auto j : temp) st.push(j);
    }
    return ans;
}

int main () {
    vector <int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    for (auto i: countNGE(arr)) {
        cout << i << " ";
    }
}