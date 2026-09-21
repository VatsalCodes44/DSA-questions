#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& arr, int i) {
    if (i == arr.size()) {
        for (auto i: arr) cout << i;
        cout << endl;
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        if (j > i && arr[j] == arr[j-1]) continue;
        swap(arr[i],arr[j]);
        f(arr, i+1);
        swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> arr = {1,2,2,3,3};
    f(arr,0);
}