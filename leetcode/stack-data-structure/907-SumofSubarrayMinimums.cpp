#include <bits/stdc++.h>

using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    stack<int> st;
    vector<int> nseRight(arr.size(), -1);
    vector<int> nseLeft (arr.size(), -1);

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
    for (int i = 0; i < arr.size(); i++) {
        int l = nseLeft[i] == -1 ? 0 : nseLeft[i]+1;
        int r = nseRight[i] == -1 ? arr.size()-1 : nseRight[i]-1;

        int n = (r-l+1) % mod;
        int modifiedI = i-l+1;

        sum = ((sum % mod) + ((((modifiedI)*(n-modifiedI+1)) % mod) * (arr[i] % mod) % mod)) % mod;
    }

    return (int) sum;
}

int main () {
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins(arr);
}