class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int k, int left1, int right1, int left2, int right2) {
        if (right1 < left1) {
            return nums2[k - left1];
        }
        if (right2 < left2) {
            return nums1[k - left2];
        }

        int mid1 = left1 + (right1 - left1) / 2;
        int mid2 = left2 + (right2 - left2) / 2;
        int val1 = nums1[mid1];
        int val2 = nums2[mid2];

        if (mid1 + mid2 < k) {
            if (val1 > val2)
                return solve(nums1, nums2, k, left1, right1, mid2+1, right2);
            else
                return solve(nums1, nums2, k, mid1+1, right1, left2, right2);
        }
        else {
            if (val1 > val2) 
                return solve(nums1, nums2, k, left1, mid1-1, left2, right2);
            else
                return solve(nums1, nums2, k, left1, right1, left2, mid2-1);
        }  
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        if (n % 2) {
            return solve(nums1, nums2, n/2, 0, n1-1, 0, n2-1);
        }
        else {
            return 1.0 * (solve(nums1, nums2, n/2-1, 0, n1-1, 0, n2-1) + solve(nums1, nums2, n/2, 0, n1-1, 0, n2-1)) / 2;
        }
    }
};