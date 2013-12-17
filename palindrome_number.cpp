class Solution {
    int getDigit(int x, int pos)
    {
        int tmp = 1;
        for(int i = 0; i < pos ; i++)
        {
            tmp *= 10;
        }
        return (x / tmp) % 10;
    }
    int getLength(int x)
    {
        if (x >= 0 && x <= 9)
        {
            return 1;
        }
        else
        {
            return getLength(x/10) + 1;
        }
    }
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        else
        {
            int l = getLength(x);
            bool answer = true;
            for(int i = 0; i < (l / 2); i++)
            {
                if (getDigit(x, i) != getDigit(x, l - i - 1))
                {
                    answer = false;
                }
            }
            return answer;
        }
    }
};
