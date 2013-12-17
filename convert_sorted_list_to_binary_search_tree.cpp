/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode * insertIntoBST(ListNode ** head, int l, int r)
    {
        if (r - l == 1)
        {
            TreeNode * leaf = new TreeNode((*head) -> val);
            *head = (*head) -> next;
            return leaf;
        }
        else if (r - l == 0)
        {
            return NULL;
        }
        else
        {
            int mid = (l + r) / 2;
            TreeNode* leftSubTree = insertIntoBST(head, l, mid);
            TreeNode* root = new TreeNode((*head) -> val);
            *head = (*head) -> next;
            root -> left = leftSubTree;
            TreeNode * rightSubTree = insertIntoBST(head, mid + 1, r);
            root -> right = rightSubTree;
            return root;
        }
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode * currNode = head;
        int length = 0;
        while(currNode != NULL)
        {
            length++;
            currNode = currNode -> next;
        }
        currNode = head;
        return insertIntoBST(&currNode, 0, length);
    }
};
