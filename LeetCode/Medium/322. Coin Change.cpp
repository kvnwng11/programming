class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for (int i=1; i<=amount; ++i) {
            int new_value = INT_MAX;
            for (int j=0; j<coins.size(); ++j) {
                if (i == coins[j]) {
                    new_value = 1;
                }
                else if (i - coins[j] >= 0 and dp[i-coins[j]] != -1) {
                    new_value = min(new_value, dp[i-coins[j]] + 1);
                }
            }
            if (new_value != INT_MAX)
                dp[i] = new_value;
        }

        return dp[amount];
    }
};