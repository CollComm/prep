/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode cur = head;
        ListNode next = head.next;
        cur.next = null;
        while (next != null)
        {
            ListNode tmp = next.next;
            next.next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }
    public ListNode mergeList(ListNode head1, ListNode head2) {
        if (head1 == null) {
            return head2;
        }
        if (head2 == null) {
            return head1;
        }
        ListNode dummyNode = new ListNode(0);
        ListNode cur = dummyNode;
        ListNode cur1 = head1;
        ListNode cur2 = head2;
        while (cur1 != null && cur2 != null) {
            cur.next = cur1;
            cur1 = cur1.next;
            cur = cur.next;
            cur.next = null;
            cur.next = cur2;
            cur2 = cur2.next;
            cur = cur.next;
            cur.next = null;
        }
        while (cur1 != null) {
            cur.next = cur1;
            cur1 = cur1.next;
            cur = cur.next;
            cur.next = null;
        }
        while (cur2 != null) {
            cur.next = cur2;
            cur2 = cur2.next;
            cur = cur.next;
            cur.next = null;
        }
        return dummyNode.next;
    }
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode cur = head;
        int totalNodes = 0;
        while (cur != null) {
            totalNodes++;
            cur = cur.next;
        }
        if (totalNodes <= 2) return;
        int nodeCounter = totalNodes / 2 - 1;
        ListNode midNode = head;
        while (midNode != null) {
            if (nodeCounter == 0) {
                ListNode next = midNode.next;
                midNode.next = null;
                head = mergeList(head, reverseList(next));
                break;
            }
            midNode = midNode.next;
            nodeCounter--;
        }
        return;
    }
}
