#include <bits/stdc++.h>

using namespace std;

bool isOperand(char o) {
    if (( o >= 'A' && o <= 'Z') || (o >= 'a' && o <= 'z') || (o >= '0' && o <= '9')) return true;
    return false;
}

void prefixToPostfix (string s) {
    int i = s.size() - 1;
    stack<string> st;

    while (i >= 0) {
        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string ans = top1 + top2 + s[i];
            st.push(ans);
        }
        i--;
    }
    cout << st.top() << endl;
}

int main () {
    string s = "/-AB*+DEF";
    prefixToPostfix(s);
}