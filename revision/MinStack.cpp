#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long minn = 0;
    MinStack() {
    }
    
    void push(int value) {
        if (st.size() == 0) {
            minn = value;
            st.push(value);
        }
        else if (value <= minn) {
            st.push((2LL*value) - minn);
            minn = value;
        }
        else st.push(value);
    }
    
    void pop() {
        if (!st.empty() && st.top() <= minn) {
            minn = (2LL*minn) - st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if (st.top() <= minn) {
            return minn;
        }
        else return st.top();
    }
    
    int getMin() {
        return minn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */