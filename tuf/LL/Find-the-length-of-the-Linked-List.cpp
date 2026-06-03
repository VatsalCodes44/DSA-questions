#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getLength(ListNode* head) {
    if (!head) return 0;

    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main () {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    cout << getLength(head) << endl;
}