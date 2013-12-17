class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = -1<<30;
        int currSum = 0;
        for (int i = 0; i < n ; i++)
        {
            if (currSum < 0)
            {
                currSum = A[i];
            }
            else
            {
                currSum += A[i];
            }
            if (currSum > maxSum)
            {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
};
