#include <bits/stdc++.h>

using namespace std;

void f() {
    int a,b, A, B,x;
    cin >> A >> B >> x;

    if (A == B) {
        cout << 0 << endl;
        return;
    }
    if (A == B+1) {
        cout << 1 << endl;
        return;
    }

    a = A > B ? A : B;
    b = A < B ? A : B;

    int count = 0;

    while (a != b) {
        if (a-1 == b) {
            b++;
            count++;
        } 
        else if (a+1 == b) {
            a++;
            count++;
        }
        else if (a > b) {
            a/=x;
            count++;
        }
        else {
            b/=x;
            count++;
        }
    }
    cout << count << endl;
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        f();
    }
}