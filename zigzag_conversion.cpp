class Solution {
public:
    string convert(string s, int nRows) {
        string* newRows = new string[nRows]();
        if (nRows == 1) return s;
        int curPos = 0;
        bool goDown = true;
        for (int i = 0; i < s.length(); i++)
        {
            newRows[curPos].push_back(s[i]);
            if (goDown)
            {
                curPos++;
            }
            else
            {
                curPos--;
            }
            if (curPos >= nRows)
            {
                goDown = !goDown;
                curPos = nRows - 2;
            }
            if (curPos < 0)
            {
                goDown = !goDown;
                curPos = 1;
            }
        }
        string ans;
        for (int i = 0; i < nRows; i++)
        {
            ans += newRows[i];
        }
        return ans;
    }
};
