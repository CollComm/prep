/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int length = 0;
        ListNode * dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode * tailNode = head;
        ListNode * prevNode = dummyNode;
        ListNode * nextNode = head -> next;
        for (int i = 1; i < m; i++)
        {
            prevNode = prevNode -> next;
            tailNode = tailNode -> next;
            nextNode = nextNode -> next;
        }
        ListNode * currNode = tailNode;
        for (int i = 0; i < n - m; i++)
        {
            ListNode * tmp = nextNode -> next;
            nextNode -> next = currNode;
            tailNode -> next = tmp;
            currNode = nextNode;
            nextNode = tmp;
        }
        prevNode -> next = currNode;
        return dummyNode -> next;
    }
};
