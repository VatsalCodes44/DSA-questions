#include <bits/stdc++.h>

using namespace std;

int elevatorRequests(int n, vector<int>& requests) {
    int sum = 0;
    int prev = 0;
    for (auto i: requests) {
        sum += abs(i-prev);
        prev = i;
    }
    return sum;
}

int main () {
    vector <int> arr = {2,0,0};
    cout << elevatorRequests(4, arr);
}