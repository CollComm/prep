class Solution {
    bool fillBoard(vector<vector<char>>& board)
    {
        int posToFillX = -1;
        int posToFillY = -1;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    posToFillX = i;
                    posToFillY = j;
                    break;
                }
            }
        }
        if (posToFillX == -1 && posToFillY == -1)
        {
            return true;
        }
        // Fill the grid
        int used = 0;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[posToFillX][i] != '.')
            {
                used |= (1 << (board[posToFillX][i] - '0'));
            }
            if (board[i][posToFillY] != '.')
            {
                used |= (1 << (board[i][posToFillY] - '0'));
            }
        }
		int baseX = posToFillX / 3;
		int baseY = posToFillY / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
        {
            if (board[baseX * 3 + i][baseY * 3 + j] != '.')
            {
                used |= (1 << (board[baseX * 3 + i][baseY * 3 + j] - '0'));
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if ((used & (1 << i)) == 0)
            {
            board[posToFillX][posToFillY] = i + '0';
            if (fillBoard(board))
            {
                return true;
            }
            board[posToFillX][posToFillY] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        fillBoard(board);
    }
};
