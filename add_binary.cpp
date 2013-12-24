class Solution {
    void calcOneDigit(int &i, int &pos, string & ans, string & a, bool& carryOver)
    {
        while(i >= 0)
        {
            if (carryOver)
            {
                if (a[i] == '1')
                {
                    ans[pos] = '0';
                }
                else
                {
                    ans[pos] = '1';
                    carryOver = false;
                }
            }
            else
            {
                ans[pos] = a[i];
            }
            i--;
            pos--;
        }
    }
public:
    string addBinary(string a, string b) {
        if (a.length() == 0)
        {
            return b;
        }
        if (b.length() == 0)
        {
            return a;
        }
        int i = a.length() - 1, j = b.length() - 1;
        int pos = max(a.length(), b.length());
        bool carryOver = false;
        string answer(pos + 1, ' ');
        for (;i >= 0 && j >= 0; pos--, i--, j--)
        {
            if (a[i] == '0' && b[j] == '0')
            {
                if (carryOver)
                {
                    answer[pos] = '1';
                    carryOver = false;
                }
                else
                {
                    answer[pos] = '0';
                }
            }
            else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
            {
                if (carryOver)
                {
                    answer[pos] = '0';
                }
                else
                {
                    answer[pos] = '1';
                }
            }
            else
            {
                //if (a[i] == '1' && b[j] == '1')
                if (carryOver)
                {
                    answer[pos] = '1';
                }
                else
                {
                    answer[pos] = '0';
                    carryOver = true;
                }
            }
        }
        calcOneDigit(i, pos, answer, a, carryOver);
        calcOneDigit(j, pos, answer, b, carryOver);
        if (carryOver)
        {
            answer[pos] = '1';
            pos--;
        }
        if (answer[0] == ' ')
        {
            answer = answer.erase(0, 1);
        }
        return answer;
    }
};
