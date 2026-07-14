#include <bits/stdc++.h>

using namespace std;

void f() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n+1,0);
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int j1 = i-x;
        int j2 = i+x;
        int j3 = i+y;
        int j4 = i-x;

        if (j1 >= 0) {
            if (j1 < i && arr[j1] > arr[i]) {
                int temp = arr[i];
                
            }
        }
    }
    cout << "YES" << endl;
    
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) f();
}