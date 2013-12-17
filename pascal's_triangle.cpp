class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > answer;
        if (numRows >= 1)
        {
            vector<int> oneLevel;
            oneLevel.push_back(1);
            answer.push_back(oneLevel);
            for (int i = 1; i < numRows; i++)
            {
                oneLevel.clear();
                oneLevel.push_back(1);
                for (int j = 1; j < answer[i - 1].size(); j++)
                {
                    oneLevel.push_back(answer[i-1][j-1] + answer[i-1][j]);
                }
                oneLevel.push_back(1);
                answer.push_back(oneLevel);
            }
        }
        return answer;
    }
};
