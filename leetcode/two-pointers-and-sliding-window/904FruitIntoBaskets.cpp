#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type1 = -1;
        int type2 = -1;
        int maxx = 0;
        int countType1 = 0;
        int countType2 = 0;
        int l = 0, r = 0;
        while (r < fruits.size()) {
            if ((type1 == -1 && fruits[r] != type2) || fruits[r] == type1) {
                type1 = fruits[r];
                countType1++;
            }
            else if ((type2 == -1 && fruits[r] != type1) || fruits[r] == type2) {
                type2 = fruits[r];
                countType2++;
            }
            else {
                while (countType1 && countType2) {
                    if (fruits[l] == type1) {
                        countType1--;
                        l++;
                        if (countType1 == 0) {
                            type1 = fruits[r];
                            countType1++;
                            break;
                        }
                    }
                    else {
                        countType2--;
                        l++;
                        if (countType2 == 0) {
                            type2 = fruits[r];
                            countType2++;
                            break;
                        }
                    }
                }
            }

            maxx = max(maxx, countType1 + countType2);
            r++;
        }
        return maxx;
    }
};
int main () {
    Solution s;
    vector<int> arr = {6,2,1,1,3,6,6};
    cout << s.totalFruit(arr);
}