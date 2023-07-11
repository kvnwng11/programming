class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int size = citations.size();
        int count = 0;

        while (count < size and citations[size - 1 - count] > count) {
            count++;
        }

        return count;
    }
};