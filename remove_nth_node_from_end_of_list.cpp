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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        for(int i = 0; i < n; i++)
        {
            p1 = p1->next;
        }
        if (head == NULL)
        {
            return NULL;
        }
        if (p1 == NULL)
        {
            p2 = p2->next;
            return p2;
        }
        while(p1->next != NULL)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        if (p2->next != NULL)
        {
            p2->next = p2->next->next;
            return head;
        }
        else
        {
            return NULL;
        }
    }
};
