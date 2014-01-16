class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        vector<vector<int>> numof1Series;
        if (matrix.size() == 0) return 0;
        matrix.push_back(vector<char>());
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[matrix.size() - 1].push_back(0);
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            numof1Series.push_back(vector<int>());
            for (int j = 0; j < matrix[i].size(); j++)
            {
                numof1Series[i].push_back(0);
                if (matrix[i][j] == '1')
                {
                    if (j == 0)
                    {
                        numof1Series[i][j] = 1;
                    }
                    else
                    {
                        numof1Series[i][j] = numof1Series[i][j - 1] + 1;
                    }
                }
            }
        }
        int maxArea = 0;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            stack<int> s;
            for (int j = 0; j < matrix.size(); j++)
            {
                if (s.empty() || numof1Series[j][i] > numof1Series[s.top()][i]) s.push(j);
                else
                {
                    int currIndex = s.top();
                    s.pop();
                    maxArea = max(maxArea, numof1Series[currIndex][i] * (s.empty()? j : j - 1 - s.top()));
                    j--;
                }
            }
        }
        matrix.pop_back();
        return maxArea;
    }
};
