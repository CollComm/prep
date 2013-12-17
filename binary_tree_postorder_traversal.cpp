/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct stackNode 
{
    TreeNode* node;
    char state;
    stackNode(TreeNode* n, char s):node(n), state(s){}
};
class Solution {
    stack<stackNode> fullStack;
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack<stackNode> emptyStack;
        fullStack.swap(emptyStack);
        if (root == NULL)
        {
            return answer;
        }
        fullStack.push(stackNode(root, 0));
        while(!fullStack.empty())
        {
            stackNode currNode = fullStack.top();
            fullStack.pop();
            if (currNode.state == 0)
            {
                fullStack.push(stackNode(currNode.node, 1));
                if (currNode.node->right != NULL)
                {
                    fullStack.push(stackNode(currNode.node->right, 0));
                }
                if (currNode.node->left != NULL)
                {
                    fullStack.push(stackNode(currNode.node->left, 0));
                }
            }
            else
            {
                answer.push_back(currNode.node->val);
            }
        }
        return answer;
    }
};
