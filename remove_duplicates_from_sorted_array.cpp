class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        while (i < n - 1)
        {
            if (A[i] == A[i + 1])
            {
                for (int j = i; j < n - 1; j++)
                {
                    A[j] = A[j + 1];
                }
                n--;
            }
            else
            {
                i++;
            }
        }
        return n;
    }
};
