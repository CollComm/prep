class Solution {
    vector<vector<int> > answer;
    void findCombo(vector<int>& currSet, int sum, int index, vector<int>& visited, int target, vector<int>&num)
    {
        if (sum == target)
        {
            answer.push_back(currSet);
        }
        else
        {
            for (int i = index; i < num.size(); i++)
            {
                if (visited[i] == 0 && sum + num[i] <= target)
                {
                    if ((i > 0 && num[i] == num[i-1] && visited[i-1] == 1) || (i == 0) || (i>0 && num[i] != num[i-1]))
                    {
                            currSet.push_back(num[i]);
                            visited[i] = 1;
                            findCombo(currSet, sum + num[i], i + 1, visited, target, num);
                            visited[i] = 0;
                            currSet.pop_back();                        
                    }
                }
                else
                {
                    if (sum + num[i] > target)
                    {
                        break;
                    }
                }
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        answer.clear();
        sort(num.begin(), num.end());
        vector<int> currSet;
        vector<int> visited;
        for (int i = 0; i < num.size(); i++)
        {
            visited.push_back(0);
        }
        findCombo(currSet, 0, 0, visited, target, num);
        return answer;
    }
};
