class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            int a1 = 1;
            int a2 = 2;
            int a3 = a1 + a2;
            for (int i = 0; i < n - 2; i++)
            {
                a3 = a1 + a2;
                a1 = a2;
                a2 = a3;
            }
            return a3;
        }

    }
};
