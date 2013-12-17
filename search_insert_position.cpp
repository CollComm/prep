class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int r = n;
        int mid = (l + r) / 2;
        while(l<r)
        {
            mid = (l + r) / 2;
            if (A[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
};
