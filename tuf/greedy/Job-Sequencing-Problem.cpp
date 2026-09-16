#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
	static bool comparator(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
	vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
		// code here
		vector<pair<int, int>> jobs;
		jobs.reserve(deadline.size());
		
		int maxDeadline = -1;
		
		for (int i = 0; i < deadline.size(); i++) {
		    maxDeadline = max(maxDeadline, deadline[i]);
		    jobs.push_back({deadline[i], profit[i]});
		}
		
		sort(jobs.begin(), jobs.end(), comparator);
		
		vector<int> endDays(maxDeadline+1, -1);
		
		int p = 0;
		int c = 0;
		for (int i = 0; i < jobs.size(); i++) {
		    int d = jobs[i].first;
		    while (d >= 1 && endDays[d] != -1) d--;
		    
		    if (d >= 1) {
		        endDays[d] = 1;
		        p += jobs[i].second;
		        c++;
		    }
		}
		
		vector<int> ans; ans.push_back(c); ans.push_back(p);
		return ans;
		
	}
};

int main () {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    Solution s;
    s.jobSequencing(deadline, profit);
}