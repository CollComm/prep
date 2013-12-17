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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL)
        {
            return NULL;
        }
        ListNode * currNode = head;
        while(currNode->next != NULL)
        {
            while (currNode->val == currNode->next->val)
            {
                currNode->next = currNode->next->next;
                if (currNode->next == NULL)
                {
                    break;
                }
            }
            if (currNode->next != NULL)
            {
                currNode = currNode->next;
            }
        }
        return head;
    }
};
