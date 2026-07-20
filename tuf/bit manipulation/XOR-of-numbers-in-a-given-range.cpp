#include <bits/stdc++.h>

using namespace std;
int xorTillN(int n) {
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n+1;
    else if (n%4 == 2) return n+1;
    if (n%4 == 3) return 0;
    else return n;
}
int findRangeXOR(int l, int r) {
    return xorTillN(r)^xorTillN(l-1);
}
int main () {
    cout << findRangeXOR(1,3);
}