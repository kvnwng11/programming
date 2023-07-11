class RandomizedSet {
private:
    unordered_map<int, int> nums;
    vector<int> values;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (nums.find(val) == nums.end()) {
            values.push_back(val);

            nums[val] = values.size()-1;
            return 1;
        }

        return 0;
    }
    
    bool remove(int val) {
        if (nums.find(val) != nums.end()) {
            int last = values[values.size()-1];
            int remove_idx = nums[val];

            nums[last] = remove_idx;
            values[remove_idx] = last;

            nums.erase(val);
            values.pop_back();
            
            return 1;
        }

        return 0;
    }
    
    int getRandom() {
        return values[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */