class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 or n == 0) return 1;
        if (x == 0) return 0;

        double ans = myPow(x, n/2);
        ans *= ans;

        if (n % 2 == 1)
            ans *= x;
        else if (n % 2 == -1)
            ans /= x;
        
        return ans;
    }
};