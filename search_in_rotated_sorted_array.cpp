class Solution {
    int findPivotPoint(int A[], int low, int high)
    {
        int l = low;
        int r = high;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] > A[l])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
		if (r == high)
		{
			return -1;
		}
		else
		{
			return r;
		}
        
    }
    int binarySearch(int A[], int low, int high, int target)
    {
        int l = low;
        int r = high;
        while(l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (r == high)
        {
            return -1;
        }
        else
        {
            if (A[r] == target)
            {
                return r;
            }
            else
            {
                return -1;
            }
        }
    }
public:
    int search(int A[], int n, int target) {
        int pivot = findPivotPoint(A, 0, n);
        if (pivot != -1)
        {
            int pos = binarySearch(A, 0, pivot + 1, target);
            if (pos != -1)
            {
                return pos;
            }
            else
            {
                pos = binarySearch(A, pivot + 1, n, target);
                if (pos != -1)
                {
                    return pos;
                }
            }
            return -1;
        }
        else
        {
            return binarySearch(A, 0, n, target);
        }
    }
};
