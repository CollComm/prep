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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL)
        {
            return false;
        }
        else
        {
            ListNode * step1 = head;
            if (step1->next==NULL)
            {
                return false;
            }
            else
            {
                ListNode * step2 = step1 -> next -> next;
                while(step1 != step2)
                {
                    step1 = step1->next;
                    if (step1 == NULL || step2 == NULL)
                    {
                        return false;
                    }
                    else
                    {
                        if (step2->next == NULL)
                        {
                            return false;
                        }
                        else if (step2->next ->next == NULL)
                        {
                            return false;
                        }
                        else
                        {
                            step2 = step2->next->next;
                        }
                    }
                }
                if (step1 == step2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            
        }
    }
};
