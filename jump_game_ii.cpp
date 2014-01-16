class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1)
        {
            return 0;
        }
        int target = n - 1;
        int cnt = 0;
        while(target > 0)
        {
            int minPos = target;
            for (int i = target - 1; i >= 0; i--)
            {
                if (A[i] >= (target - i))
                {
                    if (minPos > i)
                    {minPos = i;}
                }
            }
            cnt++;
            target = minPos;
        }
        return cnt;
    }
};
