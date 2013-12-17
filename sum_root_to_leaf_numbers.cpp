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
    int totalSum = 0;
    void findNumbers(int currNumber, TreeNode * currNode)
    {
        if (currNode -> left == NULL && currNode -> right == NULL)
        {
            totalSum += currNumber * 10 + currNode -> val;
            return;
        }
        if (currNode -> left != NULL)
        {
            findNumbers(currNumber * 10 + currNode -> val, currNode -> left);
        }
        if (currNode -> right != NULL)
        {
            findNumbers(currNumber * 10 + currNode -> val, currNode -> right);
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        totalSum = 0;
        if (root == NULL)
        {
            return 0;
        }
        findNumbers(0, root);
        return totalSum;
    }
};
