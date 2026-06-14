#include <bits/stdc++.h>

using namespace std;

int f(vector <int> arr, int n) {
    if (n == 0) {
        return arr[0];
    }
    else {
        int minimum = f(arr, n-1);
        return arr[n] < minimum ? arr[n] : minimum;
    }
}

int main () {
    vector <int> arr = {11,2,3,4,5};
    cout << f(arr,5-1) << endl;
}