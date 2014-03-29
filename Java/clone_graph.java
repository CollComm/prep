/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
        {
            return null;
        }
        UndirectedGraphNode newHead = new UndirectedGraphNode(node.label);
        LinkedList<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>();
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hashMap = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        queue.push(node);
        hashMap.put(node, newHead);
        while(!queue.isEmpty())
        {
            UndirectedGraphNode tmpNode = queue.pop();
            for (int i = 0; i < tmpNode.neighbors.size(); i++)
            {
                if (hashMap.containsKey(tmpNode.neighbors.get(i)))
                {
                    hashMap.get(tmpNode).neighbors.add(hashMap.get(tmpNode.neighbors.get(i)));
                }
                else
                {
                    UndirectedGraphNode newNode = new UndirectedGraphNode(tmpNode.neighbors.get(i).label);
                    hashMap.put(tmpNode.neighbors.get(i), newNode);
                    hashMap.get(tmpNode).neighbors.add(newNode);
                    queue.push(tmpNode.neighbors.get(i));
                }
            }
        }
        return newHead;
    }
}
