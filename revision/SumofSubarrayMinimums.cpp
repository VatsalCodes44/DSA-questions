#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nseLeft(arr.size(), -1);
        vector<int> nseRight(arr.size(), -1);
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nseLeft[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size()-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) nseRight[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        long long mod = 1000000007;

        for (long long i = 0; i < arr.size(); i++) {
            long long l = nseLeft[i] == -1 ? 0 : nseLeft[i]+1;
            long long r = nseRight[i] == -1 ? arr.size()-1 : nseRight[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            sum = (sum%mod) + ((arr[i]%mod) * ((modifiedI*(n-modifiedI+1))%mod))%mod;
        }
        return sum;

    }
};