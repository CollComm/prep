class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        for (;i < n;)
        {
            if (A[i] != elem)
            {
                i++;
            }
            else
            {
                for (int j = i; j < n - 1; j++)
                {
                    A[j] = A[j + 1];
                }
                n--;
            }
        }
        return n;
    }
};
