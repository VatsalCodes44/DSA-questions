#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    static bool comparator(pair<int, int> a, pair<int, int> b) {
        return a.second <= b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<pair<int, int>> arr;
        arr.reserve(start.size());

        for (int i = 0; i < start.size(); i++) {
            arr.push_back({start[i], end[i]});
        }

        sort(arr.begin(), arr.end(), comparator);

        int count = 0;
        int lastMeetingIdx = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) count++;
            else if (arr[lastMeetingIdx].second < arr[i].first) {
                count++;
                lastMeetingIdx = i;
            }
        }
        return count;
    }
};

int main () {
    Solution s;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end =   {2, 4, 6, 7, 9, 9};

    cout << s.maxMeetings(start, end) << endl;
}