class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int start = 0;
       int k = 0;

       for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                int temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;

                start++;
                k++;
            }
       }

       return k;
    }
};