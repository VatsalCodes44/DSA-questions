#include <bits/stdc++.h>
#include <cmath>

using namespace std;

pair<long long, long long> generatePalindrome (long long n) {
    long long x = n;
    long long y = n;

    while (y) {
        long long temp = y%10;
        x = x*10 + temp;
        y /= 10;
    }

    long long z = n;
    y = n/10;
    while (y) {
        long long temp = y%10;
        z = z*10 + temp;
        y /= 10;
    }
    pair <long long, long long> p(z,x);
    return p;
}

void B(vector <long long> &arr) {
    long long n;
    cin >> n;
    if (n == 10) {
        cout << -1 << endl;
        return;
    }

    if (n < 12) {
        cout << n << " " << 0 << endl;
        return;
    }
    if (n == 12) {
        cout << 0 << " " << 12 << endl;
        return;
    }
    for (long long i : arr) {
        long long a = i;

        long long b = n-a;
        if (b >= 0 && b%12 == 0 && a+b == n) {
            cout << a << " " << b << endl;
            return;
        }
        if (a>n) break;
    }
    cout << -1 << endl;
}

int main () {
    int t;
    cin >> t;
    vector<long long> arr;
    for (long long i = 0; i <= 1000000000; i++) {
        pair<long long, long long> p = generatePalindrome(i);
        arr.push_back(p.first);
        arr.push_back(p.second);
    }

    for (int i = 0; i < t; i++) {
        B(arr);
    }
    // long long x = 12;
    // pair<long long, long long> p = generatePalindrome(x);
    // cout << p.first << " " << p.second;
}

