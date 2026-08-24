#include <bits/stdc++.h>

using namespace std;


void toh(int n, char initial, char middle, char final) {
    if (n == 0) return;
    toh(n-1, initial, final, middle);
    cout << initial << " to " << final << endl;
    toh(n-1, middle, initial, final);
}
int main () {
    toh(3, 'a', 'b', 'c');
}