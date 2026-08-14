#include <bits/stdc++.h>

using namespace std;

bool checkSubarraySum(vector<int>& arr, int k) {
    int p = 0;
    map<int, int> pr;
    for (int i = 0; i < arr.size(); i++) {
        p+=arr[i];
        // if (arr[i]==0) continue;
        if (i>0 && p%k==0) return true;
        if (pr.find(p%k) != pr.end()){
            if (i-pr[p%k]-1>0) return true;
        } 
        else pr[p%k] = i;
    }
    return false;
}

int main () {
    vector<int> arr = {5,0,0,0};
    cout << checkSubarraySum(arr, 3);
}