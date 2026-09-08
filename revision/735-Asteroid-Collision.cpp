#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        v.reserve(asteroids.size());
        stack <int, vector<int>> st(move(v));

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {
                if (st.empty()) {
                    st.push(asteroids[i]);
                }
                else {
                    while (!st.empty()) {
                        if (st.top() == -1*asteroids[i]) {
                            st.pop();
                            break;
                        }
                        else if (st.top() < 0) {
                            st.push(asteroids[i]);
                            break;
                        }
                        else {
                            // st.top() it is positive
                            if (abs(st.top()) > abs(asteroids[i])) break;
                            else {
                                st.pop();
                                if (st.empty()) {
                                    st.push(asteroids[i]);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};