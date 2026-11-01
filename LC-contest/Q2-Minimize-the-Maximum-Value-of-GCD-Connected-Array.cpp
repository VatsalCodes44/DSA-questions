#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;
        long long ans = LONG_LONG_MAX;
        if (value % 2 == 0) {
            if (index == 1 && value - 2 == 0) return -1ll;
            if (index > 0 && ( (long long)value - ((long long)index)*2) <= 0) return -1;
            ans = (long long)value + ((long long)n - (long long)index - 1ll)*2;
        }
        else {
            int x = value;
            for (int i = 3; i <= sqrt(value); i+=2) {
                if (value%i == 0) {
                    x = i;
                    break;
                }
            }

            if (index == 0) {
                value*=2;
                index++;
                return (long long)value + ((long long)n - (long long)index - 1ll)*2;
            }
            if (index == n-1) {
                index--;
                value-=x;
                if (index == 1 && value - x == 0) return -1ll;
                if (index > 0 && ( (long long)value - ((long long)index)*x) <= 0) return -1;
                if (index == 0 && value <= 0) return -1;
                else return value+x;
            }
            if (index == 1 && value - x == 0) return -1ll;
            if (index > 1 && ( (long long)value-x - ((long long)index-1)*2) <= 0) return -1;

            value+=x;
            index++;

            ans = (long long)value + ((long long)n - (long long)index - 1ll)*2;
        }
        return ans;
    }
};

int main () {
    Solution s;
    cout << s.minimumMaxValue(4, 2, 3);
}
