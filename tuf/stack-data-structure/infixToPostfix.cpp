#include <bits/stdc++.h>

using namespace std;

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    else return 0;
}

void infixToPostfix (string s) {
    stack<char> st;
    int i = 0;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >=0 && s[i] <= 9)) {
            ans.push_back(s[i]);
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                char op = st.top();
                st.pop();
                ans.push_back(op);
            }
            st.pop();
        } 
        else {
            if (st.empty()) {
                st.push(s[i]);
            }
            else {
                while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans;
}

int main() {
    infixToPostfix("a+b*(c^d-e)^(d*e-f+g)");
}