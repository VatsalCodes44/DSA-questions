#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        stack<char> st;
        for(int i = 0; i < num.size(); i++) {
            while(k && !st.empty() && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size()) {
            if (ans[i] == '0') i++;
            else break;
        }
        ans = ans.substr(i);

        if (ans.size() == 0) return "0";


        return ans;                
    }
};