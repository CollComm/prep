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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * currL1 = l1;
        ListNode * currL2 = l2;
        ListNode * dummyNode = new ListNode(0);
        ListNode * currNode = dummyNode;
        int carrier = 0;
        while((currL1 != NULL) || (currL2 != NULL))
        {
            if ((currL1 != NULL) && (currL2 != NULL))
            {
                currNode -> next = new ListNode((currL1 -> val + currL2 -> val + carrier)%10);
                carrier = (currL1 -> val + currL2 -> val + carrier) / 10;
                currL1 = currL1 -> next;
                currL2 = currL2 -> next;
            }
            else if (currL1 != NULL && currL2 == NULL)
            {
                currNode -> next = new ListNode((currL1 -> val + carrier)%10);
                carrier = (currL1 -> val + carrier) / 10;
                currL1 = currL1 -> next;
            }
            else if (currL1 == NULL && currL2 != NULL)
            {
                currNode -> next = new ListNode((currL2 -> val + carrier)%10);
                carrier = (currL2 -> val + carrier) / 10;
                currL2 = currL2 -> next;
            }
            currNode = currNode -> next;
        }
        if (carrier != 0)
        {
            currNode -> next = new ListNode(1);
        }
        return dummyNode->next;
    }
};
