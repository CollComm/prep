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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
        {
            return head;
        }
        ListNode * currNode = head;
        ListNode * lessNode = NULL;
        ListNode * lessNodeHead = NULL;
        ListNode * greaterNode = NULL;
        ListNode * greaterNodeHead = NULL;
        //Process the head
        if (head->val < x)
        {
            lessNode = head;
            lessNodeHead = head;
        }
        else
        {
            greaterNode = head;
            greaterNodeHead = head;
        }
        //Process other nodes
        while(currNode->next != NULL)
        {
            ListNode * nextNode = currNode -> next;
            if (nextNode -> val < x)
            {
                // make sure the node is still there
                if (lessNode != NULL)
                {
                    lessNode -> next = nextNode;
                    lessNode = lessNode -> next;
                }
                else
                {
                    lessNode = nextNode;
                    lessNodeHead = nextNode;
                }
            }
            else
            {
                if (greaterNode != NULL)
                {
                    greaterNode -> next = nextNode;
                    greaterNode = greaterNode -> next;
                }
                else
                {
                    greaterNode = nextNode;
                    greaterNodeHead = nextNode;
                }
            }
            currNode = nextNode;
        }
        if (greaterNodeHead != NULL)
        {
            greaterNode -> next = NULL;
        }
        if (lessNodeHead != NULL)
        {
            lessNode -> next = greaterNodeHead;
            return lessNodeHead;
        }
        else
        {
            return greaterNodeHead;
        }
    }
};
