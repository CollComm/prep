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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode * currHead = head;
        ListNode * newHead = head;
        int listLength = 1;
        while(currHead -> next != NULL)
        {
            currHead = currHead -> next;
            listLength++;
        }
        k = k % listLength;
        currHead = head;
        for (int i = 0; i < k; i++)
        {
            currHead = currHead -> next;
        }
        while(currHead -> next != NULL)
        {
            currHead = currHead -> next;
            newHead = newHead -> next;
        }
        ListNode * nextNode = newHead -> next;
        if (nextNode != NULL)
        {
            newHead -> next = NULL;
            currHead -> next = head;
            return nextNode;
        }
        else
        {
            return head;
        }
    }
};
