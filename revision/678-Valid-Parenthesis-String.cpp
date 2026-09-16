#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> open;

        int i = 0; 
        while (i < s.size()) {
            if (s[i] == '(') {
                open.push(i);
            }
            else if (s[i] == '*') {
                st.push(i);
            }
            else {
                if (!open.empty()) {
                    open.pop();
                }
                else if (!st.empty()) st.pop();
                else return false;
            }
            i++;
        }
        while (!open.empty() && !st.empty()) {
            if (st.top() > open.top()) {
                st.pop();
                open.pop();
            }
            else return false;
        }
        if (!open.empty()) return false;
        
        return true;
    }
};