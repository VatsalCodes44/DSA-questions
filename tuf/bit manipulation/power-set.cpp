#include <bits/stdc++.h>

using namespace std;

int main () {
    string str = "abc";
    int n = str.size();

    for (int i = 0; i <= (1 << n)-1; i++) {
        string ans = "";

        for (int j = 0; j <=n-1; j++){
            if (i & (1<<j)) {
                ans.push_back(str[j]);
            }
        }
        cout << ans << endl;
    }
}