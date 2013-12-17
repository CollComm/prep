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
    vector<vector<int> > answer;
    int targetSum;
    void findPath(TreeNode *currNode, int sum, vector<int> prevNodeVal)
    {
        if (currNode->left == NULL && currNode->right == NULL)
        {
            if (sum + currNode->val == targetSum)
            {
                prevNodeVal.push_back(currNode->val);
                answer.push_back(prevNodeVal);
                // Assume no duplicate values
            }
        }
        else
        {
            prevNodeVal.push_back(currNode->val);
            if (currNode->left != NULL)
            {
                findPath(currNode->left, sum + currNode->val, prevNodeVal);
            }
            if (currNode->right != NULL)
            {
                findPath(currNode->right, sum + currNode->val, prevNodeVal);
            }
        }
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        answer.clear();
        if (root == NULL)
        {
            return answer;
        }
        targetSum = sum;
        vector<int> emptyVector;
        findPath(root, 0, emptyVector);
        return answer;
    }
};
