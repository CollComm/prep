struct SortType
{
    string str;
    int pos;
    SortType(string&a, int b):str(a),pos(b){}
};
bool operator<(const SortType&a, const SortType&b)
{
	return a.str.compare(b.str)<0? true:false;
}
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> answer;
        vector<SortType> strMapping;
        bool runonce = true;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            strMapping.push_back(SortType(s, i));
        }
        sort(strMapping.begin(), strMapping.end());
        for (int i = 0; i < strMapping.size() - 1; i++)
        {
            if (strMapping[i].str.compare(strMapping[i + 1].str) == 0)
            {
                answer.push_back(strs[strMapping[i + 1].pos]);
                if (runonce)
                {
                    answer.push_back(strs[strMapping[i].pos]);
					runonce = false;
                }
            }
            else
            {
                runonce = true;
            }
        }
        return answer;
    }
};
