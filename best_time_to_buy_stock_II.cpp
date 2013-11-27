class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int totalProfit = 0;
        bool isLookingForBuyingPoint = true;
        int buyingPoint = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (isLookingForBuyingPoint)
            {
                if (prices[i]>prices[i-1])
                {
                    buyingPoint = prices[i-1];
                    isLookingForBuyingPoint = false;
                }
            }
            else
            {
                if (prices[i]<prices[i-1])
                {
                    totalProfit += prices[i-1] - buyingPoint;
                    isLookingForBuyingPoint = true;
                }
            }
        }
        if (!isLookingForBuyingPoint)
        {
            totalProfit += prices[prices.size()-1] - buyingPoint;
        }
        return totalProfit;
    }
};
