#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            if (curr > 0) st.push(curr);
            else 
            {
                if (st.empty()) 
                {
                    st.push(curr);
                }
                else 
                {   
                    bool isDestroyed = false;
                    while (!st.empty() && st.top() > 0) 
                    {
                        if (abs(st.top()) == abs(curr)) 
                        {   
                            isDestroyed = true;
                            st.pop();
                            break;
                        }
                        else if (abs(st.top()) > abs(curr)) {
                            isDestroyed = true;
                            break;
                        }
                        else 
                        {
                            st.pop();
                        }
                    }

                    if (!isDestroyed) st.push(curr);
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

int main () {
    Solution s;
    vector <int> arr = {5,10,-5};
    s.asteroidCollision(arr);
};