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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        if (head == NULL) return NULL;
        ListNode * dummyNode = new ListNode(-1);
        dummyNode -> next = head;
        ListNode * prevNode = dummyNode;
        ListNode * currNode = head;
        ListNode * tailNode = head -> next;
        int cnt = 2;
        while (tailNode != NULL)
        {
            if (cnt < k)
            {
                cnt++;
                tailNode = tailNode -> next;
            }
            else
            {
                ListNode * nextNode = tailNode -> next;
                prevNode -> next = tailNode;
                prevNode = currNode;
                ListNode * tmpNextNode = currNode -> next;
                currNode -> next = nextNode;
                for(int i = 1; i < k; i++)
                {
                    ListNode * tNode = tmpNextNode -> next;
                    tmpNextNode -> next = currNode;
                    currNode = tmpNextNode;
                    tmpNextNode = tNode;
                }
                currNode = nextNode;
                if (nextNode != NULL)
                {
                    tailNode = nextNode -> next;
                }
                else
                {
                    tailNode = NULL;
                }
                cnt = 2;
            }
        }
        return dummyNode -> next;
    }
};
