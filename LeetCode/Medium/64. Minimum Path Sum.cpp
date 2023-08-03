class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                dp[i][j] = grid[i][j];
                if (j > 0 and i > 0) {
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                } else if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                } else if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};