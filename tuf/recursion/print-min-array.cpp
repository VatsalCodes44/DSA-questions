#include <bits/stdc++.h>

using namespace std;

int f(vector <int> arr, int n) {
    if (n == arr.size()-1) {
        return arr[arr.size()-1];
    }
    else {
        int minimum = f(arr, n+1);
        return arr[n] < minimum ? arr[n] : minimum;
    }
}

int main () {
    vector <int> arr = {11,2,3,4,5};
    cout << f(arr, 0) << endl;
}