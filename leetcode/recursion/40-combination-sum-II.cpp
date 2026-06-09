#include <bits/stdc++.h>

using namespace std;

void cS(vector<int> &arr, vector<vector<int>> &ansArr, int i, int k, vector<int> &ans) {
    if (k < 0) return;
    if (k == 0) {
        ansArr.push_back(ans);
        return;
    }
    if (i == arr.size()) return;

    int last = -1;
    for (int j = i; j < arr.size(); j++) {
        if (arr[j] != last) {
            k -= arr[j];
            ans.push_back(arr[j]);
            cS(arr, ansArr, j+1, k, ans);
            ans.pop_back();
            k += arr[j];

            last = arr[j];
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> freq(51, 0);
    for (int i: candidates) {
        freq[i]++;
    }
    int x = 0;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j < freq[i]; j++) {
            candidates[x] = i;
            x++;
        }
    }
    vector<vector<int>> ansArr;
    vector<int> ans;
    cS(candidates, ansArr, 0, target, ans);
    return ansArr;        
}

int main () {
    vector<int> candidates = {4, 9, 2, 5, 1};
    vector<vector<int>> arr = combinationSum2(candidates, 10);

    for (auto i: arr) {
        for (int j = 0; j < i.size(); j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}
