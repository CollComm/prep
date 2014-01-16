class Solution {
    string getLongestPalindrome(string& str)
    {
        int C = 0;
        int R = 0;
        int* P = new int[str.length()];
        for (int i = 0; i < str.length(); i++)
        {
            int i_mirror = C - (i - C);
            P[i] = ((R > i) && (i_mirror >= 0))? min(R-i, P[i_mirror]):0;
            while ((i + P[i] + 1 < str.length()) && (i - P[i] - 1 >= 0) && str[i + P[i] + 1] == str[i - P[i] - 1])
            {
                P[i]++;
            }
            if ((i + P[i]) > R)
            {
                R = i + P[i];
                C = i;
            }
        }
        int maxLength = -1;
        int maxPos = -1;
        for (int i = 0; i < str.length(); i++)
        {
            if (P[i] > maxLength)
            {
                maxLength = P[i];
                maxPos = i;
            }
            else if (P[i] == maxLength)
            {
                if (str[i + P[i]] != 0)
				{
					maxPos = i;
				}
            }
        }
        delete[] P;
        return str.substr(maxPos - maxLength, maxLength * 2 + 1);
    }
public:
    string longestPalindrome(string s) {
        string newS;
		string bestAns;
        for (int i = 0; i < s.length(); i++)
        {
            newS.push_back(s[i]);
            newS.push_back(0);
        }
        newS.pop_back();
        string stringWithPaddedChars = getLongestPalindrome(newS);
        for (int i = 0; i < stringWithPaddedChars.length(); i++)
        {
            if (stringWithPaddedChars[i] != 0)
            {
                bestAns.push_back(stringWithPaddedChars[i]);
            }
        }
        return bestAns;
    }
};
