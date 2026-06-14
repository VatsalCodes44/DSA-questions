#include <bits/stdc++.h>

using namespace std;

void permutations(vector<char> &arr, string& str, int i) {
    if (i == arr.size()) {
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int j = i; j < arr.size(); j++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        permutations(arr, str, i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
}

int main () {
    vector<char> arr = {'a', 'b', 'c'};
    string str = "";
    permutations(arr, str, 0);
}