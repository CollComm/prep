class Solution {
    bool isMatch(string & s, string & p, int sPos, int pPos)
    {
        if (sPos == s.length() && pPos < p.length())
        {
            // Cases like .* should still work.
            if ((p.length() - pPos) >= 2 && p[pPos + 1] == '*')
            {
                return isMatch(s, p, sPos, pPos + 2);
            }
            else
            {
                return false;
            }
        }
        else if (sPos == s.length() && pPos == p.length())
        {
            return true;
        }
        else if (sPos < s.length() && pPos == p.length())
        {
            return false;
        }
        else
        {
            // Check *
            if ((p.length() - pPos) >= 2 && p[pPos + 1] == '*')
            {
                for (int i = 0; sPos + i < s.length(); i++)
                {
                    if (p[pPos] == '.' || p[pPos] == s[sPos + i])
                    {
                        if (isMatch(s, p, sPos + i + 1, pPos + 2))
                        {
                            return true;
                        }
                    }
                    else break;
                }
                return isMatch(s, p, sPos, pPos + 2);
            }
            else
            {
                // Check .
                if (p[pPos] == '.' || p[pPos] == s[sPos])
                {
                    return isMatch(s, p, sPos + 1, pPos + 1);
                }
                else
                {
                    return false;
                }
            }
        }
    }
public:
    bool isMatch(const char *s, const char *p) {
        string str_s(s);
        string str_p(p);
        return isMatch(str_s, str_p, 0, 0);
    }
};
