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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else
        {
            ListNode * listHead = NULL;
            ListNode * l1CurrNode = l1;
            ListNode * l2CurrNode = l2;
            if (l1->val > l2->val)
            {
                listHead = l2;
                l2CurrNode = l2CurrNode -> next;
            }
            else
            {
                listHead = l1;
                l1CurrNode = l1CurrNode -> next;
            }
            ListNode * newListNode = listHead;
            while(l1CurrNode != NULL || l2CurrNode != NULL)
            {
                if (l1CurrNode == NULL)
                {
                    newListNode -> next = l2CurrNode;
                    newListNode = newListNode -> next;
                    l2CurrNode = l2CurrNode -> next;
                }
                else if (l2CurrNode == NULL)
                {
                    newListNode -> next = l1CurrNode;
                    newListNode = newListNode -> next;
                    l1CurrNode = l1CurrNode -> next;
                }
                else
                {
                    if (l1CurrNode -> val > l2CurrNode -> val)
                    {
                        newListNode -> next = l2CurrNode;
                        newListNode = newListNode -> next;
                        l2CurrNode = l2CurrNode -> next;
                    }
                    else
                    {
                        newListNode -> next = l1CurrNode;
                        newListNode = newListNode -> next;
                        l1CurrNode = l1CurrNode -> next;
                    }
                }
            }
            return listHead;
        }
        
    }
};
