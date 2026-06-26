#include <bits/stdc++.h>

using namespace std;

string decimalToBinary(int n) {
    string str = "";
    while (n) { // O(logn)
        str.push_back(n%2 == 0 ? '0' : '1'); // O(1)
        n /= 2;
    }
    reverse(str.begin(),str.end()); // O(n/2)
    return str;
}

int binaryToDecimal(string binary) {
    int n = 0;
    for (int i = 0; i < binary.size(); i++) {
        n += binary[i] == '1' ? (1 << binary.size()-i-1) : 0;
    }
    return n;
}

int main () {
    string str = "1101";
    cout << binaryToDecimal(str) <<endl;
}