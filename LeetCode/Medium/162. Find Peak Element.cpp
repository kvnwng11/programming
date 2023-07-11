class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2) {
            if (nums[0] < nums[1])
                return 1;
            else
                return 0;
        }

        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;

        int left=0, right=nums.size();

        while (left < right) {
            int mid = left + (right-left)/2;

            // if peak
            if (nums[mid-1] < nums[mid] and nums[mid] > nums[mid+1])
                return mid;

            else if (nums[mid-1] > nums[mid]) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }

        return left;
    }
};