struct hashFunc
{
    unsigned int operator()(const vector<int> &x) const
    {
        int total = 1; 
        for (int i = 0; i < x.size(); i++)
        {
            total*=x[i];
        }
        if (total<0)
        {
            return -total;
        }
        else
        {
            return total;
        }
    }
};
struct compFunc
{
    bool operator()(const vector<int> & a, const vector<int> & b) const
    {
        if (a.size() != b.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
};
class Solution {
    vector<vector<int> > answer;
    unordered_set<vector<int>, hashFunc, compFunc> existed;
    void dfs(vector<int> combo, int n, int k)
    {
        if (k == 0)
        {
            if (existed.find(combo) == existed.end())
            {
                answer.push_back(combo);
                existed.insert(combo);
            }
        }
        else
        {
	    vector<int> newNumbers = combo;
		int initNumber = 0;
		if (combo.size() > 0)
		{
			initNumber = combo[combo.size() - 1] + 1;
		}
		else
		{
			initNumber = 1;
		}
            for (int i = initNumber; i <= n; i++)
            {
				newNumbers.push_back(i);
                dfs(newNumbers, n, k-1);
				newNumbers.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        answer.clear();
		existed.clear();
        vector<int> v;
        dfs(v, n, k);
		return answer;
    }
};
