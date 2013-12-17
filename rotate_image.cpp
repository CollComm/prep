#include<algorithm>
using namespace std;
class Solution {
    void circularMove(int offset, vector<vector<int> > &matrix, int length)
    {
        for (int i = 0; i < length - 1; i++)
        {
            int x = 0;
            int y = i;
            int tmp = matrix[x + offset][y + offset];
            matrix[x + offset][y + offset] = matrix[length-y + offset - 1][x + offset];
            matrix[length-y + offset - 1][x + offset] = matrix[length-x + offset - 1][length-y + offset - 1];
            matrix[length-x + offset - 1][length-y + offset - 1] = matrix[y + offset][length-x + offset - 1];
            matrix[y + offset][length-x + offset - 1] = tmp;
        }
    }
public:
    void rotate(vector<vector<int> > &matrix) {
        int length = matrix.size();
        int midPoint = length / 2;
        for (int i = 0; i < midPoint; i++)
        {
            circularMove(i, matrix, length - i*2);
        }
    }
};
