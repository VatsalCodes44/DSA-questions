#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;

        for (int i= 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min++;
                max++;
            }
            else if (s[i] == ')') {
                if (min >= 1) min--;
                if (max >= 1) max--;
                else return false;
            }
            else {
                if (min >= 1) min--;
                max++;
            }
        }
        if (min == 0) return true;
        return false;
    }
};