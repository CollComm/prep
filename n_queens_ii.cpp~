class Solution {
    vector<vector<string> > solutions;
    vector<string> transformBoard(vector<int>& board)
    {
        vector<string> answer;
        for (int i = 0; i < board.size(); i++)
        {
            string oneRow;
            for (int j = board.size() - 1; j >= 0; j--)
            {
                if ((board[i] & (1 << j)) == 0)
                {
                    oneRow.push_back('.');
                }
                else
                {
                    oneRow.push_back('Q');
                }
            }
            answer.push_back(oneRow);
        }
        return answer;
    }
    bool checkDiagnoal(int x, int y, vector<int>& board)
    {
        bool passTest = true;
        int t1 = x + 1;
        int t2 = y - 1;
        while(t1 < board.size() && t2 >= 0)
        {
            if ((board[t2] & (1 << t1)) != 0)
            {
                passTest = false;
                return passTest;
            }
            t1 ++;
            t2 --;
        }
        t1 = x + 1;
        t2 = y + 1;
        while(t1 < board.size() && t2 < board.size())
        {
            if ((board[t2] & (1 << t1)) != 0)
            {
                passTest = false;
                return passTest;
            }
            t1++;
            t2++;
        }
        return passTest;
    }
    void findSolutions(int queenLeft, vector<int>& board)
    {
        if (queenLeft == 0)
        {
            solutions.push_back(transformBoard(board));
        }
        else
        {
            for (int i = 0; i < board.size(); i++)
            {
                if (board[i] == 0)
                {
                    // Row must be available
                    if (checkDiagnoal(queenLeft - 1, i, board))
                    {
                        int tmp = board[i];
                        board[i] = (board[i] | (1 << (queenLeft - 1)));
                        findSolutions(queenLeft - 1, board);
                        board[i] = tmp;
                    }
                }
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        solutions.clear();
        vector<int> board;
        for (int i = 0; i < n; i++)
        {
            board.push_back(0);
        }
        findSolutions(n, board);
        return solutions;
    }
};
