class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++)
        {
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            {
                int t = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = t;
            }
        }
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (A[i] - 1 != i)
            {
                break;
            }
        }
        if (i != n)
        {
            return i + 1;
        }
        else
        {
            return n + 1;
        }
    }
};
