#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n,x;
        cin >> n >> x;

        int lastStation = 0;
        int maxDist = 0;

        for (int j = 1; j<=n; j++){
            int station;
            cin >> station;
            if (j == 1) {
                if (station*2 > maxDist) {
                    maxDist = station*2;
                }
                lastStation = 0;
            }
            if (j == n) {
                if ((x-station)*2 > maxDist) {
                    maxDist =(x-station)*2;
                }
            }
            else {
                if (station-lastStation > maxDist) {
                    maxDist = station-lastStation;
                }
                lastStation = station;
            }
        }
        cout << maxDist << endl;

    }
}