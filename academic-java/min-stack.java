import java.util.*;
class MinStack {
    Deque<Integer> st;
    int min = 0;
    public MinStack() {
        st = new ArrayDeque<>();
    }
    
    public void push(int value) {
        if (st.size() == 0) {
            st.addLast(value);
            this.min = value;
        }
        else if (value < min) {
            st.addLast(2*value-min);
            min = value;
        }
        else st.addLast(value);
    }
    
    public void pop() {
        if (st.getLast() < min) {
            min = 2*min-st.getLast();
            st.removeLast();
        }
        else st.removeLast();
    }
    
    public int top() {
        if (st.getLast() < min) return min;
        return st.getLast();
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */