#include <bits/stdc++.h>

using namespace std;

void bruteForce(vector<int> &arr, int k) {
    int sum = k;
    int len = 0;
    int maxLen = 0;

    int i = 0;
    while ( i < arr.size()) {
        int j = i; 
        while (j < arr.size()) {
            sum -= arr[j];
            len++;
            
            if (sum == 0) {
                if (len > maxLen) {
                    maxLen = len;
                }
                sum = k;
                len = 0;
                break;
            }
            else if (sum < 0) {
                sum = k;
                len = 0;
                break;
            }
            j++;
            
        }
        i++;
    }

    cout << maxLen << endl;
}

int optimalApproach(vector<int> & arr, int k) {
    
}


int main () {
    vector<int> arr = {10, 5, 2, 7, 1};
    int k = 15;
    cout << optimalApproach(arr, k) << endl;
}