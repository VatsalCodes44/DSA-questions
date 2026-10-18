#include <bits/stdc++.h>

using namespace std;

int strToInt (string  str, int ans, int i, int sign) {
    if (i >= str.size()) return ans*sign;
    if(str[i] == '0') {
        if (i < str.size()-1 && (str[i+1] < '0' || str[i+1] > '9')) {
            return (ans*10+0) * sign;
        }
    }
    if (str[i] == ' ') {
        if (ans == 0) {
            return strToInt(str, ans, i+1, sign);
        }
        else return ans*sign;
    }

    if (str[i] == '-' || str[i] == '+') {
        if ( i < str.size()-1 && ans == 0 && str[i+1] >= '0' && str[i+1] <= '9') {
            sign = str[i] == '-' ? -1 : 1;
            return strToInt(str, ans, i+1, sign);
        }
        else {
            return ans * sign;
        }
    }
    if (str[i] < '0' || str[i] > '9') {
        return ans * sign;
    }
    else {
        if ((1LL*ans*10 + (str[i] - '0'))*sign >= INT_MAX) return INT_MAX;
        if ((1LL*ans*10 + (str[i] - '0'))*sign <= INT_MIN) return INT_MIN;
        ans = ans*10 + (str[i] - '0');
        return strToInt(str, ans, i+1, sign);
    }
}

int main () {
    string str = "     -11009215950h";
    cout << strToInt(str, 0, 0, 1) << endl;
}