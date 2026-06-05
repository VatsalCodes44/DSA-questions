#include <bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

ListNode* reverseDll(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* temp = curr->next;
        if (prev) {
            prev->prev = curr;
        }
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}