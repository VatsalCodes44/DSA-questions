#include <bits/stdc++.h>

using namespace std;
vector<int> factors (int n) {
    vector <int> ans;
    for (int i = 2; i <= n; i++) {
        while (n%i == 0) {
            ans.push_back(i);
            n/=i;
        }
        if (n == 1) break;
    }
    if (ans.size() == 0) {
        ans.push_back(n);
    }
    return ans;
}
vector<vector<int>> primeFactors(vector<int>& queries) {
    vector<vector<int>> ans;
    for (auto i : queries) {
        ans.push_back(factors(i));
    }
    return ans;
}

int main () {
    vector <int> arr = {7, 12, 18, 6};
    int x = 0;
    for (auto i : primeFactors(arr)) {
        cout << arr[x] << " : ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
        x++;
    }
}