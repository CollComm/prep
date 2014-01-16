class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> minStockPrices;
        vector<int> maxStockPrices;
        vector<int> maxProfitLeft;
        vector<int> maxProfitRight;
        if (prices.size() == 1) return 0;
        int minPrice = 1 << 30;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            minStockPrices.push_back(minPrice);
            maxStockPrices.push_back(0);
            maxProfitLeft.push_back(0);
            maxProfitRight.push_back(0);
        }
        int maxPrice = -1;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] > maxPrice)
            {
                maxPrice = prices[i];
            }
            maxStockPrices[i] = maxPrice;
        }
        for (int i = 1; i < prices.size(); i++)
        {
            if (maxProfitLeft[i - 1] > prices[i] - minStockPrices[i])
            {
                maxProfitLeft[i] = maxProfitLeft[i - 1];
            }
            else
            {
                maxProfitLeft[i] = (prices[i] - minStockPrices[i]);
            }
        }
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            if (maxProfitRight[i + 1] > maxStockPrices[i] - prices[i])
            {
                maxProfitRight[i] = maxProfitRight[i + 1];
            }
            else
            {
                maxProfitRight[i] = maxStockPrices[i] - prices[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i + 1 < prices.size() && ans < maxProfitLeft[i] + maxProfitRight[i + 1])
            {
                ans = maxProfitLeft[i] + maxProfitRight[i + 1];
            }
            if (ans < maxProfitLeft[i])
            {
                ans = maxProfitLeft[i];
            }
            if (ans < maxProfitRight[i])
            {
                ans = maxProfitRight[i];
            }
        }
        return ans;
    }
};
