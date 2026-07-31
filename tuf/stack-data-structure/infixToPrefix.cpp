#include <bits/stdc++.h>

using namespace std;

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    else return 0;
}

void initialReverse(string& s) {
    int i = 0;
    while (i < s.size()/2) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';

        if (s[s.size()-i-1] == '(') s[s.size()-i-1] = ')';
        else if (s[s.size()-i-1] == ')') s[s.size()-i-1] = '(';


        char temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
        i++;

    }
}

void infixToPrefix(string s) {
    initialReverse(s);

    stack<char> st;
    int i = 0;
    string ans = "";
    
    while (i < s.size()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += (s[i]);
            i++;
            continue;
        }
        else if (s[i] == '(') {
            st.push(s[i]);
            i++;
            continue;
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                ans+=st.top();
                st.pop();
            }
            st.pop();
            i++;
        }
        else if (s[i] == '^') {
            while (!st.empty() && st.top() == '^') {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
        else {
            while (!st.empty() && priority(s[i]) < priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }

    while (!st.empty()) {
        ans+= st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    
}

int main () {
    string s = "(A+B)*C-D+F^G^H";
    infixToPrefix(s);
}