class Solution {
    bool isPalindrome(const string& s, int l, int r)
    {
        for (int i = 0; i < (r - l) / 2; i++)
        {
            if (s[i + l] != s[r - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    void partitionString(const string& s, int pos, vector<string> & res, vector<vector<string>>& ans)
    {
        if (pos >= s.length())
        {
            ans.push_back(res);
        }
        else
        {
            for (int i = pos + 1; i <= s.length(); i++)
            if (isPalindrome(s, pos, i))
            {
                res.push_back(s.substr(pos, i - pos));
                partitionString(s, i, res, ans);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> result;
        partitionString(s, 0, result, answer);
        return answer;
    }
};
