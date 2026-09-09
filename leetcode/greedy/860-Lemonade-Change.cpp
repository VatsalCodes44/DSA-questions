#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5 = 0, b10 = 0, b20 = 0;

        for (int j = 0; j < bills.size(); j++) {
            int i = bills[j];
            if (i == 20) {
                b20++;
                if (b10 >= 1 && b5 >= 1) {
                    b10--;
                    b5--;
                }
                else if (b5 >= 3) {
                    b5 -= 3;
                }
                else return false;
            }
            else if (i == 10) {
                b10++;
                if (b5 >= 1) {
                    b5--;
                }
                else return false;
            }
            else {
                b5++;
            }
        }
        return true;
    }
};