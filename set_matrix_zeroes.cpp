class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int GcRow = -1;
        int GcCol = -1;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (GcRow == -1)
                    {
                        GcRow = i;
                        GcCol = j;
                    }
                    else
                    {
                        matrix[GcRow][j] = 0;
                        matrix[i][GcCol] = 0;
                    }
                }
            }
        }
        if (GcRow != -1 && GcCol != -1)
        {
            for (int i = 0; i < matrix[GcRow].size(); i++)
            {
                if (matrix[GcRow][i] == 0 && GcCol != i)
                {
                    for (int j = 0; j < matrix.size(); j++)
                    {
                        matrix[j][i] = 0;
                    }
                }
            }
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][GcCol] == 0 && GcRow != i)
                {
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][GcCol] = 0;
            }
            for (int i = 0; i < matrix[GcRow].size(); i++)
            {
                matrix[GcRow][i] = 0;
            }
        }
    }
};
