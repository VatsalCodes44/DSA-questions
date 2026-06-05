#include <bits/stdc++.h>

using namespace std;

void ans (int n) {
    if ((n-1)%3 == 0 || (n+1)%3 == 0){
        cout << "First" << endl;
        return;
    }
    
    cout << "Second" << endl;
}

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ans(n);
    }
}