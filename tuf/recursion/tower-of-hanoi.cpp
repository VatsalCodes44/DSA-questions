#include <bits/stdc++.h>

using namespace std;

void toh(int n, char from, char through, char to) {
    if (n == 0) {
        return;
    }
    toh(n-1, 'A', 'C', 'B');
    cout << "move " << from << " to " << to << endl;
    toh(n-1, 'B', 'A', 'C');
}

int main () {
    toh(3, 'A', 'B', 'C');
}