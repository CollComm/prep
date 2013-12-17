class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p1 = 0;
        int p2 = 0;
        int total = 0;
        for (int i = m - 1; i >= 0 ; i--)
        {
            A[i + n] = A[i];
        }
        p1 = n;
        while (p1 < m + n || p2 < n)
        {
            if (p1 >= m + n)
            {
                A[total] = B[p2];
                p2++;
                total++;
            }
            else if (p2 >= n)
            {
                A[total] = A[p1];
                p1++;
                total++;
            }
            else
            {
                if (A[p1] < B[p2])
                {
                    A[total] = A[p1];
                    p1++;
                    total++;
                }
                else
                {
                    A[total] = B[p2];
                    p2++;
                    total++;
                }
            }
        }
    }
};
