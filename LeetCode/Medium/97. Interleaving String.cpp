class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return 0;

        bool dp[s2.size() + 1];
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 and j == 0)
                    dp[j] = 1;
                else if (i == 0)
                    dp[j] = dp[j - 1] and s2[j - 1] == s3[i + j - 1];
                else if (j == 0)
                    dp[j] = dp[j] and s1[i - 1] == s3[i + j - 1];
                else
                    dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or
                            (dp[j - 1] and s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[s2.size()];
    }
};