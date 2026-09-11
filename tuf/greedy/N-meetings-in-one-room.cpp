#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<pair<int, int>> arr;
        arr.reserve(start.size());
        
        for (int i = 0; i < start.size(); i++) {
            arr.push_back({start[i], end[i]});
        }
    }
};

int main () {
    Solution s;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << s.maxMeetings(start, end) << endl;
}