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
    TreeNode *buildTree(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2)
    {
        if (r2 - l2 == 1)
        {
            return new TreeNode(inorder[l2]);
        }
        else if (r2 == l2)
        {
            return NULL;
        }
        else
        {
            TreeNode * root = new TreeNode(preorder[l1]);
            int rootPos = 0;
            for (int i = l2; i < r2; i++)
            {
                if (inorder[i] == root -> val)
                {
                    rootPos = i;
                    break;
                }
            }
            TreeNode * leftSubTree = buildTree(preorder, l1 + 1, l1 + 1 + rootPos - l2, inorder, l2, rootPos);
            TreeNode * rightSubTree = buildTree(preorder, l1 + 1 + rootPos - l2, r1, inorder, rootPos + 1, r2);
            root -> left = leftSubTree;
            root -> right = rightSubTree;
            return root;
        }
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
