class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }

        bool added = false;
        for (int i=0; i<intervals.size(); ++i) {
            // too far
            if (!added and intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);
                added = true;
            }
            // no overlap
            if (intervals[i][1] < newInterval[0] or intervals[i][0] > newInterval[1])
                ans.push_back(intervals[i]);
            // overlap
            else {
                int start = min(intervals[i][0], newInterval[0]);

                while (i+1 < intervals.size() and intervals[i+1][0] <= newInterval[1]) {
                    i++;
                }

                int end = max(newInterval[1], intervals[i][1]);
                vector<int> v(2, start);
                v[1] = end;
                ans.push_back(v);
                added = true;
            }
        }

        if (!added) ans.push_back(newInterval);

        return ans;
    }
};