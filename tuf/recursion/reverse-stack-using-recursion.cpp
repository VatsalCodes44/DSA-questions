#include <bits/stdc++.h>

using namespace std;

void insertInBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertInBottom(st,x);

    st.push(top);

}


void reverseStack (stack <int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    reverseStack(st);

    insertInBottom(st, top);
}


void printStack(stack<int> st) {
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}


int main () {
    stack<int> st;
    st.push(9);
    st.push(7);
    st.push(3);
    st.push(1);
    st.push(8);
    st.push(2);

    printStack(st);
    reverseStack(st);
    printStack(st);

}