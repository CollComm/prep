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
struct stackNode {
    char state;
    TreeNode * currNode;
    stackNode(TreeNode* x, char s) : currNode(x), state(s) {}
};
class Solution {
    stack<stackNode> mainStack;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<stackNode> emptyStack;
        mainStack.swap(emptyStack);
        mainStack.push(stackNode(root, 0));
        vector<int> answer;
        if (root == NULL) return answer;
        while(!mainStack.empty())
        {
            stackNode topNode = mainStack.top();
            mainStack.pop();
            if (topNode.state == 0)
            {
            if (topNode.currNode->right != NULL)
            {
                mainStack.push(stackNode(topNode.currNode->right, 0));
            }
            mainStack.push(stackNode(topNode.currNode, 1));
            if (topNode.currNode->left != NULL)
            {
                mainStack.push(stackNode(topNode.currNode->left, 0));
            }
            }
            else
            {
                answer.push_back(topNode.currNode->val);
            }
        }
        return answer;
    }
};
