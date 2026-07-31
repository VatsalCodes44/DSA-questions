#include <bits/stdc++.h>
#include <format>

using namespace std;

void postfixToInfix (string s) {
    stack<string> st;
    int i = 0;

    while (i < s.size()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1,s[i]));
        }
        else {
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();

            string ans = std::format("({}{}{})", first, s[i], second);
            st.push(ans);
        }
        i++;
    }

    cout << st.top() << endl;
}

int main () {
    string s = "AB-DE+F*/";
    postfixToInfix(s);
}