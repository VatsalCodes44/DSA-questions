#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& arr) {
    int i = 0, j = 0; 
    int count = 1;
    while (j < arr.size()) {
        if (arr[i] == arr[j]) {
            j++;
        }
        else {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
            j++;
        }
    }
    return count;
}

int main () {
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(arr) << endl;
}