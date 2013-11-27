#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<string>
#include<iterator>
using namespace std;
struct TrieNode {
    int next[26];
    int count;
};
struct StateNode {
    int startPoint;
    int length;
};
TrieNode tNode[50000];
TrieNode root;
string parentS;
vector<string> allSentences;
vector<string> dictionary;
class Solution {
    int totalLen;
    int totalNodes;
    bool existed(int startPoint, int len)
    {
        TrieNode* currNode = &root;
        for (int i = startPoint; i < startPoint + len; i++)
        {
            if (currNode -> next[parentS[i] - 'a'] != 0)
            {
                currNode = tNode + (currNode -> next[parentS[i] - 'a']);
            }
            else
            {
                return false;
            }
        }
        if (currNode -> count > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertIntoTrie(string s)
    {
        TrieNode* currNode = &root;
        for(int i = 0; i < s.length(); i++)
        {
            // Assume the alphabet is from a to z
            if (currNode->next[s[i]-'a']==0)
            {
                // New node
                totalNodes++;
                currNode->next[s[i]-'a'] = totalNodes;
            }
            currNode = tNode + currNode->next[s[i] - 'a'];
        }
        currNode->count = currNode -> count + 1;
    }
public:
	void enumSolV2(vector<StateNode> currSol, int currPos)
	{
		if (totalLen - currPos == 0)
        {
            string sentence;
            for(int i = 0; i < currSol.size() - 1; i++)
            {
                sentence = sentence + parentS.substr(currSol[i].startPoint, currSol[i].length) + " ";
            }
            sentence = sentence + parentS.substr(currSol[currSol.size() - 1].startPoint, currSol[currSol.size() - 1].length);
            allSentences.push_back(sentence);
        }
        else
        {
        for(int i = 0; i < dictionary.size(); i++)
        {
			bool isFound = true;
			if (currPos + dictionary[i].length() > parentS.length()) continue;
			for (int j = 0; j < dictionary[i].length(); j++)
				if (parentS[currPos + j] != dictionary[i][j])
				{
					isFound = false;break;
				}
			if (isFound == true)
			{
				vector<StateNode> currRecord = currSol;
                StateNode snode;
                snode.startPoint = currPos;
                snode.length = dictionary[i].length();
				currRecord.push_back(snode);
				enumSolV2(currRecord, currPos + dictionary[i].length());
			}
        }
        }
	}
	bool precheck(vector<string> dict, string s)
	{
		char str[26];
		memset(str, 0, sizeof(str));
		for (int i = 0; i < dict.size(); i++)
		{
			for (int j = 0; j < dict[i].length(); j++)
			{
				str[dict[i][j] - 'a'] = 1;
			}
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (str[s[i]-'a'] != 1)
			{
				return false;
			}
		}
		return true;
	}
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        parentS = s;
        totalLen = s.length();
        memset(tNode, 0, sizeof(tNode));
		memset(&root, 0, sizeof(root));
        allSentences.clear();
        totalNodes = 0;
		dictionary.clear();
        for(auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            insertIntoTrie(*iter);
			dictionary.push_back(*iter);
        }
		if (precheck(dictionary, s))
		{
			vector<StateNode> init;
			//enumSol(init, 0);
			enumSolV2(init, 0);
		}
        return allSentences;
    }
};
