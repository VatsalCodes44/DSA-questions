#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  
    void sort(vector<int> &v, vector<int> &w, int l, int r, int mid) {
        vector<int> ansArr1;
        ansArr1.reserve(r-l+1);
        vector<int> ansArr2;
        ansArr2.reserve(r-l+1);
        
        int i = l;
        int j = mid+1;
        
        while (i <= mid && j <= r) {
            if ((double)v[i]/w[i] <= (double)v[j]/w[j]) {
                ansArr1.push_back(v[i]);
                ansArr2.push_back(w[i]);
                i++;
            }
            else {
                ansArr1.push_back(v[j]);
                ansArr2.push_back(w[j]);
                j++;
            }
        }
        
        while (i <= mid) {
            ansArr1.push_back(v[i]);
            ansArr2.push_back(w[i]);
            i++;
        }
        while (j <= r) {
            ansArr1.push_back(v[j]);
            ansArr2.push_back(w[j]);
            j++;
        }
        
        for (int i = 0; i < ansArr1.size(); i++) {
            v[i+l] = ansArr1[i];
            w[i+l] = ansArr2[i];
        }
    }
    void ms(vector<int> &v, vector<int> &w, int i, int j) {
        if (i == j) return;
        
        int mid = (i+j)/2;
        ms(v, w, i, mid);
        ms(v,w, mid+1, j);
        sort(v, w, i, j, mid);
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double ans = 0;
        ms(val, wt, 0, val.size()-1);
    
        for (int i = val.size()-1; i >= 0; i--) {
            if (wt[i] <= capacity) {
                ans += val[i];
                capacity -= wt[i];
            }
            else {
                double frac = (double)capacity/wt[i];
                ans += (double)val[i]*frac;
                break;
            }
        }
        return ans;
        
    }

};
