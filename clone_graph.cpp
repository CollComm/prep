/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<int, UndirectedGraphNode *> existed;
    UndirectedGraphNode * solveCloneGraph(UndirectedGraphNode * node)
    {
        UndirectedGraphNode * currNode = new UndirectedGraphNode(node -> label);
        existed[node -> label] = currNode;
        for (int i = 0; i < (node -> neighbors).size(); i++)
        {
            if (existed.find(node->neighbors[i] -> label) == existed.end())
            {
                currNode -> neighbors.push_back(solveCloneGraph((node -> neighbors)[i]));
            }
            else
            {
                currNode -> neighbors.push_back(existed[(node->neighbors[i]) -> label]);
            }
        }
        return currNode;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        existed.clear();
        if (node == NULL) return NULL;
        return solveCloneGraph(node);
    }
};
