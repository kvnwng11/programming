class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int idx = digits.size()-1;
        while (idx >= 0) {
            int sum = digits[idx] + carry;
            carry = sum / 10;
            digits[idx] = sum % 10;
            idx--;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};