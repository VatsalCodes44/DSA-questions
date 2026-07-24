#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode (int x) {
        this->next = nullptr;
        this->val = x;
    }
};

class Q {
    ListNode* front;
    int currSize;
    ListNode* rear;

    public:
    Q (): front(nullptr), currSize(0), rear(nullptr) {};

    void push(int x) {
        if (currSize == 0) {
            front = new ListNode(x);
            rear = front;
            currSize = 1;
            return;
        }

        rear -> next = new ListNode(x);
        rear = rear->next;
        currSize++;
    }

    int pop () {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (currSize == 1) {
            int temp = front -> val;
            delete front;
            front = nullptr;
            rear = nullptr;
            currSize = 0;
            return temp;
        }

        ListNode* temp = front;
        front = front->next;
        currSize--;
        int popedVal = temp->val;
        delete temp;
        return popedVal;
    }

    int size () {
        return currSize;
    }

    int top () {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }
};