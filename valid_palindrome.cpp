class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        string newS;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >='A' && s[i] <='Z')
            {
                newS.push_back('a' + s[i] - 'A');
            }
            else 
            {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                {
                    newS.push_back(s[i]);
                }
            }
        }
        for (int i = 0; i < newS.length() / 2; i++)
        {
            if (newS[i] != newS[newS.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
