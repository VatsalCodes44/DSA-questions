#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *deleteHead(ListNode *&head) {
    if (!head->next) {
        delete head;
        return nullptr;
    }
    ListNode* temp = head->next;
    delete head;
    temp->prev = nullptr;
    head = temp;
    return head;
}