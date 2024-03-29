class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }

        // initialize window
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<char, int> window; // maps char to rightmost index

        // slide window
        while (right < s.size()) {
            char r = s[right];

            if (window[r] > 0) {
                left = max(window[r], left);
            }

            ans = max(ans, right-left+1);
            window[r] = right+1;
            right++;
        }

        return ans;
    }
};