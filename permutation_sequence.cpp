class Solution {
    void getPermutation(int maxN, int box, int k, int totalDigits, int visited, string & a)
    {
        if (box == 0)
        {
            for (int i = 1; i <= maxN; i++)
            {
                if ((visited & (1 << i)) == 0)
                {
                    a.push_back(i + '0');
                    return;
                }
            }
        }
        else
        {
            int pos = k / totalDigits;
            int i = 1;
            for (; i <= maxN; i++)
            {
                if ((visited & (1 << i)) == 0)
                {
                    if (pos == 0)
                    {
                        a.push_back(i + '0');
                        break;
                    }
                    else
                    {
                        pos--;
                    }
                }
            }
            getPermutation(maxN, box - 1, k % totalDigits, totalDigits / box, visited | (1 << i), a);
        }
    }
public:
    string getPermutation(int n, int k) {
        int totalDigits = 1;
        for (int i = 1; i <= n - 1; i++)
        {
            totalDigits *= i;
        }
        string ans;
        int visited = 0;
        getPermutation(n, n - 1, k - 1, totalDigits, visited, ans);
        return ans;
    }
};
