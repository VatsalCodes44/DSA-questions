#include <bits/stdc++.h>

using namespace std;

int f(string& str, int i, int x, int y) {
    if (i == str.size()) {
        return abs(0 - x) + abs(0 - y);
    }
    if (str[i] == '_') {
        int ans = 0;
        str[i] = 'L';
        int max1 = f(str, i+1, x-1, y);
        str[i] = '_';
        ans = max1;

        str[i] = 'R';
        int max2 = f(str, i+1, x+1, y);
        str[i] = '_';
        ans = max(ans, max2);

        str[i] = 'U';
        int max3 = f(str, i+1, x, y+1);
        str[i] = '_';
        ans = max(ans, max3);

        str[i] = 'D';
        int max4 = f(str, i+1, x, y-1);
        str[i] = '_';
        ans = max(ans, max4);

        return ans;
    }
    else {
        if (str[i] == 'L') {
            return f(str, i+1, x-1, y);
        }
        else if (str[i] == 'R') {
            return f(str, i+1, x+1, y);
        }
        else if (str[i] == 'U') {
            return f(str, i+1, x, y+1);
        }
        else {
            return f(str, i+1, x, y-1);
        }
    }
}
int maxDistance(string moves) {
    return f(moves, 0, 0, 0);
}

int main () {
    string moves = "UUUR_DLU_L_LUURRRD_RDU____L__LDL_UR_U_L_DLL_RRR__RDDDUDUUURLUD__DDDU";
    cout << maxDistance(moves) << endl;
}