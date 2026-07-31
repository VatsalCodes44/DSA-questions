#include <bits/stdc++.h>

using namespace std;

bool isOperand(char o) {
    if (( o >= 'A' && o <= 'Z') || (o >= 'a' && o <= 'z') || (o >= '0' && o <= '9')) return true;
    return false;
}

void postfixToPrefix(string s) {
    int i = 0;
    stack<string> st;

    while ( i < s.size()) {
        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string ans = s[i] + top2 + top1;
            st.push(ans);
        }
        i++;
    }

    cout << st.top() << endl;
}

int main () {
    string s = "AB-DE+F*/";
    postfixToPrefix(s);
}