class Solution {
public:
    int check(string &s, int left, int right) {
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }


    string longestPalindrome(string s) {
        int ans1 = 0, ans2 = 0;

        for (int i=0; i<s.size(); ++i) {
            int left = i;
            int right = i;

            int res = check(s, left, right);
            if (ans2 - ans1 + 1 < res) {
                int dist = res/2;
                ans1 = left - dist;
                ans2 = right + dist;
            }

            right = i+1;
            res = check(s, left, right);
            if (ans2 - ans1 + 1 < res) {
                int dist = res/2 - 1;
                ans1 = left - dist;
                ans2 = right + dist;
            }
        }

        return s.substr(ans1, ans2-ans1+1);
    }
};