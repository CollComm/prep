/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        stack<TreeNode *> traverseStack;
        if (root==NULL) return result;
        traverseStack.push(root);
        while(!traverseStack.empty())
        {
            TreeNode* node = traverseStack.top();
            traverseStack.pop();
            result.push_back(node->val);
            if (node->right != NULL)
            {
                traverseStack.push(node->right);
            }
            if (node->left != NULL)
            {
                traverseStack.push(node->left);
            }
        }
        return result;
    }
};
