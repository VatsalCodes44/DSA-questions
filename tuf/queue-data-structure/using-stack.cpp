#include <bits/stdc++.h>

using namespace std;

class Q {
    stack<int> s1;
    stack<int> s2;

    public:
    Q() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    // TC = O(1);
    void push(int x) {
        s1.push(x);
    }

    // TC = O(N)
    int pop () {
        if (!s2.empty()) {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else if (!s1.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            return pop();
        }
        cout << "Queue is empty" << endl;
        return -1;
    }

    // TC = O(N)
    int top () {
        if (!s2.empty()) {
            return s2.top();
        }
        else if (!s1.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            return pop();
        }
        cout << "Queue is empty" << endl;
        return -1;
    }

    int size () {
        return s1.size() + s2.size();
    }

    void print () {
        vector<int> arr;
        int size1 = s1.size();
        int size2 = s2.size();
        if (size1 + size2 == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        while (!s2.empty()) {
            cout << s2.top() << " ";
            arr.push_back(s2.top());
            s2.pop();
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        while (!s2.empty()) {
            cout << s2.top() << " ";
            arr.push_back(s2.top());
            s2.pop();
        }

        for (auto i : arr) {
            s1.push(i);
        }
        cout << endl;
    }

};

int main () {
    Q q = Q();
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
}