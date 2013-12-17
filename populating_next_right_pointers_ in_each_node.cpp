/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        {
            return;
        }
        TreeLinkNode * parentNode = root;
        TreeLinkNode * currNode = NULL;
        if (root -> left != NULL)
        {
            currNode = root->left;
        }
        else
        {
            currNode = root->right;
        }
        while(currNode != NULL)
        {
            TreeLinkNode * nextNode = currNode;
            while(nextNode != NULL)
            {
                if (nextNode == parentNode->left && parentNode -> right != NULL)
                {
                    nextNode -> next = parentNode -> right;
                }
                else
                {
                    nextNode -> next = NULL;
                        while(parentNode -> next != NULL)
                        {
                            parentNode = (parentNode) -> next;
                            if ((parentNode) -> left != NULL)
                            {
                                nextNode -> next = (parentNode) -> left;
                                break;
                            }
                            else if ((parentNode) -> right != NULL)
                            {
                                nextNode -> next = (parentNode) -> right;
                                break;
                            }
                        }
                }
                nextNode = nextNode -> next;
            }
            parentNode = currNode;
            while (parentNode != NULL)
            {
                if (parentNode -> left != NULL)
                {
                    currNode = parentNode -> left;
                    break;
                }
                else if (parentNode -> right != NULL)
                {
                    currNode = parentNode -> right;
                    break;
                }
                else
                {
                    parentNode = parentNode -> next;
                }
            }
            if (parentNode == NULL)
            {
                break;
            }
        }
    }
};
