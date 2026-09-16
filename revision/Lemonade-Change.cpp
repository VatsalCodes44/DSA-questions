#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5 = 0; 
        int b10 = 0;
        int b15 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                b5++;
            }
            else if (bills[i] == 10) {
                if (b5 >= 1 ) {
                    b5--;
                    b10++;
                }
                else return false;
            }
            else {
                if (b10 >= 1 && b5 >= 1) {
                    b10--;
                    b5--;
                }
                else if (b5 >= 3) b5-=3;
                else return false;
            }
        }

        return true;
    }
};