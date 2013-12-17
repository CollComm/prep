class Solution {
    int findPivotPoint(int A[], int low, int high)
    {
        int l = low;
        int r = high;
        while(l<r)
        {
            int mid = (l + r) / 2;
			while(A[mid] == A[l] && mid > l)
            {
                l++;
            }
            if (A[mid] > A[l])
            {
                l = mid;
            }
            else if (A[mid] < A[l])
            {
                r = mid;
            }
			else
			{
				// mid == l
				l = mid;
				if ((l + r)/2 == l)
				{
					r = mid;
				}
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
    bool binarySearch(int A[], int low, int high, int target)
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
            return false;
        }
        else
        {
            if (A[r] == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
public:
    bool search(int A[], int n, int target) {
        int pivot = findPivotPoint(A, 0, n);
        if (pivot != -1)
        {
            return binarySearch(A, 0, pivot + 1, target) || binarySearch(A, pivot + 1, n, target);
        }
        else
        {
            return binarySearch(A, 0, n, target);
        }
    }
};
