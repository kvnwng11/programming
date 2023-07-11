class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i=1; i<nums.size(); ++i) {
            int new_value = 1;
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i])
                    new_value = max(new_value, dp[j] + 1);
            }
            dp[i] = new_value;
        }

        int ans = 1;
        for (int i=0; i<nums.size(); ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};