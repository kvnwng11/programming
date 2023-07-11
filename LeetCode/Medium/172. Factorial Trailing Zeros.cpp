class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long curr = 5;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};