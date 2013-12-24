class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        int alphabet[26];
        for (int i = 0; i < 26; i++) alphabet[i] = -1;
        int from = 0;
        int maxLength = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (alphabet[s[i] - 'a'] > -1)
            {
                if (alphabet[s[i] - 'a'] >= from)
                {
                    maxLength = max(i - from, maxLength);
                    from = alphabet[s[i] - 'a'] + 1;
                }
            }
            alphabet[s[i] - 'a'] = i;
        }
        maxLength = max((int)s.length() - from, maxLength);
        return maxLength;
    }
};
