#include <bits/stdc++.h>

using namespace std;

void minSteps(string str) {
    int mover = 0;
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            mover++;
        }
        else if (str[i] == '#') {
            if (mover == 1) {
                ones++;
            }
            else if (mover == 2) {
                twos++;
            }
            else if (mover > 2) {
                cout << 2 << endl;
                return;
            }
            mover = 0;
        }
    }

    if (mover == 1) {
        ones++;
    }
    else if (mover == 2) {
        twos++;
    }

    if (mover > 2) {
        cout << 2 << endl;
        return;
    }

    cout << ones+twos*2 << endl;
    return;
}

int main () {
    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        int x;
        cin >> x;

        string str;
        cin >> str;

        minSteps(str);
    }
}

