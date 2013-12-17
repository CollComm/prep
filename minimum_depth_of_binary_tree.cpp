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
    int minTreeDepth;
    void dfs(TreeNode* root, int distance)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
            {
                dfs(root->left, distance + 1);
            }
            if (root->right != NULL)
            {
                dfs(root->right, distance + 1);
            }
            if (root->left == NULL && root->right == NULL)
            {
                if (distance < minTreeDepth)
                {
                    minTreeDepth = distance;
                }
            }
        }
    }
public:
    int minDepth(TreeNode *root) {
        minTreeDepth = 1<<30;
        if (root == NULL)
        {
            return 0;
        }
        dfs(root, 1);
        return minTreeDepth;
    }
};
