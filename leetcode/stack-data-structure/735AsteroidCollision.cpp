#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> arr = asteroids;
        stack<int> st;

        for (int i = arr.size()-1; i >= 0; i--) {
            if (arr[i] == 0) continue;
            if (arr[i] < 0) {
                st.push(i);
            }
            else {
                while (!st.empty()) {
                    int top = arr[st.top()];
                    if (arr[i] != 0 && abs(arr[i]) == abs(arr[st.top()])) {
                        arr[i] = 0;
                        arr[st.top()] = 0;
                    }
                    else if (arr[i] != 0 && abs(arr[i]) > abs(arr[st.top()])){
                        arr[st.top()] = 0;
                    }
                    else if (arr[i] != 0 && abs(arr[i]) < abs(arr[st.top()])) {
                        arr[i] = 0;
                        break;
                    }
                    st.pop();
                }
            }
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) continue;
            if (arr[i] > 0) {
                st.push(i);
            }
            else {
                while (!st.empty()) {
                    int top = arr[st.top()];
                    if (arr[i] != 0 && abs(arr[i]) == abs(arr[st.top()])) {
                        arr[i] = 0;
                        arr[st.top()] = 0;
                    }
                    else if (arr[i] != 0 && abs(arr[i]) > abs(arr[st.top()])){
                        arr[st.top()] = 0;
                    }
                    else if (arr[i] != 0 && abs(arr[i]) < abs(arr[st.top()])) {
                        arr[i] = 0;
                        break;
                    }
                    st.pop();
                }
            }
        }

        vector<int> ans;
        for (auto i: arr) {
            if (i!=0) ans.push_back(i);
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<int> arr = {7,-1,2,-3,-6,-6,-6,4,10,2};
    for (auto i: s.asteroidCollision(arr)) {
        cout << i << " ";
    }
}