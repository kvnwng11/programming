class Solution {
   private:
    int binarySearch(vector<int>& sub, int num) {
        int left = 0;
        int right = sub.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (sub[mid] < num)
                left = mid + 1;
            else if (sub[mid] > num)
                right = mid;
            else
                return mid;
        }
        return left;
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.reserve(nums.size());
        sub.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            if (num > sub.back())
                sub.push_back(num);
            else
                sub[binarySearch(sub, num)] = num;
        }

        return sub.size();
    }
};