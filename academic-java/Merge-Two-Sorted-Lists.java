class ListNode {
    int val;
    ListNode next;
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode(1, null);
        ListNode mover = head;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                mover.next = list1;
                mover = mover.next;
                list1 = list1.next;
            }
            else {
                mover.next = list2;
                mover = mover.next;
                list2 = list2.next;
            }
        }

        while (list1 != null) {
            mover.next = list1;
            mover = mover.next;
            list1 = list1.next;
        }

        while (list2 != null) {
            mover.next = list2;
            mover = mover.next;
            list2 = list2.next;
        }
        return head.next;
    }
}