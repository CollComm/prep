class Solution {
    int getInteger(string a)
    {
        int sum = 0;
        for (int i = 0; i < a.length(); i++)
        {
            sum *= 10;
            sum += a[i] - '0';
        }
        return sum;
    }
    void findValidIP(string & a, int pos, int partNum, string& currIP, vector<string> & ans)
    {
        for (int i = 1; i <= 3; i++)
        {
			if (pos + i > a.length()) break;
			string digits = a.substr(pos, i);
			if (digits.length() > 1 && digits[0] == '0') continue;
            int number = getInteger(digits);
            if (number > 255)
            {
                break;
            }
            else
            {
                currIP.append(a.substr(pos, i));
                if (partNum == 4)
                {
                    if (pos + i != (a.length()))
                    {
						for (int j = 0; j < i; j++)
						{
							currIP.pop_back();
						}
                    }
                    else
                    {
                        ans.push_back(currIP);
						for (int j = 0; j < i; j++)
						{
							currIP.pop_back();
						}
                    }
                }
                else
                {
                    currIP.push_back('.');
                    findValidIP(a, pos + i, partNum + 1, currIP, ans);
					for (int j = 0; j < i + 1; j++)
					{
						currIP.pop_back();
					}
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string empty;
        findValidIP(s, 0, 1, empty, ans);
		return ans;
    }
};
