class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int l = 0;
        int r = matrix.size();
        while(l<r)
        {
            int mid = (l + r) / 2;
            if (matrix[mid][0] < target)
            {
                l = mid + 1;
            }
            else if (matrix[mid][0] > target)
            {
                r = mid;
            }
            else
            {
                return true;
            }
        }
        int row = l - 1;
        if (row < 0)
        {
            return false;
        }
        l = 0;
        r = matrix[row].size();
        while(l<r)
        {
            int mid = (l + r) / 2;
            if (matrix[row][mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        int col = l;
        if (col == matrix[row].size())
        {
            return false;
        }
        if (matrix[row][col] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
