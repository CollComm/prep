class Solution {
    unordered_set<int> hashSet;
public:
    int longestConsecutive(vector<int> &num) {
        hashSet.clear();
        int maxLength = -1;
        for (int i = 0; i < num.size(); i++)
        {
            if (hashSet.find(num[i]) == hashSet.end())
            {
                hashSet.insert(num[i]);
            }
        }
        for (int i = 0; i < num.size(); i++)
        {
            int cnt = 1;
            if (hashSet.find(num[i]) != hashSet.end())
            {
                for (int j = 1; hashSet.find(num[i] + j) != hashSet.end(); j++)
                {
                    cnt ++;
                    hashSet.erase(num[i] + j);
                }
                for (int j = 1; hashSet.find(num[i] - j) != hashSet.end(); j++)
                {
                    cnt ++;
                    hashSet.erase(num[i] - j);
                }
                hashSet.erase(num[i]);
            }
            if (cnt > maxLength)
            {
                maxLength = cnt;
            }
        }
        return maxLength;
    }
};
