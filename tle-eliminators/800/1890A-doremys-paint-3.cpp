#include <bits/stdc++.h>

using namespace std;

void doremysPaint() {
    int n;
    cin >> n;

    int x = -1;
    int y = -1;
    int z = -1;

    int countX = 0;
    int countY = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (x == -1) {
            x = temp;
            countX++;
            continue;
        }
        else if (temp == x) {
            countX++;
            continue;
        }
        else if (y == -1) {
            y = temp;
            countY++;
            continue;
        }
        else if (temp == y) {
            countY++;
            continue;
        } 
        else {
            z = temp;
        }
    }
    if (z != -1) {
        cout << "No" << endl;
        return;
    }


    if (countX == countY || countX-1 == countY || countX == countY-1 || countX == 0 || countY == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main () {
    int t;
    cin>> t;

    for (int i = 0; i < t; i++) {
        doremysPaint();
    }
}