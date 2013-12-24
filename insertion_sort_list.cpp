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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode * currNode = head -> next;
        ListNode * newHead = head;
        head -> next = NULL;
        while(currNode != NULL)
        {
            ListNode * nextNode = currNode -> next;
            ListNode * iterNode = newHead;
            ListNode * prevNode = NULL;
            while(currNode->val > iterNode->val)
            {
                prevNode = iterNode;
                iterNode = iterNode -> next;
                if (iterNode == NULL)
                {
                    break;
                }
            }
            if (iterNode != NULL)
            {
                if (prevNode != NULL)
                {
                    prevNode -> next = currNode;
                }
                else
                {
                    newHead = currNode;
                }
                currNode -> next = iterNode;
            }
            else
            {
                prevNode -> next = currNode;
                currNode -> next = NULL;
            }
            currNode = nextNode;
        }
        return newHead;
    }
};
