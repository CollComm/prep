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
    TreeNode * buildTree(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2)
    {
        if (r1 - l1 == 1)
        {
            return new TreeNode(inorder[l1]);
        }
        else if (r1 == l1)
        {
            return NULL;
        }
        else 
        {
            TreeNode * root = new TreeNode(postorder[r2 - 1]);
            int rootPos;
            for (int i = l1; i < r1; i++)
            {
                if (inorder[i] == postorder[r2 - 1])
                {
                    rootPos = i; 
                    break;
                }
            }
            root -> left = buildTree(inorder, l1, rootPos, postorder, l2, l2 + rootPos - l1);
            root -> right = buildTree(inorder, rootPos + 1, r1, postorder, l2 + rootPos - l1, r2 - 1);
            return root;
        }
        
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
