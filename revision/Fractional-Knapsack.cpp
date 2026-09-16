#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		// code here
		vector<pair<int, int>> arr;
		arr.reserve(val.size());
		
		for (int i = 0; i < val.size(); i++) {
			arr.push_back({val[i], wt[i]});
		}
		
		sort(arr.begin(), arr.end(), [](pair<int, int>&a, pair<int, int>&b) {
			return (double(a.first)/a.second) > (double(b.first)/b.second);
		});
		
		double maxVal = 0;
		
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].second >= capacity) {
				maxVal += ((double(arr[i].first)/double(arr[i].second))*capacity);
				break;
			}
			else {
				maxVal += double(arr[i].first);
				capacity -= double(arr[i].second);
			}
		}
		
		return maxVal;
	}
};


int main () {
    Solution s;
    vector<int> val = {500};
    vector<int> wt = {30};
    cout << s.fractionalKnapsack(val, wt, 10);
}