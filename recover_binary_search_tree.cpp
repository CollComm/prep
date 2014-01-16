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
    void inorder(TreeNode *& p1, TreeNode *& p2, TreeNode * currNode, TreeNode *& prevNode)
    {
        if (currNode == NULL)
        {
            return;
        }
        else
        {
            inorder(p1, p2, currNode -> left, prevNode);
            if (prevNode != NULL && prevNode -> val > currNode -> val)
            {
                if (p1 == NULL)
                {
                    p1 = prevNode;
                }
                p2 = currNode;
            }
            prevNode = currNode;
            inorder(p1, p2, currNode -> right, prevNode);
        }
    }
public:
    void recoverTree(TreeNode *root) {
        TreeNode * p1 = NULL;
        TreeNode * p2 = NULL;
        TreeNode * prevNode = NULL;
        inorder(p1, p2, root, prevNode);
        if (p1 != NULL && p2 != NULL)
        {
            swap(p1 -> val, p2 -> val);
        }
    }
};
