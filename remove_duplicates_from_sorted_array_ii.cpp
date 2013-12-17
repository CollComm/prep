class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int total = n;
        int i = 0;
        while(i < total)
        {
            if (((i+1) < total) && ((i+2) < total) && A[i] == A[i + 1] && A[i+1] == A[i+2])
            {
                for(int j = i + 2; j + 1 < total; j++)
                {
                    A[j] = A[j + 1];
                }
                total--;
            }
            else if ((i+1)>=total || (i+2)>=total)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        return total;
    }
};
