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
    ListNode *detectCycle(ListNode *head) {
        bool existCycle = false;
        ListNode * meetPoint = NULL;
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *node1 = NULL;
        ListNode *node2 = NULL;
        node1 = head;
        node2 = head;
        while(node1 -> next != NULL)
        {
            node1 = node1 -> next;
            if (node2 -> next == NULL || node2 -> next -> next == NULL)
            {
                break;
            }
            node2 = node2 -> next -> next;
            if (node2 == node1)
            {
                existCycle = true;
                meetPoint = node2;
                break;
            }
        }
        if (existCycle)
        {
            node1 = head;
            while(node1 != meetPoint)
            {
                node1 = node1 -> next;
                meetPoint = meetPoint ->next;
            }
            return meetPoint;
        }
        else
        {
            return NULL;
        }
    }
};
