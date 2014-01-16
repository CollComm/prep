class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int>> alphaData;
        vector<int> lastRowCount;
        vector<int> thisRowCount;
        for (int i = 0; i < T.length(); i++)
        {
            alphaData.push_back(vector<int>());
        }
        for (int i = 0; i < T.length(); i++)
        {
            for (int j = 0; j < S.length(); j++)
            {
                if (T[i] == S[j])
                {
                    alphaData[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < T.length(); i++)
        {
            thisRowCount.clear();
            for (int j = 0; j < alphaData[i].size(); j++)
            {
                thisRowCount.push_back(0);
            }
            for (int j = 0; j < alphaData[i].size(); j++)
            {
                if (i == 0)
                {
                    thisRowCount[j] = 1;
                }
                else
                {
                    for (int k = 0; k < alphaData[i - 1].size(); k++)
                    {
                        if (alphaData[i - 1][k] < alphaData[i][j])
                        {
                            thisRowCount[j] += lastRowCount[k];
                        }
                    }
                }
            }
            lastRowCount = thisRowCount;
        }
        int ans = 0;
        for (int i = 0; i < lastRowCount.size(); i++)
        {
            ans += lastRowCount[i];
        }
        return ans;
    }
};
