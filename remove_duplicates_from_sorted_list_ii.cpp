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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * dummyNode = new ListNode(1<<30);
        dummyNode -> next = head;
        ListNode * currNode = head;
        ListNode * prevNode = dummyNode;
        while(currNode != NULL)
        {
            ListNode * nextNode = NULL;
            if (currNode -> next == NULL)
            {
                break;
            }
            else
            {
                nextNode = currNode -> next;
                if (currNode -> val == nextNode -> val)
                {
                    while (nextNode -> next != NULL && nextNode -> next -> val == nextNode -> val)
                    {
                        nextNode = nextNode -> next;
                    }
                    prevNode -> next = nextNode -> next;
                    currNode = prevNode -> next;
                }
                else
                {
                    prevNode = currNode;
                    currNode = nextNode;
                }
            }
        }
        return dummyNode->next;
    }
};
