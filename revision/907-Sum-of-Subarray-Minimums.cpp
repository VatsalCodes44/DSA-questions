#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        vector<int> v;
        v.reserve(arr.size());
        stack<int, vector<int>> st(move(v));
        // stack<int> st;
        vector<int> nseR(arr.size(), -1);
        vector<int> nseL(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nseL[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size()-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) nseR[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        long long mod = 1000000007;

        for (int i = 0; i < arr.size(); i++) {
            long long l = nseL[i] == -1 ? 0 : nseL[i]+1;
            long long r = nseR[i] == -1 ? nseR.size()-1 : nseR[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            sum = ((sum % mod) + (modifiedI * (n-modifiedI+1) * arr[i]) % mod) % mod;
        }
        return sum;
    }
};

int main () {
    vector<int> arr = {3,1,2,4};
    Solution s;
    cout << s.sumSubarrayMins(arr);
}