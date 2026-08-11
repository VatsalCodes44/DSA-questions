#include <bits/stdc++.h>

using namespace std;

int f(vector<int>& arr, int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (i <= h-1 && arr[i] <= pivot) i++;
        while (j >= l+1 && arr[j] > pivot) j--;

        if (i<j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void qS(vector<int>& arr, int l, int h) {
    if (l >= h) return;
    int partitionIdx = f (arr, l, h);
    qS(arr, l, partitionIdx-1); 
    qS(arr, partitionIdx+1, h); 
}

int main () {
    vector <int> arr = {5,4,3,2,1};
    qS(arr, 0, arr.size()-1);
    for (auto i: arr) {
        cout << i << " ";
    }

}