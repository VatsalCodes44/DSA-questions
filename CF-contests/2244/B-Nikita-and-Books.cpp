#include <bits/stdc++.h>

using namespace std;

void f() {
    int n;
    cin >> n;

    vector<long long> arr(n,0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    if (arr[0] > 1) {
        long long x = arr[0]-1;
        arr[0]-=x;
        arr[1]+=x;
    }

    for (int i = 1; i < n-1; i++) {
        if (arr[i] > i+1) {
            long long x = arr[i]-(i+1);
            arr[i]-=x;
            arr[i+1]+=x;
        }
        if (arr[i] < i+1) {
            cout << "NO" << endl;
            return;
        }
    }
    if (arr[n-1] <= arr[n-2]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        f();
    }
}