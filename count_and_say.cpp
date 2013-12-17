class Solution {
    string getString(int num)
    {
        string target;
        int cnt = 1;
        while(num>=cnt)
        {
            cnt*=10;
        }
        while(num>0)
        {
            cnt/=10;
            target.push_back('0' + (char)num/cnt);
            num = num%cnt;
        }
        return target;
    }
    string genNewStr(string prev)
    {
        string newStr;
        int cnt = 1;
        for (int i = 1; i < prev.length(); i++)
        {
            if (prev[i] == prev[i - 1])
            {
                cnt++;
            }
            else
            {
                newStr.append(getString(cnt));
                newStr.push_back(prev[i-1]);
                cnt = 1;
            }
        }
        newStr.append(getString(cnt));
        newStr.push_back(prev[prev.length() - 1]);
        return newStr;
    }
public:
    string countAndSay(int n) {
        string answer;
        answer.push_back('1');
        if (n == 1) return answer;
        for (int i = 1; i < n; i++)
        {
            answer = genNewStr(answer);
        }
        return answer;
    }
};
