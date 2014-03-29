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
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode cur = head;
        while(cur != null) {
            ListNode next = cur.next;
            cur.next = reverseList(next);
            cur = cur.next;
        }
    }
}
