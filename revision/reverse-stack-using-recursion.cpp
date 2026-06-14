#include <bits/stdc++.h>

using namespace std;

void putInCorrectOrder(stack<int>&st, int n) {
    if (st.empty()) {
        st.push(n);
        return;
    }
    int top = st.top();
    st.pop();
    putInCorrectOrder(st, n);
    st.push(top);
}

void reverseSt(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseSt(st);
    putInCorrectOrder(st, top);
}

int main () {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseSt(st);

    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}