class SummaryRanges {
private:
    set<int> vals;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vals.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if (vals.empty()) return {};
        vector<vector<int>> intervals;
        int left = -1, right = -1;
        for (int val : vals) {
            if (left < 0)
                left = right = val;
            else if (val == right+1)
                right = val;
            else{
                intervals.push_back({left, right});
                left = right = val;
            }
        }
        intervals.push_back({left, right});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */