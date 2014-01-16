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
    void recoverTree(TreeNode *root) {
        TreeNode * p1 = NULL;
        TreeNode * p2 = NULL;
        TreeNode * prevNode = NULL;
        TreeNode * currNode = root;
        while(currNode != NULL)
        {
            if (prevNode != NULL)
            {
                if (prevNode -> val > currNode -> val)
                {
                    if (p1 == NULL)
                    {
                        p1 = prevNode;
                    }
                    p2 = currNode;
                }
            }
            if (currNode -> left == NULL)
            {
                prevNode = currNode;
                currNode = currNode -> right;
            }
            else
            {
                TreeNode * rightMost = currNode -> left;
                while(rightMost -> right != NULL && rightMost -> right != currNode)
                {
                    rightMost = rightMost -> right;
                }
                if (rightMost -> right == NULL)
                {
                    rightMost -> right = currNode;
                    currNode = currNode -> left;
                }
                else
                {
                    rightMost -> right = NULL;
                    prevNode = currNode;
                    currNode = currNode -> right;
                }
            }
        }
        if (p1 != NULL && p2 != NULL)
        {
            swap(p1 -> val, p2 -> val);
        }
    }
};
