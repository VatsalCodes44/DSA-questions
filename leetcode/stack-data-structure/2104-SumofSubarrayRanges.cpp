#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        stack<int> st;
        vector<int> neLeft(arr.size(), -1);
        vector<int> neRight(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) neLeft[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) neRight[i] = st.top();
            st.push(i);
        }

        long long minSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long l = neLeft[i] == -1 ? 0 : neLeft[i]+1;
            long long r = neRight[i] == -1 ? arr.size()-1 : neRight[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            minSum += arr[i] * (modifiedI * (n - modifiedI + 1));
            neRight[i] = -1;
            neLeft[i] = -1;
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) neLeft[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) neRight[i] = st.top();
            st.push(i);
        }

        long long maxSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long l = neLeft[i] == -1 ? 0 : neLeft[i]+1;
            long long r = neRight[i] == -1 ? arr.size()-1 : neRight[i]-1;

            long long n = r-l+1;
            long long modifiedI = i-l+1;

            maxSum += arr[i] * (modifiedI * (n - modifiedI + 1));
        }

        return maxSum - minSum;
    }
};