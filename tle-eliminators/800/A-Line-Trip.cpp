#include <bits/stdc++.h>

using namespace std;

void f() {
    int n, x;
    cin >> n >> x;
    vector<int> stations;
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        if (stations.empty()) {
            maxDist = y;
        } else {
            maxDist = max(maxDist, y - stations.back());
        }

        if (i == n - 1) {
            maxDist = max(maxDist, 2 * (x - y));
        }

        stations.push_back(y);
    }
    cout << maxDist << endl;
}
int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        f();
    }
}