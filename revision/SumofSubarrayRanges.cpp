#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nseLeft(arr.size(), -1);
        vector<int> nseRight(arr.size(), -1);
        vector<int> ngeLeft(arr.size(), -1);
        vector<int> ngeRight(arr.size(), -1);
        stack<int> stSmaller;
        stack<int> stGreater;

        for (int i = 0; i < arr.size(); i++) {
            while (!stSmaller.empty() && arr[stSmaller.top()] >= arr[i]) stSmaller.pop();
            if (!stSmaller.empty()) nseLeft[i] = stSmaller.top();
            stSmaller.push(i);

            while (!stGreater.empty() && arr[stGreater.top()] <= arr[i]) stGreater.pop();
            if (!stGreater.empty()) ngeLeft[i] = stGreater.top();
            stGreater.push(i);
        }

        while (!stSmaller.empty()) {
            stSmaller.pop();
        }
        while (!stGreater.empty()) {
            stGreater.pop();
        }

        for (int i = arr.size()-1; i >= 0; i--) {
            while (!stSmaller.empty() && arr[stSmaller.top()] > arr[i]) stSmaller.pop();
            if (!stSmaller.empty()) nseRight[i] = stSmaller.top();
            stSmaller.push(i);

            while (!stGreater.empty() && arr[stGreater.top()] < arr[i]) stGreater.pop();
            if (!stGreater.empty()) ngeRight[i] = stGreater.top();
            stGreater.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            int l = nseLeft[i] == -1 ? 0 : nseLeft[i]+1;
            int r = nseRight[i] == -1 ? arr.size()-1 : nseRight[i]-1;

            int n = r-l+1;
            int modifiedI = i-l+1;

            sum -= (long long)arr[i] * (modifiedI*(n-modifiedI+1));


            l = ngeLeft[i] == -1 ? 0 : ngeLeft[i]+1;
            r = ngeRight[i] == -1 ? arr.size()-1 : ngeRight[i]-1;
            n = r-l+1;
            modifiedI = i-l+1;
            sum += (long long)arr[i] * (modifiedI*(n-modifiedI+1));
        }

        return sum;
    }
};