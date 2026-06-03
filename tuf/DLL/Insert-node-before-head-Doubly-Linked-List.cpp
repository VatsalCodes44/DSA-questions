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

ListNode* insertBeforeHead(ListNode* head, int X) {
    ListNode* temp = new ListNode(X);
    temp->next = head;
    if (head) {
        head->prev = temp;
    }
    return temp;
}

int main () {
    ListNode* head = new ListNode(1);
    insertBeforeHead(head, 0);
}