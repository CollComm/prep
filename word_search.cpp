struct Position
{
    int x;
    int y;
    int pos;
    Position(int u, int v, int p):x(u), y(v), pos(p){}
};
bool dfs(vector<vector<char>> & visited, Position p, vector<vector<char>> &board, string & word)
{
    if (p.pos == word.length() - 1)
    {
        return true;
    }
    visited[p.x][p.y] = 1;
    bool ans = false;
    if (p.x + 1 < board.size() && visited[p.x + 1][p.y] == 0 && board[p.x + 1][p.y] == word[p.pos + 1])
    {
        ans = dfs(visited, Position(p.x + 1, p.y, p.pos + 1), board, word);
    }
    if (ans) return true;
    if (p.x - 1 >= 0 && visited[p.x - 1][p.y] == 0 && board[p.x - 1][p.y] == word[p.pos + 1])
    {
        ans = dfs(visited, Position(p.x - 1, p.y, p.pos + 1), board, word);
    }
    if (ans) return true;
    if (p.y + 1 < board[0].size() && visited[p.x][p.y + 1] == 0 && board[p.x][p.y + 1] == word[p.pos + 1])
    {
        ans = dfs(visited, Position(p.x, p.y + 1, p.pos + 1), board, word);
    }
    if (ans) return true;
    if (p.y - 1 >= 0 && visited[p.x][p.y - 1] == 0 && board[p.x][p.y - 1] == word[p.pos + 1])
    {
        ans = dfs(visited, Position(p.x, p.y - 1, p.pos + 1), board, word);
    }
    if (ans) return true;
    visited[p.x][p.y] = 0;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) return true;
        if (board.size() == 0) return false;
        vector<vector<char>> visited;
        vector<Position> startPoints;
        bool existed = false;
        for (int i = 0; i < board.size(); i++)
        {
            visited.push_back(vector<char>());
            for (int j = 0; j < board[i].size(); j++)
            {
                visited[i].push_back(0);
                if (board[i][j] == word[0])
                {
                    startPoints.push_back(Position(i, j, 0));
                }
            }
        }
        for (int i = 0; i < startPoints.size(); i++)
        {
            existed = dfs(visited, startPoints[i], board, word);
            if (existed) break;
        }
        return existed;
        
    }
};
