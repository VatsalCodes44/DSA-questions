#include <bits/stdc++.h>

using namespace std;

void putInLast(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    putInLast(st, x);
    st.push(top);
}

void sortt(stack<int>& st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    sortt(st);
    putInLast(st, x);
}

int main () {
    stack<int> st;
    st.push(5);
    st.push(11);
    st.push(6);
    st.push(8);
    st.push(9);
    sortt(st);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}