#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >>t;
    
    for (int i = 0; i < t; i++) {
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);
        bool sorted = true;
        for (int j = 0; j <n; j++) {
            cin >> arr[j];
            if (j > 0) {
                if (arr[j-1] > arr[j]){
                    sorted = false;
                }
            }
        }

        if (sorted) {
            cout << "YES" << endl;
            continue;
        }
        if (k>=2) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}