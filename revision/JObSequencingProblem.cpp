#include <bits/stdc++.h>

using namespace std;

class Solution{  
  public:  
    vector<int> JobScheduling(vector<vector<int>>& jobs) { 
        //your code goes here
        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
            if (a[2] == b[2]) return a[1] < b[1];
            return a[2] > b[2];
        });

        int maxDeadline = 0;

        for (int i = 0; i < jobs.size(); i++) {
            maxDeadline = max(maxDeadline, jobs[i][1]);
        }

        vector<int> sequence(maxDeadline, -1);

        for (int i = 0; i < jobs.size(); i++) {
            int j = jobs[i][1];
            while (sequence[j] == -1) j--;
            if (j > 0) {
                sequence[j] = i;
            }
        }

        int count = 0;
        int profit = 0;

        for (int i = 1; i < sequence.size(); i++) {
            if (sequence[i] != -1) {
                count++;
                profit += jobs[sequence[i]][2];
            }
        }

        vector<int> ans = {count, profit};
        return ans;
    } 
};
int main () {
    vector<vector<int>> arr = { {1, 4, 20} , {2, 1, 10} , {3, 1, 40} , {4, 1, 30} };
    Solution s;
    cout << s.JobScheduling(arr)[1];
}