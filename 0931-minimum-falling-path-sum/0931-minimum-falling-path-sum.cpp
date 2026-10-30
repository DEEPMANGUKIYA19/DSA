class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(n);

        for (int j = 0; j < n; j++) 
        {
            dp[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) 
        {
            vector<int> temp(n);

            for (int j = 0; j < n; j++) 
            {
                int up = dp[j];
                int left = (j > 0) ? dp[j - 1] : 1e9;
                int right = (j < n - 1) ? dp[j + 1] : 1e9;

                temp[j] = matrix[i][j] + min({up, left, right});
            }

            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};