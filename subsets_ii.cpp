struct compFunc
{
    int operator()(const vector<int> & a, const vector<int> & b) const
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
struct hashFunc
{
    unsigned int operator()(const vector<int> & a) const
    {
        int hValue = 1;
        for (int i = 0; i < a.size(); i++)
        {
            hValue *= a[i];
        }
        return (unsigned int)hValue;
    }
};
class Solution {
    unordered_set<vector<int>, hashFunc, compFunc> existed;
    vector<vector<int> > answer;
    vector<int> backupS;
    void findSubSets(vector<int> currSet, int numberLeft)
    {
        vector<int> transSet;
        for (int i = 0; i < currSet.size(); i++)
        {
            transSet.push_back(backupS[currSet[i]]);
        }
        if (existed.find(transSet) == existed.end())
        {
            existed.insert(transSet);
            answer.push_back(transSet);
        }
        if (numberLeft != 0)
        {
            int minIndex = 0;
            if (currSet.size() > 0)
            {
                minIndex = currSet[currSet.size() - 1] + 1;
            }
            for (int i = minIndex; i < backupS.size(); i++)
            {
                currSet.push_back(i);
                findSubSets(currSet, numberLeft - 1);
                currSet.pop_back();
            }
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        answer.clear();
        existed.clear();
        for(int i = 0; i < S.size(); i++)
        {
            backupS.push_back(S[i]);
        }
        sort(backupS.begin(), backupS.end());
        vector<int> emptySet;
        findSubSets(emptySet, S.size());
        return answer;
    }
};
