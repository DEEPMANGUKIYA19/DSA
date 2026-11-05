class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;

        for (int i = 1; i < prices.size(); i++) 
        {
            int temp = sell;

            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, temp - prices[i]);
        }

        return sell;
    }
};