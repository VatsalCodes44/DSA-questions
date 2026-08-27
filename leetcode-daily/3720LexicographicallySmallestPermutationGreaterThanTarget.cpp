#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string f(string& str, string& target, string& curr, map<char, int>& mpp) {
        if (curr.size() && curr[0] < target[0]) return "";
        if (curr.size() == str.size()) {
            if (curr > target) return curr;
            return "";
        }

        for (auto i: mpp) {
            if (i.second) {
                curr += i.first;
                mpp[i.first]--;
                string ans = f(str, target, curr, mpp);
                if (ans != "") return ans;
                curr.pop_back();
                mpp[i.first]++;
            }
        }
        return "";
    }
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mpp;
        string curr = "";
        for (auto i: s) mpp[i]++;

        return f(s, target, curr, mpp);
    }
};