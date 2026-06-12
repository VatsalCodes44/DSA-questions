#include <bits/stdc++.h>

using namespace std;

void f() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
        if(min > arr[i]) {
            min = arr[i];
        }
    }

    cout << max + 1 - min << endl;

}

int main () {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        f();
    }
}