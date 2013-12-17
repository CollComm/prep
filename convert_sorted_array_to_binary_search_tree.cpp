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
    TreeNode *divideAndConquer(vector<int> &num, int l, int r)
    {
        if (r - l == 1)
        {
            return new TreeNode(num[l]);
        }
        else if (r - l == 0)
        {
            return NULL;
        }
        else
        {
            int mid = (l + r) / 2;
            TreeNode* root = new TreeNode(num[mid]);
            root -> left = divideAndConquer(num, l, mid);
            root -> right = divideAndConquer(num, mid+1, r);
            return root;
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
        {
            return NULL;
        }
        else
        {
            return divideAndConquer(num, 0, num.size());
        }
    }
};
