struct keyHash
{
	unsigned long operator()(const vector<int>& key) const {
        unsigned long hash = 0;
        for(size_t i=0; i<key.size(); i++)
            hash += (71*hash + key[i]) % 5;
        return hash;
    }
};
struct keyEqual
{
	bool operator()(const vector<int>& key1, const vector<int>& key2) const{
		if (key1.size() != key2.size())
		{
			return false;
		}
		else
		{
			for (unsigned int i = 0; i < key1.size(); i++)
			{
				if (key1[i] != key2[i])
				{
					return false;
				}
			}
			return true;
		}
	}
};
class Solution {
    vector<vector<int> > answer;
    unordered_set<vector<int>, keyHash, keyEqual> existed;

    void genPerm(vector<int> &num, int state, vector<int> currResult)
    {
        bool finished = true;
        int size = min(num.size(), (unsigned int)31);
        for (int i = 0; i < size; i++)
        {
            if ((state & (1 << i)) == 0)
            {
                // This position is zero
                finished = false;
				currResult.push_back(num[i]);
                genPerm(num, state | (1 << i), currResult);
				currResult.pop_back();
            }
        }
        if (finished)
        {
            if (existed.find(currResult) == existed.end())
            {
                existed.insert(currResult);
                answer.push_back(currResult);
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        answer.clear();
        existed.clear();
        vector<int> emptyAnswer;
        genPerm(num, 0, emptyAnswer);
        return answer;
    }
};
