#include <bits/stdc++.h>

using namespace std;

void permutations(vector<int> &arr, vector<int> &freq, string &ans) {
    if (ans.size() == arr.size()) {
        cout << ans << endl;
        return;
    }

    for (int j = 0; j < freq.size(); j++) {
        if (freq[j]) {
            freq[j]--;
            ans.push_back(arr[j]);
            permutations(arr, freq, ans);
            ans.pop_back();
            freq[j]++;
        }
    }
}

int main () {
    vector <int> arr = {'1','2','3'};
    vector <int> freq = {1,1,1};
    string ans = "";
    permutations(arr, freq, ans);
    
}