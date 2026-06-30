#include <bits/stdc++.h>

using namespace std;



bool good(long long n) {
    long long x =10;
    long long y = 10;

    while (n) {
        long long a = n%10;
        n/=10;
        if (x == 10 || x == a) {
            x=a;
        }
        else if (y ==10 || y == a) {
            y = a;
        }
        else {
            return false;
        }
    }
    return true;
}

void generate(vector<int>& goods, int d1, int d2, long long curr) {
    if (curr > 1000000000) return;
    if (curr >=2) goods.push_back((int)curr);


    generate(goods,d1, d2, curr*10+d1);

    if (d1 != d2) {
        generate(goods, d1, d2, curr*10+d2);
    }
}
void generateGoods(vector<int>& goods, int d1, int d2) {
    if (d1 > 9) {
        return;
    }
    if (d2 > 9) {
        generateGoods(goods, d1+1, 0);
        return;
    }
    generate(goods, d1, d2, d1);
    generateGoods(goods, d1, d2+1);

}

void f(vector<int>& goods) {
    int x;
    cin >> x;
    for (auto i: goods) {
        if (good(x*i)) {
            cout << i << '\n';
            return;
        }
    }
}

int main () {
    int n;
    cin >> n; 
    vector<int> goods;
    generateGoods(goods, 1, 0);
    sort(goods.begin(), goods.end());
    for (int i = 0; i < n; i++) {
        f(goods);
    }
    return 0;
}