class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &p, vector<int> &q){return p[1] < q[1];});

        int ans = 1;
        int first_end = points[0][1];
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0] > first_end) {
                first_end = points[i][1];
                ans++;
            }
        }

        return ans;
    }
};