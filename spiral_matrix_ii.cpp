class Solution {
    void mov(int direction, int &x, int &y)
    {
        switch(direction)
        {
            case 0: x++; break;
            case 1: y++; break;
            case 2: x--; break;
            case 3: y--; break;
        }
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        // Init a empty matrix
        vector<vector<int> > matrix;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(0);
            }
            matrix.push_back(v);
        }
        // Fill the grids
        int x = 0, y = 0;
        int num = 1;int direction = 0;
        int lowBoundX = 0;
        int highBoundX = n;
        int lowBoundY = 0;
        int highBoundY = n;
        while(num <= n * n)
        {
            matrix[y][x] = num;
            num++;
            int newX = x;
            int newY = y;
            mov(direction, newX, newY);
            if (!(newX>=lowBoundX && newX < highBoundX && newY>=lowBoundY && newY < highBoundY))
            {
                direction++;
                direction%=4;
                newX = x;
                newY = y;
                mov(direction, newX, newY);
            }
            if (newX == lowBoundX && newY == lowBoundY)
            {
                lowBoundX ++;
                lowBoundY ++;
                highBoundX --;
                highBoundY --;
                newX = lowBoundX;
                newY = lowBoundY;
            }
            x = newX;
            y = newY;
        }
        return matrix;
    }
};
