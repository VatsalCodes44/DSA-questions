#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* evenHead = nullptr;
    ListNode* even = nullptr;
    ListNode* odd = nullptr;
    ListNode* mover = head;
    int count = 1;
    while (mover) {
        if (count % 2 == 0) {
            if (!evenHead)  {
                evenHead = mover;
                even = mover;
            } else {
                even->next = mover;
                even = even->next;
            }
        } 
        else {
            if (!odd)  {
                odd = mover;
            } else {
                odd->next = mover;
                odd = odd->next;
            }
        }

        mover = mover->next;
        count++;
    }

    odd->next = evenHead;
    even->next = nullptr;
    return head;
}