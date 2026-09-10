#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> st;

        vector<int> stars;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                stars.push_back(i);
            }
            else if (s[i] == '(') {
                st.push_back(i);
            }
            else {
                if (st.empty()) {
                    if (stars.size() > 0) stars.pop_back(); 
                    else return false;
                }
                else {
                    st.pop_back();
                }
            }
        }
        
        if (st.size() == 0) return true;
        if (st.size() > stars.size()) return false;
        int i = 0; int j = 0;
        while ( j < stars.size()) {
            if (i == st.size()) break;
            if (st[i] < stars[j]) {
                i++;
            }
            j++;
        }
        if (i == st.size()) return true;

        return false;
    }
};

int main () {
    Solution s;//                                                           '                                             '
    cout << boolalpha << s.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
}