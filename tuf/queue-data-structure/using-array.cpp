#include <bits/stdc++.h>

using namespace std;

class Q { 
    int *arr;
    int mover;
    int maxSize;
    int topIdx;
    int currSize;

    public:
    Q(int size) {
        arr = new int[size];
        topIdx = -1;
        mover = -1;
        maxSize = size;
        currSize = 0;
    }

    int top () {
        if (topIdx == -1) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return arr[topIdx];
    }

    void push (int x) {
        if (currSize == maxSize) {
            cout << "Queue is full" << endl;
            return;
        }
        if (currSize == 0) {
            topIdx = 0;
            mover = 0;
            currSize = 1;
            arr[0] = x;
            return;
        }

        mover = (currSize + topIdx) % maxSize;
        arr[mover] = x;
        currSize++;
    }

    int pop () {
        if (currSize == 1) {
            int temp = arr[topIdx];
            topIdx = -1;
            mover = -1;
            currSize = 0;
            return temp;
        }
        
        int temp = arr[topIdx];
        if (topIdx == maxSize-1) {
            topIdx = 0;
            currSize--;
        } else {
            topIdx++;
            currSize--;
        }
        return temp;

    }

    int size() {
        return currSize;
    }

    void print() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (mover >= topIdx) {
            for (int i = topIdx; i <= mover; i++) {
                cout << arr[i] << " ";
            }
        }
        else  {
            for (int i = topIdx; i < maxSize; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= mover; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main () {
    Q q = Q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.push(4);
    q.push(5);
    q.print();
    
}