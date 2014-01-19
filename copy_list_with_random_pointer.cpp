/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    unordered_map<RandomListNode*, int> oldNodeMap;
    unordered_map<int, RandomListNode*> newNodeMap;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        int total = 0;
        if (head == NULL) return NULL;
        RandomListNode * currNode = head;
        RandomListNode * newHeadNode = new RandomListNode(head -> label);
        RandomListNode * currNewNode = newHeadNode;
        while(currNode != NULL)
        {
            total++;
            oldNodeMap[currNode] = total;
            newNodeMap[total] = currNewNode;
            if (currNode -> next != NULL)
            {
                currNewNode -> next = new RandomListNode(currNode -> next -> label);
            }
            currNewNode = currNewNode -> next;
            currNode = currNode -> next;
        }
        currNode = head;
        currNewNode = newHeadNode;
        while(currNode != NULL)
        {
            if (currNode -> random != NULL)
            {
                currNewNode -> random = newNodeMap[oldNodeMap[currNode -> random]];
            }
            currNode = currNode -> next;
            currNewNode = currNewNode -> next;
        }
        return newHeadNode;
    }
};
