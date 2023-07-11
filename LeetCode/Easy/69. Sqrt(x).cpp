class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int ans = 1;
        while (((long)ans+1) * ((long)ans+1) <= x) {
            ans++;
        }
        return ans;
    }
};