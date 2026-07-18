#include <bits/stdc++.h>

using namespace std;

void f() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        sum+=x;
    }
    if (n%2 == 1 || sum%2 != 0) {
        cout << "NO" << endl;
        return;
    }
    if (sum == 0) {
        cout << "YES" << endl;
        return;
    }

    bool neg = sum < 0 ? true : false;

    for (int j = 0; j < n-1; j++) {
        if (sum == 0) {
            break;
        }
        if (arr[j] == arr[j+1]) {
            if (neg && arr[j] == -1) {
                arr[j] = 1;
                arr[j+1] = 1;
                sum+=4;
                j++;
            }
            else if (!neg && arr[j] == 1) {
                arr[j] = -1;
                arr[j+1] = -1;
                sum-=4;
                j++;
            }
        }
    }
    if (sum == 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        f();
    }
}