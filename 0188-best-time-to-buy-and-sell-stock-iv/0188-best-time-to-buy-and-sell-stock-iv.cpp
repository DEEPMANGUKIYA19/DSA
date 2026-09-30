 class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        for(int t = 1; t <= k; t++) {
            dp[t][0] = 0;
            dp[t][1] = -prices[0];
        }

        for(int i = 1; i < n; i++) {
            for(int t = 1; t <= k; t++) {
                dp[t][0] = max(dp[t][0], dp[t][1] + prices[i]);
                dp[t][1] = max(dp[t][1], dp[t-1][0] - prices[i]);
            }
        }

        return dp[k][0];
    }
};