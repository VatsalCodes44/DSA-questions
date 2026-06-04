// Input: n = 3
// Output: ["000", "001", "010", "100", "101"]
// Explanation: All strings are of length 3 and do not contain consecutive 1s

#include <bits/stdc++.h>

using namespace std;

void generateBinaryStrings(string str, int i, int n) {
    if (i == n) {
        cout << str << endl;
        return;
    }
    if (i == 0) {
        generateBinaryStrings("0", i+1, n);
        generateBinaryStrings("1", i+1, n);
    }
    else {
        if (str[i-1] == '1') {
            string temp = str;
            temp.push_back('0');
            generateBinaryStrings(temp, i+1,n);
        }
        else {
            string temp = str;
            temp.push_back('0');
            generateBinaryStrings(temp, i+1,n);
            temp = str;
            temp.push_back('1');
            generateBinaryStrings(temp, i+1,n);
        }
    }
}

int main () {
    generateBinaryStrings("", 0, 3);
}