class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        vector<int> minSumInclude;
        vector<int> newMinSumInclude;
        for (int i = 0; i < triangle.size(); i++)
        {
            minSumInclude.push_back(1<<30);
            newMinSumInclude.push_back(1<<30);
        }
        minSumInclude[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                newMinSumInclude[j] = 1 << 30;
            }
            for (int j = 0; j < triangle[i - 1].size(); j++)
            {
                newMinSumInclude[j] = min(minSumInclude[j] + triangle[i][j], newMinSumInclude[j]);
                newMinSumInclude[j + 1] = min(minSumInclude[j] + triangle[i][j + 1], newMinSumInclude[j + 1]);
            }
            for (int j = 0; j < triangle[i].size(); j++)
            {
                minSumInclude[j] = newMinSumInclude[j];
            }
        }
        int minSum = 1 << 30;
        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++)
        {
            if (minSum > minSumInclude[j])
            {
                minSum = minSumInclude[j];
            }
        }
        return minSum;
    }
};
