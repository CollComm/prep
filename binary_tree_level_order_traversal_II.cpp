/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct traverseNode {
    TreeNode* node;
    int level;
    traverseNode(TreeNode* r, int l):node(r), level(l){}
};
class Solution {
    queue<traverseNode> traverseQueue;
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > answer;
        if (root == NULL)
        {
            return answer;
        }
        queue<traverseNode> tmpQueue;
        traverseQueue.swap(tmpQueue);
        traverseQueue.push(traverseNode(root, 1));
        while(!traverseQueue.empty())
        {
            traverseNode topNode = traverseQueue.front();
            if (topNode.level > answer.size())
            {
                vector<int> emptyVector;
                answer.push_back(emptyVector);
            }
            answer[topNode.level - 1].push_back(topNode.node->val);
            traverseQueue.pop();
            if (topNode.node -> left != NULL)
            {
                traverseQueue.push(traverseNode(topNode.node->left, topNode.level + 1));
            }
            if (topNode.node -> right != NULL)
            {
                traverseQueue.push(traverseNode(topNode.node->right, topNode.level + 1));
            }
        }
        for (int i = 0; i < (answer.size()/2); i++)
        {
            answer[i].swap(answer[answer.size() - i - 1]);
        }
        return answer;
    }
};
