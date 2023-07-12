class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i=0; i<intervals.size(); ++i) {
            int start = intervals[i][0];
            while (i+i < intervals.size() and intervals[i][1] >= intervals[i+1][0]) i++;
            
            int end = intervals[i][1];
            
            vector<int> interval(2, start);
            interval[1] = end;
            ans.push_back(interval);
        }

        return ans;
    }
};