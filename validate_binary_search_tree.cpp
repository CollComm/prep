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
    bool answer;
    void checkBST(TreeNode * root, int &minV, int &maxV)
    {
        if ((root->left == NULL) && (root->right == NULL))
        {
            minV = maxV = root->val;
        }
        else
        {
            int minValue, maxValue;
            bool updated = false;
            if (root -> left != NULL)
            {
                
                checkBST(root -> left, minValue, maxValue);
                if (maxValue >= root -> val)
                {
                    answer = false;
                    return;
                }
                minV = minValue;
                maxV = maxValue;
                updated = true;
            }
            if (root -> right != NULL)
            {
                checkBST(root -> right, minValue, maxValue);
                if (minValue <= root -> val)
                {
                    answer = false;
                    return;
                }
                if (updated)
                {
                    minV = min(minV, minValue);
                    maxV = max(maxV, maxValue);
                }
                else
                {
                    minV = minValue;
                    maxV = maxValue;
                }
            }
            minV = min(root -> val, minV);
            maxV = max(root -> val, maxV);
        }
    }
public:
    bool isValidBST(TreeNode *root) {
        answer = true;
        if (root == NULL)
        {
            return true;
        }
        else
        {
            int minValue, maxValue;
            checkBST(root, minValue, maxValue);
        }
        return answer;
    }
};
