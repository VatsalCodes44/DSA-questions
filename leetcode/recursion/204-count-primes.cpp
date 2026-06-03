#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n+1, true);
    int count = 0;

    for (int i = 2; i*i < n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j < n; j+=i) {
                    isPrime[j] = false;
            }
        }
    }


    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }

    return count;
}


int main () {
    int n = 1000;
    cout << countPrimes((int)(1e6)) << endl;
    
}