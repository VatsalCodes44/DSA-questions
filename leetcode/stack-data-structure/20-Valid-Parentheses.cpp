#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    if (s.size() % 2 != 0) return false;

    for (auto i: s) {
        if (i == '(' || i == '[' || i == '{') {
            st.push(i);
        }
        else if (st.empty()) return false;
        else if (i == ')') {
            if (st.top() == '(') {
                st.pop();
            }
            else return false;
        }
        else if (i == ']') {
            if (st.top() == '[') {
                st.pop();
            }
            else return false;
        }
        else if (i == '}') {
            if (st.top() == '{') {
                st.pop();
            }
            else return false;
        }
        else return false;
    }
    if (st.size() > 0) return false;
    return true;
}

// this approach can't be solved by recursive method because here we have multiple 
// braces type if we only have a string with one typ of braces like () or [] or {} 
// then we could have solved it by recursion.
int main () {
    cout << boolalpha << isValid("([])") << endl;
}