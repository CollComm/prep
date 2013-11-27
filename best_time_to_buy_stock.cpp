class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int minP = 1<<30;
        int maxProfits = -1000;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minP)
            {
                minP = prices[i];
            }
            if ((prices[i] - minP) > maxProfits)
            {
                maxProfits = prices[i] - minP;
            }
        }
        if (maxProfits >= 0)
        {
            return maxProfits;
        }
        else
        {
            return 0;
        }
    }
};
