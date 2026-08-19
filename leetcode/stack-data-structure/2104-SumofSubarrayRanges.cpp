#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        stack<int> st;
        vector<int> nseLeft(arr.size(), -1);
        vector<int> nseRight(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nseLeft[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) nseRight[i] = st.top();
            st.push(i);
        }

        long long minSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long l = nseLeft[i] == -1 ? 0 : nseLeft[i]+1;
            long long r = nseRight[i] == -1 ? arr.size()-1 : nseRight[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            minSum += arr[i] * (modifiedI * (n - modifiedI + 1));
        }

        while (!st.empty()) st.pop();


        vector<int> ngeLeft(arr.size(), -1);
        vector<int> ngeRight(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) ngeLeft[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) ngeRight[i] = st.top();
            st.push(i);
        }

        long long maxSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long l = ngeLeft[i] == -1 ? 0 : ngeLeft[i]+1;
            long long r = ngeRight[i] == -1 ? arr.size()-1 : ngeRight[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            maxSum += arr[i] * (modifiedI * (n - modifiedI + 1));
        }

        return maxSum - minSum;
    }
};