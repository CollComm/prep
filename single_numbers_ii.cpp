class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones[32];
        memset(ones, 0, sizeof(ones));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 31; j++)
            {
                if ((A[i] & (1<<j))!=0)
                {
                    ones[j]++;
                }
            }
        }
        int theOne = 0;
        for (int j = 0; j <= 31; j++)
        {
            if (ones[j]%3 != 0)
            {
                theOne = theOne | (1<<j);
            }
        }
        return theOne;
    }
};
