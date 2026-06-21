#include <bits/stdc++.h>

using namespace std;

int countValidSubarrays(vector<int>& arr, int x) {
    int count = 0; 
    for (int i = 0; i < arr.size(); i++) {
        long long sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum % 10 != x) continue;

            long long t = sum;
            while (t >= 10) t /= 10;

            if (t == x) count++;
        }
    }
    return count;
}

int main () {
    vector <int> arr = {1,100,1};
    cout << countValidSubarrays(arr, 1) << endl;
}