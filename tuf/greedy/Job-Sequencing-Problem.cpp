#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
	static bool comparator(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
	vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
		// code here
		vector<pair<int, int>> jobs;
		jobs.reserve(deadline.size());
		
		for (int i = 0; i < deadline.size(); i++) {
		    jobs.push_back({deadline[i], profit[i]});
		}
		
		sort(jobs.begin(), jobs.end(), comparator);
		
		int totalProfit = 0;
		int totalJobs = 0;
		int t = 0;

		for (int i = 0; i < jobs.size(); i++) {
		    if (jobs[i].first > t) {
		        t++;
		        totalProfit += jobs[i].second;
		        totalJobs++;
		    }
		}
		
		vector <int> ans = {totalJobs, totalProfit};
		return ans;
	}
};
