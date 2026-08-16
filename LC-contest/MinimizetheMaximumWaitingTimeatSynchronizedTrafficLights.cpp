#include <bits/stdc++.h>

using namespace std;

int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
    int maxGreen = *max_element(lights.begin(), lights.end());
    int panelty = 0;
    for (auto i: arrivalTime) {
        if (i%period >= maxGreen){
            panelty = max(panelty, period-i%period);
        }
    }
    return panelty;
}

int main () {
    vector<int> lights = {2}, arrivalTime = {2,3,4,5,6};
    cout << minPenalty(5, lights, arrivalTime);
}