/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct StateNode {
	TreeNode treeNode;
	int height;
public:
	StateNode():height(0), treeNode(0) {}
};
#include<stack>
class Solution {
    stack<StateNode> treeStack;
public:
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		stack<StateNode> tmp;
		treeStack.swap(tmp);
		int maxHeight = 0;
		if (root != NULL)
		{
		StateNode initState;
		initState.height = 1;
		initState.treeNode = *root;
        treeStack.push(initState);
        while(!treeStack.empty())
        {
            StateNode sNode = treeStack.top();
			if (sNode.height > maxHeight)
			{
				maxHeight = sNode.height;
			}
			treeStack.pop();
            if (sNode.treeNode.left != NULL)
			{
				StateNode newNode;
				newNode.height = sNode.height + 1;
				newNode.treeNode = *sNode.treeNode.left;
				treeStack.push(newNode);
			}
            if (sNode.treeNode.right != NULL)
			{
				StateNode newNode;
				newNode.height = sNode.height + 1;
				newNode.treeNode = *sNode.treeNode.right;
				treeStack.push(newNode);
			}
        }
		}
        return maxHeight;
    }
};
