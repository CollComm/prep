class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        int target = n - 1;
        while(target>=0)
        {
        int newTarget = -1;
        for(int i = target - 1; i >= 0; i--)
        {
            if (A[i] >= target - i)
            {
                newTarget = i;
            }
        }
        if (newTarget == 0)
        {
            return true;
        }
        else if (newTarget == -1)
        {
            return false;
        }
        else
        {
            target = newTarget;
        }
        }
        // Useless
        return false;
    }
};
