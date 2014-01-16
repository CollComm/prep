class Solution {
public:
    int minCut(string s) {
        vector<vector<char>> isPalindrome;
        vector<int> minCutDp;
        for (int i = 0; i <= s.length(); i++)
        {
            isPalindrome.push_back(vector<char>());
            minCutDp.push_back(1 << 30);
            for (int j = 0; j <= s.length(); j++)
            {
                isPalindrome[i].push_back(0);
            }
        }
        minCutDp[0] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            isPalindrome[i][i+1] = 1;
            isPalindrome[i][i] = 1;
        }
        for (int i = 2; i <= s.length(); i++)
        {
            for (int j = 0; j + i <= s.length(); j++)
            {
                if (s[j] == s[j + i - 1])
                {
                    isPalindrome[j][j + i] = isPalindrome[j + 1][j + i - 1];
                }
                else
                {
                    isPalindrome[j][j + i] = 0;
                }
            }
        }
        for (int i = 1; i <= s.length(); i++)
        {
            if (isPalindrome[0][i])
            {
                minCutDp[i] = 0;
            }
            for (int j = 1; j < i; j++)
            {
                if (isPalindrome[j][i])
                {
                    minCutDp[i] = min(minCutDp[i], minCutDp[j] + 1);
                }
            }
        }
        return minCutDp[s.length()];
    }
};
