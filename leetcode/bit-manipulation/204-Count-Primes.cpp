#include <bits/stdc++.h>

using namespace std;

int countPrimes (int n) {
    vector<int> arr(n);

    if (n < 2) return 0;
    
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }
    int count = 0;
    for (long long i = 2; i < n; i++) {
        if (arr[i] == 0) continue;
        if (i*i >= n) break;
        // count++;
        for (long long j = i*i; j < n; j = j+i) {
            arr[j] = 0;
        }
    }
    for (auto i : arr) {
        if (i == 1) count++;
    }
    return count-2; // 0 and 1 are counted that must be removed
}

int main () {
    cout << countPrimes(10) << endl;
}