#include <bits/stdc++.h>

using namespace std;
int findRangeXOR(int l,int r){
    //your code goes here
    int ans = 0;
    int a = r%4;
    int b = r/4;
    if (a == 1) ans = 1;
    if (a == 2) {
        ans = 3 + (4*b);
    }
    if (a == 3) ans = 0;
    if (a == 0) {
        ans = 4*b;
    }
    // cout << "N: " << r << " is " << ans << endl; 

    int ans2 = 0;
    int x = l-1;
    a = x%4;
    b = x/4;
    if (a == 1) ans2 = 1;
    if (a == 2) {
        ans2 = 3 + (4*b);
    }
    if (a == 3) ans2 = 0;
    if (a == 0) {
        ans2 = 4*b;
    }
    // cout << "N: " << x << " is " << ans2 << endl; 
    return ans^ans2;

}
int main () {
    cout << findRangeXOR(1,3);
}