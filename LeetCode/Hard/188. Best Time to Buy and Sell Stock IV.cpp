class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> profits(k + 1, 0);
        vector<int> costs(k + 1, INT_MAX);

        for (int price : prices) {
            for (int i = 1; i <= k; ++i) {
                costs[i] = min(costs[i], price - profits[i - 1]);
                profits[i] = max(profits[i], price - costs[i]);
            }
        }

        return profits[k];
    }
};