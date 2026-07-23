#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode (int val) {
        this->val = val;
        this->next = nullptr;
    }
    ListNode (int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }
};

class Stackk {
    ListNode* head;
    int currSize;

    public: 
    Stackk () {
        head = nullptr;
        currSize = 0;
    }
    ~Stackk () {
        if (!head) return;
        while (head) {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
    }

    int pop () {
        if (!head || currSize == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        if (!head->next) {
            int popedValue = head->val;
            delete head;
            head = nullptr;
            currSize = 0;
            return popedValue;
        }

        ListNode* temp = head->next;
        int popedValue = head->val;
        delete head;
        currSize--;
        head = temp;
        return popedValue;
    }

    void push(int x) {
        if (!head || currSize == 0) {
            head = new ListNode(x);
            currSize++;
            return;
        }

        head = new ListNode(x, head);
        currSize++;
    }

    int top () {
        if (!head || currSize == 0) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return head->val;
    }

    int size() {
        return currSize;
    }
};