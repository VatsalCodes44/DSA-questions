#include <bits/stdc++.h>

using namespace std;

string decimalToBinary(int n) {
    string str = "";
    while (n) {
        str.push_back(n%2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main () {
    cout << decimalToBinary(13);
}