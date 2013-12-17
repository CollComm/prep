class Solution {
    bool isMatched(char a, char b)
    {
        if ((a == '(' and b == ')') || (a == '{' and b == '}') || (a == '[' && b == ']'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isOpenBrackets(char a)
    {
        if ((a == '(') || (a== '[') || (a == '{'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    bool isValid(string s) {
        stack<char> openBrackets;
        for(int pos = 0; pos < s.length(); pos++)
        {
            if (openBrackets.size() > 0)
            {
                if (isOpenBrackets(s[pos]))
                {
                    openBrackets.push(s[pos]);
                }
                else
                {
                    if (!isMatched(openBrackets.top(), s[pos]))
                    {
                        return false;
                    }
                    else
                    {
                        openBrackets.pop();
                    }
                }
            }
            else
            {
                if (isOpenBrackets(s[pos]))
                {
                    openBrackets.push(s[pos]);
                }
                else
                {
                    return false;
                }
            }
        }
        if (openBrackets.size() != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
};
