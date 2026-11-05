class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0];
        int sell = 0;
        int prev = 0;

        for (int i = 1; i < n; i++) 
        {
            int temp = sell;

            sell = max(sell, buy + prices[i]);
            buy = max(buy, prev - prices[i]);

            prev = temp;
        }

        return sell;
    }
};