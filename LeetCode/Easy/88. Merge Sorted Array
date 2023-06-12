class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1 = m - 1;
        int last2 = n - 1;
        int ptr = n + m - 1;

        while (last1 >= 0 and last2 >= 0) {
            if (nums1[last1] > nums2[last2]) {
                nums1[ptr] = nums1[last1];
                --last1;
            }
            else {
                nums1[ptr] = nums2[last2];
                --last2;
            }
            
            --ptr;
        }

        while (last1 >= 0) nums1[ptr--] = nums1[last1--];
        while (last2 >= 0) nums1[ptr--] = nums2[last2--];
    }
};