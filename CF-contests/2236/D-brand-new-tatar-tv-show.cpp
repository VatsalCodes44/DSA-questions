#include <bits/stdc++.h>

using namespace std;

void f() {
    int n,k;
    cin >> n >> k;
    int min = 0;
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        mpp[temp]++;
        if (temp < min) {
            min = temp;
        }
    }
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        f();
    }
}