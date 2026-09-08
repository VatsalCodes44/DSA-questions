#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        st.reserve(num.size());

        for (int i = 0; i < num.size(); i++) {
            while (st.size() > 0 && k && st[st.size()-1] > num[i]) {
                st.pop_back();
                k--;
            }
            if (st.size() == 0 && num[i] == '0') continue;
            st.push_back(num[i]);
        }

        if (k) {
            if (st.size() <= k) return "0";
            else st = st.substr(0, st.size()-k);
        }

        if (st == "") return "0";

        return st;

    }
};