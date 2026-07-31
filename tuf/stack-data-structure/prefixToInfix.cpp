#include <bits/stdc++.h>

using namespace std;

bool isOperand(char o) {
    if (( o >= 'A' && o <= 'Z') || (o >= 'a' && o <= 'z') || (o >= '0' && o <= '9')) return true;
    return false;
}

void prefixToInfix (string s) {
    int i = s.size() - 1;
    stack<string> st;

    while (i >= 0) {
        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();

            string ans = "(" + second + s[i] + first + ")";
            st.push(ans);
        }
        i--;
    }

    cout << st.top() << endl;
}

int main () {
    string s = "*+PQ-MN";
    prefixToInfix(s);
}