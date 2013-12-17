class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > dp;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            vector<int> emptyRow;
            bool blocked = false;
            for (int j = 0; j < obstacleGrid[i].size(); j++)
            {
                emptyRow.push_back(0);
            }
            dp.push_back(emptyRow);
        }
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] == 0)
            {
                dp[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {
            if (obstacleGrid[0][i] == 0)
            {
                dp[0][i] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid[i].size(); j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                if (i - 1 >= 0 && obstacleGrid[i-1][j] == 0)
                {
                    dp[i][j] = dp[i-1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j-1] == 0)
                {
                    dp[i][j] += dp[i][j-1];
                }
                }
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[obstacleGrid.size() - 1].size() - 1];
    }
};
