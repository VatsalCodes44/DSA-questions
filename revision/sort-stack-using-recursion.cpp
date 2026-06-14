#include <bits/stdc++.h>

using namespace std;

void putInCorrectOrder(stack<int>& st, int n) {
    if (st.empty()) {
        st.push(n);
        return;
    }
    if (st.top() < n) {
        st.push(n);
        return;
    }
    else {
        int top = st.top();
        st.pop();
        putInCorrectOrder(st, n);
        st.push(top);
    }
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    sortStack(st);

    putInCorrectOrder(st, top);
}

int main () {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(1);
    st.push(2);
    st.push(3);

    sortStack(st);

    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}