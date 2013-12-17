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
    ListNode *swapPairs(ListNode *head) {
        ListNode * newHead = NULL;
        ListNode * currNode = NULL;
        ListNode * nextNode = NULL;
        ListNode * tmpNode = NULL;
        ListNode * prevNode = NULL;
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            currNode = head;
            nextNode = head -> next;
            if (nextNode == NULL)
            {
                return currNode;
            }
            else
            {
            tmpNode = nextNode -> next;
            newHead = nextNode;
            nextNode -> next = currNode;
            currNode -> next = tmpNode;
            prevNode = currNode;
            while(tmpNode != NULL)
            {
                currNode = tmpNode;
                nextNode = currNode -> next;
                if (nextNode == NULL)
                {
                    break;
                }
                tmpNode = nextNode -> next;
                nextNode -> next = currNode;
                currNode -> next = tmpNode;
                prevNode -> next = nextNode;
                prevNode = currNode;
            }
            return newHead;
            }
        }
    }
};
