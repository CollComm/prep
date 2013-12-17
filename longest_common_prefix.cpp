class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string answer;
        if (strs.size() == 0)
        {
            return answer;
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        int index = 0;
        int minLength = 1<<30;
        for (int i = 0; i < strs.size(); i++)
        {
            if (minLength > strs[i].length())
            {
                minLength = strs[i].length();
            }
        }
        for (int i = 0; i < minLength; i++)
        {
            bool isValid = true;
            bool isOccupied = false;
            char commonChar;
            for (int j = 0; j < strs.size(); j++)
            {
                if (isOccupied)
                {
                    if (strs[j][i] != commonChar)
                    {
                        isValid = false;
                        break;
                    }
                }
                else
                {
                    commonChar = strs[j][i];
                    isOccupied = true;
                }
            }
            if (isValid)
            {
                answer.push_back(commonChar);
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};
