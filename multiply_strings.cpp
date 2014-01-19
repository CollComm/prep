class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        for (int i = 0; i < num1.length() + num2.length(); i++)
        {
            result.push_back(0);
        }
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                result[(num1.length() - i - 1) + (num2.length() - j - 1)] += (num1[i] - '0') * (num2[j] - '0');
            }
            for (int j = 0; j < num1.length() + num2.length() - 1; j++)
            {
                if (result[j] >= 10) 
                {
                    result[j + 1] += (result[j] / 10);
                    result[j] = result[j]%10;
                }
            }
        }
        string ans;
        int i = num1.length() + num2.length() - 1;
        while (i >= 0 && result[i] == 0)
        {
            i--;
        }
        for (; i >= 0; i--)
        {
            ans.push_back(result[i] + '0');
        }
        if (ans.length() == 0)
        {
            return "0";
        }
        else return ans;
    }
};
