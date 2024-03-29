class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left)/2;

            if (nums[mid] < target) {
                left = mid+1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                return mid;
            }
        }

        return left;
    }

};