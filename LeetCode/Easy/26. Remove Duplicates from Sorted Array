class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int start = 1;
       int prev = nums[0];

       for (int i=1; i<nums.size(); ++i) {
           if (nums[i] != prev) {
               prev = nums[i];
               nums[start] = nums[i];
                start++;
           }
       }

       return start;
    }
};