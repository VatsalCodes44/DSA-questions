#include <bits/stdc++.h>

using namespace std;

void appproach1(vector<int> &arr, vector<int> &freq, string &ans) {
    if (ans.size() == arr.size()) {
        cout << ans << endl;
        return;
    }

    for (int j = 0; j < freq.size(); j++) {
        if (freq[j]) {
            freq[j]--;
            ans.push_back('0'+arr[j]);
            appproach1(arr, freq, ans);
            ans.pop_back();
            freq[j]++;
        }
    }
}

void approach2 (vector<int> arr, int i) {
    if (i == arr.size()) {
        for (auto x: arr) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        approach2(arr, i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main () {
    vector <int> arr = {1,2,3};
    vector <int> freq = {1,1,1};
    string ans = "";
    appproach1(arr, freq, ans);
    // approach2(arr, 0);
    
}