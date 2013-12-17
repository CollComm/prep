class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0;
        int r = n;
        vector<int> answer;
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
        if (r == n || A[r] != target)
        {
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }
        else
        {
            answer.push_back(r);
        }
        l = 0;
        r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] < target)
            {
                l = mid + 1;
            }
            else if (A[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid;
                if (r - l == 1)
                {
                    r--;
                }
            }
        }
        if (r == n || A[r] != target)
        {
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }
        else
        {
            answer.push_back(r);
        }
        return answer;
    }
};
