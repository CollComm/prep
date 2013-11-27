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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if ((p != NULL && q == NULL)||(p == NULL && q!= NULL))
        {
            return false;
        }
        else
        {
        if (p->val == q->val)
        {
            if (p->left == NULL && q->left == NULL)
            {
                if (p->right == NULL && q->right == NULL)
                {
                    return true;
                }
                else if ((p->right == NULL && q->right != NULL) || (p->right != NULL && q->right == NULL))
                {
                    return false;
                }
                else
                {
                    return isSameTree(p->right, q->right);
                }
            }
            else if ((p->left == NULL && q->left != NULL) || (p->left != NULL && q->left == NULL))
            {
                return false;
            }
            else
            {
                if (p->right == NULL && q->right == NULL)
                {
                    return isSameTree(p->left, q->left);
                }
                else if ((p->right == NULL && q->right!=NULL) || (p->right != NULL) && (q->right == NULL))
                {
                    return false;
                }
                else
                {
                    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
                }
            }
        }
        else
        {
            return false;
        }
        }
    }
};
