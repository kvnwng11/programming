class Solution {
public:
    int binarySearchRow(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size();

        while (left < right) {
            int mid = left + (right-left)/2;

            if (matrix[mid][0] <= target and matrix[mid][matrix[0].size()-1] >= target) {
                return mid;
            }
            else if (matrix[mid][0] < target) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binarySearchRow(matrix, target);
        if (row == -1)
            return false;

        int left = 0, right = matrix[0].size();
        while (left < right) {
            int mid = left + (right-left)/2;

            if (matrix[row][mid] < target) {
                left = mid+1;
            }
            else if (matrix[row][mid] > target) {
                right = mid;
            }
            else {
                return true;
            }
        }

        return matrix[row][left] == target;
    }
};