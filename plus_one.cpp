class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool mark = false;
        digits[digits.size() - 1] = digits[digits.size() - 1] + 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i]>=10)
            {
                digits[i]%=10;
                if (i-1>=0)
                {
                    digits[i-1]++;
                }
                else
                {
                    mark = true;
                }
            }
        }
        if (!mark)
        {
            return digits;
        }
        else
        {
            vector<int> answer;
            answer.push_back(1);
            for (int i = 0; i < digits.size(); i++)
            {
                answer.push_back(digits[i]);
            }
            return answer;
        }
        return digits;
    }
};
