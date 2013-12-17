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
    unordered_set<int> totalSums;
    void traverse(TreeNode * root, int sum)
    {
        if (root != NULL)
        {
            sum += root -> val;
            if (root->left == NULL && root->right == NULL)
            {
                totalSums.insert(sum);
            }
            traverse(root->left, sum);
            traverse(root->right, sum);
        }
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        totalSums.clear();
        traverse(root, 0);
        if (totalSums.find(sum) == totalSums.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
