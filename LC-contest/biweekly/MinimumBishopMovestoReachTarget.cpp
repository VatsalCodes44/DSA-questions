#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if ((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2) return -1;
        int sr = source[0] - 1;
        int sc = source[1] - 1;
        int tr = target[0] - 1;
        int tc = target[1] - 1;  

        // checking lower left Diagonal
        if ((tr+tc) == (sr+sc)) return 1;

        // checking upper left diagonal
        if ((7 + tc - tr) == (7 + sc - sr)) return 1;

        // checking upper right diagonal 
        if ((14 - (tc + tr)) == (14 - (sc + sr))) return 1;

        // checking lower right diagonal 
        if ((7 + tr - tc) == (7 + sr - sc)) return 1;

        return 2;
    }
};

int main () {
    Solution s;
    vector<int> src = {1,1};
    vector<int> tar = {4,6};
    cout << s.minBishopMoves(src, tar);
}