#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        map<int, int> mpp;
        int sum = 0;
        int minn = INT_MAX;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] == '0' ? 0 : 1;

            if (sum == k) {
                if (minn > i+1) {
                    l = 0; r = i;
                    minn =  i+1;
                }
                else if (minn == i+1) {
                    string a = s.substr(l, minn);
                    string b = s.substr(0, i+1);
                    if (b < a) {
                        l = 0;
                        r = i;
                    }
                }
            }
            if (mpp.find(sum-k) != mpp.end()) {
                if (minn > i-mpp[sum-k]) {
                    l = mpp[sum-k]+1;
                    r = i;
                    minn = r-l+1;
                }
                else if (minn == i-mpp[sum-k]) {
                    string a = s.substr(l, minn);
                    string b = s.substr(mpp[sum-k]+1, i-mpp[sum-k]);
                    if (b < a) {
                        l = mpp[sum-k]+1;
                        r = i;
                    }
                }
            }

            mpp[sum] = i;
        }

        if (minn == INT_MAX) return "";

        string temp;
        for (int i = l; i <= r; i++) {
            temp += s[i];
        }
        return temp;
    }
};

int main () {
    cout << ("111111100011111" < "111111000111111") << endl;
    Solution s;
    cout << (s.shortestBeautifulSubstring("0111111100011111101", 12) == "111111000111111") << endl;
}