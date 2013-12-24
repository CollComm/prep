class Solution {
public:
    double pow(double x, int n) {
        double iterX = x;
        double ans = 1;
        int absN = abs(n);
        for (int i = 0; i <= 30; i++)
        {
            if ((1<<i & absN) != 0)
            {
                ans *= iterX;
            }
            iterX = iterX * iterX;
        }
        if (n > 0)
        {
            return ans;
        }
        else
        {
            return 1 / ans;
        }
    }
};
