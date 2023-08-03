class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];

        dp[0][0] = grid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int val = i == 0 and j == 0 ? dp[0][0] : 0;
                if (grid[i][j] == 0) {
                    if (i > 0)
                        val += dp[i - 1][j];
                    if (j > 0)
                        val += dp[i][j - 1];
                }
                dp[i][j] = val;
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};