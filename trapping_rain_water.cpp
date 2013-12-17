class Solution {
public:
    int trap(int A[], int n) {
        vector<int> leftLargestHeight;
        leftLargestHeight.push_back(0);
        for (int i = 0; i < n; i++)
        {
            if (A[i] > leftLargestHeight[i])
            {
                leftLargestHeight.push_back(A[i]);
            }
            else
            {
                leftLargestHeight.push_back(leftLargestHeight[i]);
            }
        }
        int totalTrapWater = 0;
        int rightLargestHeight = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            totalTrapWater += (min(leftLargestHeight[i], rightLargestHeight) - A[i]) > 0?(min(leftLargestHeight[i], rightLargestHeight) - A[i]):0;
            if (A[i] > rightLargestHeight)
            {
                rightLargestHeight = A[i];
            }
        }
        return totalTrapWater;
    }
};
