#include <bits/stdc++.h>

using namespace std;

void insertInOrder(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    if (st.top() > x) {
        int top = st.top();
        st.pop();
        insertInOrder(st, x);
        st.push(top);
    }
    else {
        st.push(x);
    }
}

void sortStack(stack<int>& st) {
    if (st.size() == 0 ) return;
    int x = st.top();
    st.pop();
    sortStack(st);

    insertInOrder(st, x);
}

void printStack(stack<int> st) {
     while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main () {
    stack<int> st;
    st.push(9);
    st.push(7);
    st.push(3);
    st.push(1);
    st.push(8);
    st.push(2);

    sortStack(st);
    printStack(st);

}