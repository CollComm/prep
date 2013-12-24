class Solution {
    vector<vector<int> > answer;
    void findAllPermutations(vector<int>& prev, vector<bool>& visited, vector<int> &numbers)
    {
        if (prev.size() == numbers.size())
        {
			answer.push_back(prev);
        }
        else
        {
            for (int i = 0; i < numbers.size(); i++)
            if (!visited[i])
            {
				if (i>0 && numbers[i] == numbers[i-1] && !visited[i-1])
				{
				    continue;
				}
				visited[i] = true;
                prev.push_back(numbers[i]);
                findAllPermutations(prev, visited, numbers);
                prev.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        answer.clear();
        sort(num.begin(), num.end());
        vector<int> emptyVector;
        vector<bool> visited;
        for(int i = 0; i < num.size(); i++)
        {
            visited.push_back(false);
        }
        findAllPermutations(emptyVector, visited, num);
        return answer;
    }
};
