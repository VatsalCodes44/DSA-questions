#include <bits/stdc++.h>

using namespace std;

void putInOrder(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    if (st.top() > x) {
        int top = st.top();
        st.pop();
        putInOrder(st, x);
        st.push(top);
    }
    else {
        st.push(x);
    }
}

void sortt(stack<int>& st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    sortt(st);
    putInOrder(st, x);
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