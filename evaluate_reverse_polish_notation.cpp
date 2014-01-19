class Solution {
    void getTopTwo(stack<int>&s, int&a, int&b)
    {
        a = s.top(); 
        s.pop();
        b = s.top();
        s.pop();
    }
    int getInt(string& s)
    {
        int sum = 0;
        for (int i = (s[0] == '-')?1:0; i < s.length(); i++)
        {
            sum *= 10;
            sum += (s[i] - '0');
        }
        return (s[0] == '-')?-sum:sum;
    }
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<int> s;
        int a = 0;
        int b = 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            switch(tokens[i][0])
            {
                case '+': 
                getTopTwo(s, a, b);
                s.push(a+b);
                break;
                case '-':
                if (tokens[i].length() == 1)
                {
                    getTopTwo(s, a, b);
                    s.push(b - a);
                }
                else
                {
                    s.push(getInt(tokens[i]));
                }
                break;
                case '*':
                getTopTwo(s, a, b);
                s.push(a * b);
                break;
                case '/':
                getTopTwo(s, a, b);
                s.push(b / a);
                break;
                default:
                s.push(getInt(tokens[i]));
            }
        }
        return s.top();
    }
};
