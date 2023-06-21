class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                right = mid-1;
            }
            else if (nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        if (left < nums.size() and nums[left] == target)
            return left;

        return -1;
    }

    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                left = mid+1;
            }
            else if (nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        if (left-1 < nums.size() and nums[left-1] == target)
            return left-1;

        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(lowerBound(nums, target));
        ans.push_back(upperBound(nums, target));
        return ans;
    }
};