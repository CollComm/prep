class Solution {
public:
    int getNumber(char c)
    {
        switch(c)
        {
            case 'I': return 1;break;
            case 'V': return 5;break;
            case 'X': return 10;break;
            case 'L': return 50;break;
            case 'C': return 100;break;
            case 'D': return 500;break;
            case 'M': return 1000;break;
        }
    }
    int romanToInt(string s) {
        int answer = 0;
        int i = 0;
        while (i < s.length())
        {
            if ((s[i] == 'I' && (i + 1 < s.length()) && (s[i+1] == 'V' || s[i+1] == 'X'))
             || (s[i] == 'X' && (i + 1 < s.length()) && (s[i+1] == 'L' || s[i+1] == 'C' ))
             || (s[i] == 'C' && (i + 1 < s.length()) && (s[i+1] == 'D' || s[i+1] == 'M' )))
            {
                answer += (getNumber(s[i+1]) - getNumber(s[i]));
                i+=2;
            }
            else
            {
                answer += getNumber(s[i]);
                i++;
            }
        }
        return answer;
    }
};
