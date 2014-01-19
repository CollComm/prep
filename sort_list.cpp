/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *mergeList(ListNode *head1, int n1, ListNode *head2, int n2)
    {
        ListNode dummyNode(0);
        ListNode * currNode = &dummyNode;
        ListNode * nextNode = NULL;
        while(n1 > 0 && n2 > 0)
        {
            if (head1 -> val > head2 -> val)
            {
                nextNode = head2 -> next;
                currNode -> next = head2;
                head2 = nextNode;
                n2 --;
            }
            else
            {
                nextNode = head1 -> next;
                currNode -> next = head1;
                head1 = nextNode;
                n1 --;
            }
            currNode = currNode -> next;
        }
        while(n1 > 0)
        {
            nextNode = head1 -> next;
            currNode -> next = head1;
            head1 = nextNode;
            currNode = currNode -> next;
            n1--;
        }
        while(n2 > 0)
        {
            nextNode = head2 -> next;
            currNode -> next = head2;
            head2 = nextNode;
            currNode = currNode -> next;
            n2--;
        }
        return dummyNode.next;
    }
    ListNode *sortList(ListNode *head, int l, int r)
    {
        if (r - l <= 1) return head;
        int mid = (l + r) / 2;
        ListNode * currNode = head;
        for (int i = l; i < mid; i++)
        {
            currNode = currNode -> next;
        }
        ListNode * node1 = sortList(head, l, mid);
        ListNode * node2 = sortList(currNode, mid, r);
        return mergeList(node1, mid - l, node2, r - mid);
    }
public:
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int totalNodes = 0;
        ListNode * currNode = head;
        while(currNode != NULL)
        {
            totalNodes++;
            currNode = currNode -> next;
        }
        ListNode * newHead = sortList(head, 0, totalNodes);
        currNode = newHead;
        for (int i = 0; i < totalNodes - 1; i++)
        {
            currNode = currNode -> next;
        }
        if (currNode != NULL) currNode -> next = NULL;
        return newHead;
    }
};
