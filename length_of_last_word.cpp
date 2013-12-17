class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int wordLength = 0; 
        if (s == NULL)
        {
            return 0;
        }
        for (int i = 0; s[i] != 0; i++)
        {
            if (s[i] != ' ')
            {
                if (i >= 1)
                {
                    if (s[i - 1] == ' ')
                    {
                        wordLength = 1;
                    }
                    else
                    {
                        wordLength++;
                    }
                }
                else
                {
                    wordLength = 1;
                }
            }
        }
        return wordLength;
    }
};
