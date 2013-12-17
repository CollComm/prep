struct hashFunc{
	unsigned long operator()(const string& key) const {
        unsigned long hash = 0;
        for(size_t i=0; i<key.size(); i++)
            hash += (71*hash + key[i]) % 5;
        return hash;
    }
};
struct compFunc{
	bool operator()(const string& t1, const string& t2) const {
        return !(t1.compare(t2));
    }
};
class Solution {
    vector<string> answer;
    unordered_set<string, hashFunc, compFunc> existed; 
    void dfs(string currStr, int n, int open)
    {
        if (n == 0 && open == 0)
        {
            if (existed.find(currStr) == existed.end())
            {
				existed.insert(currStr);
                answer.push_back(currStr);
                return;
            }
        }
        else
        {
            string newStr;
			newStr.append(currStr);
			if (open > 0)
			{
				if (n > 0)
				{
					newStr.push_back('(');
					dfs(newStr, n - 1, open + 1);
					newStr.pop_back();
				}
				newStr.push_back(')');
				dfs(newStr, n, open - 1);
			}
			else
			{
				newStr.push_back('(');
				dfs(newStr, n - 1, open + 1);
				newStr.pop_back();
			}
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        answer.clear();
        existed.clear();
        string initStr;
        dfs(initStr, n, 0);
        return answer;
    }
};
