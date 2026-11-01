class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(cols, vector<int>(cols, 0));

        
        for (int j1 = 0; j1 < cols; j1++) 
        {
            for (int j2 = 0; j2 < cols; j2++) 
            {
                if (j1 == j2)
                    dp[j1][j2] = grid[rows - 1][j1];
                else
                    dp[j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
            }
        }

         
        for (int i = rows - 2; i >= 0; i--) 
        {
            vector<vector<int>> curr(cols, vector<int>(cols, 0));

            for (int j1 = 0; j1 < cols; j1++) 
            {
                for (int j2 = 0; j2 < cols; j2++) 
                {
                    int maxi = 0;
 
                    for (int d1 = -1; d1 <= 1; d1++) 
                    {
                        for (int d2 = -1; d2 <= 1; d2++) 
                        {
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if (nj1 >= 0 && nj1 < cols &&
                                nj2 >= 0 && nj2 < cols) 
                                {

                                maxi = max(maxi, dp[nj1][nj2]);
                            }
                        }
                    }

                    int cherries = grid[i][j1];

                    if (j1 != j2)
                        cherries += grid[i][j2];

                    curr[j1][j2] = cherries + maxi;
                }
            }

            dp = curr;
        }

        return dp[0][cols - 1];
    }
};