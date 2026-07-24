#include <bits/stdc++.h>

using namespace std;

class Stackk {
    queue<int> q1;
    queue<int> q2;
    bool topInQ1;
    int lastPushed;

    public: 
    Stackk () {
        q1 = queue<int>();
        q2 = queue<int>();
        topInQ1 = true;
        lastPushed = -1;
    }

    // TC = O(1)
    void push (int x) {
        lastPushed = x;
        if (q1.size() + q2.size() == 0) {
            q1.push(x);
            topInQ1 = true;
            return;
        }

        if (topInQ1) {
            q1.push(x);
            return;
        } 
        else {
            q2.push(x);
            return;
        }
    }

    // TC = O(n) worst case
    int pop () {
        if (q1.size() + q2.size() == 0) {
            cout << "stack is empty" << endl;
            return -1;
        }
        if (q1.size() + q2.size() == 1) {
            if (!q1.empty()) {
                int temp = q1.front();
                q1.pop();
                return temp;
            }
            else {
                int temp = q2.front();
                q2.pop();
                return temp;
            }
        } 
        
        
        if (topInQ1) {
            int top = 0;
            while (q1.size() != 1) {
                top = q1.front();
                q1.pop();
                q2.push(top);
            }
            lastPushed = top;
            top = q1.front();
            q1.pop();
            topInQ1 = false;
            return top;
        }
        else {
            int top = 0;
            while (q2.size() != 1) {
                top = q2.front();
                q2.pop();
                q1.push(top);
            }
            lastPushed = top;
            top = q2.front();
            q2.pop();
            topInQ1 = true;
            return top;
        }
    }

    int size() {
        return q1.size()+q2.size();
    }

    // TC = O(n) worst case
    int top () {
        if (q1.size() + q2.size() == 0) {
            cout << "stack is empty" << endl;
            return -1;
        }

        if (topInQ1) {
            int top = 0;
            while (q1.size() != 0) {
                top = q1.front();
                q1.pop();
                q2.push(top);
            }
            topInQ1 = false;
            return top;
        }
        else {
            int top = 0;
            while (q2.size() != 0) {
                top = q2.front();
                q2.pop();
                q1.push(top);
            }
            topInQ1 = true;
            return top;
        }
    }

    // TC = O(1) worst case
    int betterTop () {
        if (q1.size() + q2.size() == 0) {
            cout << "stack is empty" << endl;
            return -1;
        }
        else return lastPushed;
    }

    void print () {
        if (q1.size() + q2.size() == 0) {
            cout << "stack is empty" << endl;
            return;
        }

        if (topInQ1) {
            int size1 = q1.size();
            int size2 = q2.size();
            while (!q2.empty()) {
                cout << q2.front() << " ";
                q1.push(q2.front());
                q2.pop();
            }
            for (int i = 0; i < size1; i++) {
                cout << q1.front() << " ";
                q1.push(q1.front());
                q1.pop();
            }
            cout << endl;
        }
        else {
            int size1 = q1.size();
            int size2 = q2.size();
            while (!q1.empty()) {
                cout << q1.front() << " ";
                q2.push(q1.front());
                q1.pop();
            }
            for (int i = 0; i < size2; i++) {
                cout << q2.front() << " ";
                q2.push(q2.front());
                q2.pop();
            }
            cout << endl;
        }
    }
};

int main () {
    Stackk st = Stackk();
    st.push(1);
    st.push(2);
    st.pop();
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.print();
    cout << st.betterTop() << endl;
}