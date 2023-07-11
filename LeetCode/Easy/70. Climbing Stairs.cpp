class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int num1 = 1;
        int num2 = 2;
        for (int i = 3; i <= n; ++i) {
            int num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num2;
    }
};