class Solution {
    vector<vector<int> > answer;
    vector<int> backupS;
    void findSubSets(vector<int> currSet, int numberLeft)
    {
        vector<int> result;
        for(int i = 0; i < currSet.size(); i++)
        {
            result.push_back(backupS[currSet[i]]);
        }
        answer.push_back(result);
        if (numberLeft == 0)
        {
            return;
        }
        else
        {
            int minIndex = 0;
            if (currSet.size() != 0)
            {
                minIndex = currSet[currSet.size() - 1] + 1;
            }
            for(int i = minIndex; i < backupS.size(); i++)
            {
                currSet.push_back(i);
                findSubSets(currSet, numberLeft - 1);
                currSet.pop_back();
            }
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        answer.clear();
        backupS.clear();
        vector<int> emptyVector;
        //answer.push_back(emptyVector);
            for(int i = 0; i < S.size(); i++)
            {
                backupS.push_back(S[i]);
            }
            findSubSets(emptyVector, S.size());
        return answer;
    }
};
