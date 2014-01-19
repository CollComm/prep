class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        vector<int> failureFunction;
        int needleLength = 0;
        while(needle[needleLength] != 0)
        {
            needleLength++;
            failureFunction.push_back(0);
        }
		failureFunction.push_back(0);
        if (needleLength == 0)
        {
            return haystack;
        }
        int j = 0;
        for (int i = 2; i <= needleLength; i++)
        {
            if (needle[i - 1] == needle[j])
            {
                failureFunction[i] = j + 1;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = failureFunction[j];
                    i--;
                }
            }
        }
        j = 0;
        for (int i = 0; haystack[i] != 0; i++)
        {
            if (haystack[i] == needle[j])
            {
                j++;
                if (j == needleLength)
                {
                    return haystack + i - j + 1;
                }
            }
            else
            {
                if (j != 0)
                {
                    j = failureFunction[j];
                    i--;
                }
            }
        }
        return NULL;
    }
};
