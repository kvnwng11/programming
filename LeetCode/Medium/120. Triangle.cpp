class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        int width = triangle[height-1].size();

        for (int i=height-2; i >= 0; --i) {
            for (int j=0; j<=i; ++j) {
                int idx1 = j;
                int idx2 = j + 1;

                triangle[i][j] += min(triangle[i+1][idx1], triangle[i+1][idx2]);
            }
        }

        return triangle[0][0];
    }
};