/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root==NULL) return;
        if (root->left == NULL || root->right == NULL) return;
        TreeLinkNode * node = root;
        while (node->next!=NULL)
        {
            if (node->left!=NULL)
            {
                node->left->next = node->right;
                if (node->next!=NULL)
                node->right->next = node->next->left;
            }
            node = node->next;
        }
        node->left->next = node->right;
        connect(root->left);
    }
};
