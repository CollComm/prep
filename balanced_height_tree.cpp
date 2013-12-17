/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<cstdlib>
 #include<algorithm>
 using namespace std;
class Solution {
    bool isSubTreeBalanced;
public:
    int getHeight(TreeNode *root)
    {
        int rightSubTreeHeight = 0;
        int leftSubTreeHeight = 0;
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            if (root->left == NULL)
            {
                rightSubTreeHeight = getHeight(root->right);
                if (rightSubTreeHeight > 1)
                {
                    isSubTreeBalanced = false;
                }
                return rightSubTreeHeight + 1;
            }
            else if (root->right == NULL)
            {
                leftSubTreeHeight = getHeight(root->left);
                if (leftSubTreeHeight > 1)
                {
                    isSubTreeBalanced = false;
                }
                return leftSubTreeHeight + 1;
            }
            else
            {
                leftSubTreeHeight = getHeight(root->left);
                rightSubTreeHeight = getHeight(root->right);
                if (abs(leftSubTreeHeight-rightSubTreeHeight)>1)
                {
                    isSubTreeBalanced = false;
                }
                return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
            }
        }
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            isSubTreeBalanced = true;
            int left_height = getHeight(root->left);
            int right_height = getHeight(root->right);
            if (abs(left_height-right_height)<=1)
            {
                if (isSubTreeBalanced)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
};
