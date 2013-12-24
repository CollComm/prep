/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NodeType
{
    TreeNode * node;
    int level;
    NodeType(TreeNode* cur, int l):level(l), node(cur){}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > answer;
        queue<NodeType> queueNodes;
        if (root == NULL)
        {
            return answer;
        }
        queueNodes.push(NodeType(root, 0));
        while(!queueNodes.empty())
        {
            NodeType currNode = queueNodes.front();
            if (currNode.level >= answer.size())
            {
                vector<int> currLevel;
                answer.push_back(currLevel);
            }
            answer[currNode.level].push_back(currNode.node->val);
            if (currNode.node -> left != NULL)
            {
                queueNodes.push(NodeType(currNode.node->left, currNode.level + 1));
            }
            if (currNode.node -> right != NULL)
            {
                queueNodes.push(NodeType(currNode.node->right, currNode.level + 1));
            }
            queueNodes.pop();
        }
        bool turnOver = false;
        for (int i = 0; i < answer.size(); i++)
        {
            if (turnOver)
            {
                for (int j = 0; j < answer[i].size() / 2; j++)
                {
                    swap(answer[i][j], answer[i][answer[i].size() - j - 1]);
                }
            }
            turnOver = !turnOver;
        }
        return answer;
    }
};
