class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int count[10];
        // Check rows
        for(int i = 0; i < board.size(); i++)
        {
            memset(count, 0, sizeof(count));
            for(int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j]!='.')
                {
                    count[board[i][j] - '0']++;
                    if (count[board[i][j] - '0'] >= 2)
                    {
                        return false;
                    }
                }
            }
        }
        // Check columns
        for(int i = 0; i < board.size(); i++)
        {
            memset(count, 0, sizeof(count));
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[j][i]!='.')
                {
                    count[board[j][i] - '0']++;
                    if (count[board[j][i] - '0'] >= 2)
                    {
                        return false;
                    }
                }
            }
        }
        // Check small grid
        int offsetX = 0;
        int offsetY = 0;
        for (int offsetX = 0; offsetX <= 6; offsetX+=3)
            for (int offsetY = 0; offsetY <= 6; offsetY+=3)
        {
            memset(count, 0, sizeof(count));
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[offsetX + i][offsetY + j]!='.')
                    {
                        count[board[offsetX + i][offsetY + j] - '0']++;
                        if (count[board[offsetX + i][offsetY + j] - '0'] >= 2)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
