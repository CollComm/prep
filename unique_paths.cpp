class Solution {
public:
    int uniquePaths(int m, int n) {
        long long totalAns = 1;
        int initNum = 1;
        m--;
        n--;
        if (n == 0 || m == 0)
        {
            return 1;
        }
        for (int i = m + 1; i <= (m + n); i++, initNum++)
        {
            totalAns *= (long long)(i);
            totalAns /= (initNum);
        }
        return totalAns;
    }
};
