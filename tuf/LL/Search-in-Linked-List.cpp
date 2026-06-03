#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool searchKey(ListNode* head, int key) {
        
    while (head) {
        if (head->val == key) return true;
        head = head->next;
    }

    return false;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << searchKey(head, 3) << endl;
}