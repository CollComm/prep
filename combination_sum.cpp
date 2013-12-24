class Solution {
    vector<vector<int>> answer;
    void findAllCombo(vector<int>&candidates, int pos, vector<int>& curSet, int target)
    {
        if (target == 0)
        {
            answer.push_back(curSet);
        }
        else
        {
            for (int i = pos; i < candidates.size(); i++)
            {
                if (target - candidates[i] < 0)
                {
                    return; 
                }
                else
                {
                    curSet.push_back(candidates[i]);
                    findAllCombo(candidates, i, curSet, target - candidates[i]);
                    curSet.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        answer.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> result;
        findAllCombo(candidates, 0, result, target);
        return answer;
    }
};
