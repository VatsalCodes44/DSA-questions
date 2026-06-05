#include <bits/stdc++.h>

using namespace std;

void jaggedSwaps() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (arr[0] != 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        jaggedSwaps();
    }
}