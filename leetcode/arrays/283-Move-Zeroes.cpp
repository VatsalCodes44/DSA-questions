#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& arr) {
    int i = 0; 
    int j = 0;
    while (i < arr.size() && j < arr.size()) {
        if (arr[i] == 0) {
            i++;
            continue;
        }
        else if (arr[j] != 0) {
            j++;
            continue;
        }
        else if (i < j) {
            i = j+1;
        }
        else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
            i++;
        }
    }
}

int main () {
    vector <int> arr = {1, 0};
    moveZeroes(arr);

    for (auto i: arr) {
        cout << i << " ";
    }
}