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
    TreeNode * flattenTree(TreeNode * root, TreeNode * rightTree)
    {
        if (root->left == NULL && root->right == NULL)
        {
            root -> right = rightTree;
            return root;
        }
        else
        {
            if (root -> right == NULL)
            {
                // Assume root->left != NULL
                TreeNode * leftSubTree = flattenTree(root -> left, rightTree);
                root -> left = NULL;
                root -> right = leftSubTree;
                return root;
            }
            else if (root -> left == NULL)
            {
                TreeNode * rightSubTree = flattenTree(root -> right, rightTree);
                root -> right = rightSubTree;
                return root;
            }
            else
            {
                TreeNode * rightSubTree = flattenTree(root -> right, rightTree);
                TreeNode * leftSubTree = flattenTree(root -> left, rightSubTree);
                root -> left = NULL;
                root -> right = leftSubTree;
                return root;
            }
        }
    }
public:
    void flatten(TreeNode *root) {
        if (root != NULL)
        {
            TreeNode * newRoot = flattenTree(root, NULL);
        }
    }
};
