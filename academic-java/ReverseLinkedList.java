class ListNode {
    int val;
    ListNode next;
    ListNode (int v, ListNode nxt) {
        this.val = v;
        this.next = nxt;
    }
}

class Recursive {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode next = head.next;
        ListNode newHead = reverseList(head.next);
        next.next = head;
        head.next = null;
        return newHead;
    }
}

class Iterative {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode prev = null;
        ListNode mover = head;
        while (mover != null) {
            ListNode temp = mover.next;
            mover.next = prev;
            prev = mover;
            mover = temp;
        }
        return prev;
    }
}