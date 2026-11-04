#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5 = 0;
        int d10 = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                d5++;
            }
            else if (bills[i] == 10) {
                d10++;
                if (d5 > 0) d5--;
                else return false;
            }
            else {
                int sum = 15;
                if (d10 > 0) {
                    sum -= 10;
                    d10--;
                }
                
                if (sum == 5) {
                    if (d5 > 0) d5--;
                    else return false;
                }
                else if (sum == 15) {
                    if (d5 >= 3) d5 -= 3;
                    else return false;
                }
            }
        }
        return true;
    }
};