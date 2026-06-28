#include <bits/stdc++.h>

using namespace std;

void f() {
    int n,c;
    cin >> n >> c;

    vector<int> a,b;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    int justDec = 0;

    bool rearrangeNeeded = false;
    int app1 = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) rearrangeNeeded = true;
        if (a[i] > b[i]) justDec += a[i]-b[i];
    }

    if (!rearrangeNeeded) app1 = justDec;

    int app2 = c;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cout << -1 << endl;
            return;
        }
        while (a[i] > b[i]) {
            a[i]--;
            app2++;
        }
    }

    if (app1 < app2) {
        cout << app1 << endl;
    }
    else {
        cout << app2 << endl;
    }

    
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        f();
    }
}