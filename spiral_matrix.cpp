class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int startX = 0;
        int startY = 0;
        int endX = matrix[0].size();
        int endY = matrix.size();
        while (startX < endX && startY < endY)
        {
            for (int i = startX; i < endX; i++)
            {
                ans.push_back(matrix[startY][i]);
            }
            startY++;
            for (int i = startY; i < endY; i++)
            {
                ans.push_back(matrix[i][endX - 1]);
            }
            endX--;
            if (startY < endY)
            {
                for (int i = endX - 1; i >= startX; i--)
                {
                    ans.push_back(matrix[endY - 1][i]);
                }
                endY--;
            }
            if (startX < endX)
            {
                for (int i = endY - 1; i >= startY; i--)
                {
                    ans.push_back(matrix[i][startX]);
                }
                startX++;
            }
        }
        return ans;
    }
};
