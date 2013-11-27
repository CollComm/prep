#include<cstring>
#include<stack>
#include<vector>
using namespace std;
struct TrieNode {
    int alphabet[26];
    int count;
};
struct SearchNode {
    int trie_node;
    int pos;
};
class Solution {
    TrieNode trieNode[5000];
    int totalNode;
    stack<SearchNode> dfsStack; 
    vector<int> target;
    void insertNode(string s)
    {
        TrieNode* currNode = trieNode;
        for(int i = 0; i < s.length(); i++)
        {
            if (currNode -> alphabet[s[i] - 'a'] == 0)
            {
                // Does not exist, so we insert it
                totalNode = totalNode + 1;
                currNode -> alphabet[s[i] - 'a'] = totalNode;
                currNode = trieNode + totalNode;
            }
            else
            {
                currNode = trieNode + currNode -> alphabet[s[i] - 'a'];
            }
        }
        currNode -> count ++;
    }
    bool solve(string s)
    {
        SearchNode snode;
        if (s.length() == 0)
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            target.push_back(s[i] - 'a');
        }
        bool found = false;
        snode.pos = 0;
        snode.trie_node = trieNode[0].alphabet[target[0]];
        dfsStack.push(snode);
        while(!dfsStack.empty())
        {
            snode = dfsStack.top();
            dfsStack.pop();
            if (snode.trie_node != 0)
            {
                if (snode.pos == target.size() - 1)
                {
                    if (trieNode[snode.trie_node].count > 0)
                    {
                        found = true;
                        break;
                    }
                }
                else
                {
                    // two choices
                    SearchNode newNode;
					newNode.pos = snode.pos + 1;
                    // choice one: stay here
                    if (trieNode[snode.trie_node].count > 0)
                    {
                        newNode.trie_node = trieNode[0].alphabet[target[newNode.pos]];
						if (newNode.trie_node == 0)
						{
							break;
						}
                        dfsStack.push(newNode);
                    }
                    // choice two: skip this node
                    newNode.trie_node = trieNode[snode.trie_node].alphabet[target[newNode.pos]];
                    dfsStack.push(newNode);
                }
            }
        }
        return found;
    }
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // Initialization
        totalNode = 0;
        memset(trieNode, 0, sizeof(trieNode));
        while(!dfsStack.empty())
        {
            dfsStack.pop();
        }
        target.clear();
        for (auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            insertNode(*iter);
        }
        return solve(s);
    }
};
