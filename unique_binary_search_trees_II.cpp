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
    vector<TreeNode *> constructBST(int l, int r)
    {
        vector<TreeNode *> result;
        if (l > r)
        {
            result.push_back(NULL);
        } else if (l == r)
        {
            result.push_back(new TreeNode(l));
        } else
        {
            for (int i = l; i <= r; i++)
            {
                vector<TreeNode *> leftSubTrees = constructBST(l, i - 1);
                vector<TreeNode *> rightSubTrees = constructBST(i + 1, r);
                
                for (int j = 0; j < leftSubTrees.size(); j++)
                    for (int k = 0; k < rightSubTrees.size(); k++)
                    {
                        TreeNode * currNode = new TreeNode(i);
                        currNode -> left = leftSubTrees[j];
                        currNode -> right  = rightSubTrees[k];
                        result.push_back(currNode);
                    }
            }
        }
        return result;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return constructBST(1, n);
    }
};
