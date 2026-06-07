#include <bits/stdc++.h>

using namespace std;

void A() {
    int n;
    cin >> n;
    map<int,int> mpp;
    int max1 = -1;
    int max2 = -1; //6 4 2

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        mpp[temp]++;

        if (temp > max1) {
            max2 = max1;
            max1 = temp;
        }
        else if (temp > max2) {
            max2 = temp;
        }
    }

    int x = max1;
    int y = max2;

    for (int i = 0; i < n-2; i++) {
        int t = x%y;
        if (mpp[t] == 0) {
            x = -1;
            break;
        }
        else {
            x = y;
            y = t;
        }
    }
    if (x == -1) {
        cout << -1 << endl;
        return;
    }

    cout << max1 << " " << max2 << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        A();
    }
}

