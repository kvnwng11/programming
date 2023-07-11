class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int ans = INT_MAX, curr_sum = 0;
        int curr_size = 0;

        while (right < nums.size()) {
            curr_sum += nums[right];

            while (left < nums.size() and curr_sum >= target) {
                ans = min(ans, right - left + 1);
                curr_sum -= nums[left];
                left++;
            }

            right++;
        }

        return ans == INT_MAX? 0: ans;
    }
};