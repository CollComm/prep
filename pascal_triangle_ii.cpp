class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;
        answer.push_back(1);
        if (rowIndex == 0) return answer;
        answer.push_back(1);
        if (rowIndex == 1) return answer;
        if (rowIndex >= 2)
        {
            for (int i = 1; i < rowIndex; i++)
            {
                queue<int> tmpStore;
                for (int j = 1; j < answer.size(); j++)
                {
                    tmpStore.push(answer[j - 1] + answer[j]);
                    if (tmpStore.size() == 2)
                    {
                        answer[j - 1] = tmpStore.front();
                        tmpStore.pop();
                    }
                }
                answer[answer.size() - 1] = tmpStore.front();
                tmpStore.pop();
                answer.push_back(1);
            }
        }
        return answer;
    }
};
