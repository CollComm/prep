class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > Dmin;
        for (int i = 0; i < grid.size(); i++)
        {
            //row
            vector<int> emptyRow;
            Dmin.push_back(emptyRow);
            for (int j = 0; j < grid[i].size(); j++)
            {
                //column
                Dmin[i].push_back(1<<30);
            }
        }
        Dmin[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (j-1>=0)
                {
                    Dmin[i][j] = min(Dmin[i][j-1] + grid[i][j], Dmin[i][j]);
                }
                if (i-1>=0)
                {
                    Dmin[i][j] = min(Dmin[i-1][j] + grid[i][j], Dmin[i][j]);
                }
            }
        }
        return Dmin[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};
