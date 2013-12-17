class Solution {
public:
    void sortColors(int A[], int n) {
        int redIndex = 0;
        int blueIndex = n - 1;
        for (int i = 0; i <= blueIndex ;)
        {
            if (A[i] == 0)
            {
                std::swap(A[i], A[redIndex]);
                redIndex++;
                i++;
            }
            else if (A[i] == 2)
            {
                std::swap(A[i], A[blueIndex]);
                blueIndex--;
            }
            else
            {
                i++;
            }
        }
    }
};
