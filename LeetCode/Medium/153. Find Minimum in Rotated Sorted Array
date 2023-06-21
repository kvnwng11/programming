class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (mid-1 >= 0 and nums[mid-1] > nums[mid])
                return nums[mid];
            else if (nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid-1;
        }

        return nums[left];
    }
};