#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int a = 0, b = 0, c = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] == 'a') a++;
            else if (s[r] == 'b') b++;
            else if (s[r] == 'c') c++;
            while (a > 1 || b > 1 || c > 1) {
                if (a > 1 && s[l] == 'a') a--;
                else if (b > 1 && s[l] == 'b') b--;
                else if (c > 1 && s[l] == 'c') c--;
                else break;
                l++;
            }
            if (a && b && c) {
                count += l+1;
            }
            r++;
        }
        return count;        
    }
};