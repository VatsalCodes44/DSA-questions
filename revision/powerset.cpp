#include <bits/stdc++.h>

using namespace std;

int main () {
    vector <int> arr = {1,2,3};
    for (int i = 0; i < (1 << arr.size()); i++){
        string ans = "";
        for (int j = 0; j < arr.size(); j++){
            if (i & (1<<j)) {
                ans.push_back('0'+arr[j]);
            }
        }
        cout << ans << endl;
    }
}