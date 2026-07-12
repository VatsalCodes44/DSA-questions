#include <bits/stdc++.h>

using namespace std;

bool f(vector<int> & arr, int i, int count) {
    if (i == arr.size()) {
        if (count == 1) {
            return false;
        }
        return true;
    }

    if(!f(arr, i+1, count)) return false;

    count += (i+1)*arr[i];
    if (!f(arr, i+1, count)) return false;
    count -= (i+1)*arr[i];

    count -= (i+1)*arr[i];
    if (!f(arr, i+1, count)) return false;
    count += (i+1)*arr[i];

    return true;
}

void f1(int n) {
    vector <int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }

    do {
        if (f(arr, 0 , 0)) {
            for (auto j: arr) {
                cout << j << " ";
            }
            cout << endl;
            break;
        }
    } while (next_permutation(arr.begin(), arr.end()));
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        f1(n);
    }
}