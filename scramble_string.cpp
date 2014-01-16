class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<vector<vector<char>>> scrambled;
        for (int i = 0; i <= s1.length(); i++)
        {
            scrambled.push_back(vector<vector<char>>());
            for (int j = 0; j <= s1.length(); j++)
            {
                scrambled[i].push_back(vector<char>());
                for (int k = 0; k <= s1.length(); k++)
                {
                    scrambled[i][j].push_back(0);
                }
            }
        }
        for (int i = 0; i < s1.length(); i++)
        {
            for (int j = 0; j < s2.length(); j++)
            {
                if (s1[i] == s2[j])
                {
                    scrambled[1][i][j] = 1;
                }
            }
        }
        for (int k = 2; k <= s1.length(); k++)
        {
            for (int i = 0; i + k <= s1.length(); i++)
            {
                for (int j = 0; j + k <= s2.length(); j++)
                {
                    for (int p = 1; p < k; p++)
                    {
                        if (scrambled[p][i][j] == 1 && scrambled[k - p][i + p][j + p] == 1)
                        {
                            scrambled[k][i][j] = 1;
                        }
                        if (scrambled[p][i][j + k - p] == 1 && scrambled[k - p][i + p][j] == 1)
                        {
                            scrambled[k][i][j] = 1;
                        }
                    }
                }
            }
        }
        return scrambled[s1.length()][0][0];
    }
};
