#include <bits/stdc++.h>

using namespace std;

void cS3(int num, int k, int n, vector<vector<int>>& ansArr, vector<int>& ans) {
    if (n < 0) return;
    
    if (ans.size() == k) {
        if (n==0) {
            ansArr.push_back(ans);
        }
        return;
    }
    if (num > 9)return;

    cS3(num+1, k, n, ansArr, ans);

    n-=num;
    ans.push_back(num);
    cS3(num+1, k, n, ansArr, ans);
    ans.pop_back();
    n+=num;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ansArr;
    vector<int> ans;
    cS3(1, k, n, ansArr, ans);
    return ansArr;
}