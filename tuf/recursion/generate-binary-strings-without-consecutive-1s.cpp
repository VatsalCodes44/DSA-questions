// Input: n = 3
// Output: ["000", "001", "010", "100", "101"]
// Explanation: All strings are of length 3 and do not contain consecutive 1s

#include <bits/stdc++.h>

using namespace std;

void x(int n, string &ans) {
    if (ans.size() == n) {
        cout << ans << endl;
        return;
    }
    ans.push_back('0');
    x(n, ans);
    ans.pop_back();
    
    if (ans.back() != '1'){
        ans.push_back('1') ;
        x(n, ans);
        ans.pop_back();
    }
    

}

int main () {
    string str = "";
    x(3, str);
}
