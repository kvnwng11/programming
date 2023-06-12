class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 1;
        int prev = nums[0];
        int count = 1;

        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] == prev and count < 2) {
                nums[start] = nums[i];
                start++;
                count++;
            }
            else if (nums[i] != prev) {
                prev = nums[i];
                nums[start] = nums[i];
                start++;
                count = 1;
            }
        }

        return start;
    }
};