#include <bits/stdc++.h>

using namespace std;

class Stackk {
    private:
    int *arr;
    int topIdx;
    int currSize;
    int maxSize;

    public: 
    Stackk (int size) {
        this->arr = new int[size];
        this->topIdx = -1;
        this->maxSize = size;
        this->currSize = 0;
    }
    ~Stackk() {
        delete[] arr;
    }

    int top () {
        if (topIdx == -1 ||currSize == 0) {
            cout << "stack is empty" << endl;
            return 0;
        }
        return arr[topIdx];
    }

    int pop () {
        if (topIdx == -1) {
            cout << "stack is empty" << endl;
            return 0;
        }
        int currTop = arr[topIdx];
        currSize--;
        topIdx--;

        return currTop;
    }

    void push (int x) {
        if (topIdx == maxSize-1) {
            cout << "stack is full" << endl;
            return;
        }

        topIdx++;
        currSize++;
        arr[topIdx] = x;
    }

    int size () {
        return currSize;
    }
};

int main () {
    Stackk st = Stackk(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(4);
    st.push(4);
    st.push(4);
    st.push(4);
    st.push(4);
    st.push(4);
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;

}