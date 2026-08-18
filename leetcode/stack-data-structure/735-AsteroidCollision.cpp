#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto i: asteroids) {
            if (i > 0) st.push(i);
            else {
                if (st.empty()) st.push(i);
                else {
                    bool destroyed = false;
                    while (!st.empty() && st.top() > 0) {
                        if (abs(st.top()) == abs(i)) {
                            st.pop();
                            destroyed = true;
                            break;
                        }
                        else if (abs(st.top()) > abs(i)) {
                            destroyed = true;
                            break;
                        }
                        else {
                            st.pop();
                        } 
                    }
                    if (!destroyed) st.push(i);
                }
            } 
        }

        vector<int> ans(st.size(), 0);
        for (int i = ans.size() -1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
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