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
public:
    bool isSymmetric(TreeNode *left, TreeNode* right)
    {
        if (left==NULL && right == NULL)
        {
            return true;
        }
        else if ((left == NULL && right != NULL) || (left != NULL && right == NULL))
        {
            return false;
        }
        else
        {
            // Both subtree are not NULL
            if (left -> val == right -> val)
            {
                return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
            }
            else
            {
                return false;
            }
        }
    }
    bool isSymmetric(TreeNode *root) {
        if (root==NULL)
        {
            return true;
        }
        else
        {
            return isSymmetric(root->left, root->right);
        }
        
    }
};
