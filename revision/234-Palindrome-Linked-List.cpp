#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    if (!head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mover = slow->next;
    ListNode* prev = slow;

    while (mover) {
        ListNode* temp = mover->next;
        mover->next = prev;
        prev = mover;
        mover = temp;
    }

    ListNode* frwd = head;
    ListNode* bkwd = prev;
    bool ans = true;
    while (bkwd != slow) {
        if (frwd->val != bkwd->val) {
            ans = false;
        }
        frwd = frwd->next;
        bkwd = bkwd->next;
    }

    mover = prev;
    prev = nullptr;
    while (mover!= slow) {
        ListNode* temp = mover->next;
        mover->next = prev;
        prev = mover;
        mover = temp;
    } 
    return ans;
}