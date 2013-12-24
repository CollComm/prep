class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> minDist;
        for (int i = 0; i <= word1.length(); i++)
        {
            vector<int> tmp;
            for (int j = 0; j <= word2.length(); j++)
            {
                tmp.push_back(1<<30);
            }
            minDist.push_back(tmp);
        }
        for (int i = 0; i <= word1.length(); i++)
        {
            minDist[i][0] = i;
        }
        for (int i = 0; i <= word2.length(); i++)
        {
            minDist[0][i] = i;
        }
        for (int i = 0; i < word1.length(); i++)
        {
            for (int j = 0; j < word2.length(); j++)
            {
                if (word1[i] == word2[j])
                {
                    minDist[i + 1][j + 1] = min(minDist[i][j], minDist[i + 1][j + 1]);
                }
                else
                {
                    minDist[i + 1][j + 1] = min(minDist[i + 1][j + 1], min(minDist[i][j + 1] + 1, min(minDist[i][j] + 1, minDist[i + 1][j] + 1)));
                }
            }
        }
        return minDist[word1.length()][word2.length()];
    }
};
