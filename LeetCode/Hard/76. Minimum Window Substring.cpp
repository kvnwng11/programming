class Solution {
private:
    unordered_map<char, int> counts;

    struct pair {
        int pos;
        char c;
    };
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 or t.size() == 0 or s.size() < t.size())
            return "";

        // Initialize
        for (int i=0; i<t.size(); ++i) {
            counts[t[i]] += 1;
        }
        int ans[] = {-1, 0}; // [window size, left]
        int formed = 0;

        // Filter string
        vector<pair> filteredS;
        for (int i=0; i<s.length(); ++i) {
            char c = s[i];
            if (counts.find(c) != counts.end()) {
                filteredS.push_back({i, c});
            }
        }

        // Sliding window
        unordered_map<char, int> found; // Store unique letters
        int left = 0;
        for(int right = 0; right < filteredS.size(); ++right) {
            char c = filteredS[right].c;
            found[c] += 1;

            if (counts.find(c) != counts.end() and found[c] == counts[c])
                formed++;

            // Contract window
            while (left <= right and formed == counts.size()) {
                // New optimal answer
                int end = filteredS[right].pos;
                int start = filteredS[left].pos;
                if (ans[0] == -1 or end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                }

                // Remove from window
                char leftChar = filteredS[left].c;
                found[leftChar] -= 1;
                if (counts.find(leftChar) != counts.end() and found[leftChar] < counts[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return ans[0] == -1? "": s.substr(ans[1], ans[0]);
    }
};