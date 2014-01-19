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
    int globalMaxPathSum;
    int getMaxValue(TreeNode * root)
    {
        if (root == NULL) return 0;
        int l = getMaxValue(root -> left);
        int r = getMaxValue(root -> right);
        int maxValue = root -> val;
        if (l > 0) maxValue += l;
        if (r > 0) maxValue += r;
        if (maxValue > globalMaxPathSum)
        {
            globalMaxPathSum = maxValue;
        }
        if (l > 0 && l >= r) return l + root -> val;
        if (r > 0 && r > l) return r + root -> val;
        return root -> val;
    }
public:
    int maxPathSum(TreeNode *root) {
        globalMaxPathSum = -(1<<30);
        getMaxValue(root);
        return globalMaxPathSum;
    }
};
