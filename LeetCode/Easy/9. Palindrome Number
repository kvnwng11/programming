class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 or (x % 10 == 0 and x != 0)) return 0;

        int rev = 0;
        while (x > rev) {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        
        return rev == x or x == rev/10;
    }
};