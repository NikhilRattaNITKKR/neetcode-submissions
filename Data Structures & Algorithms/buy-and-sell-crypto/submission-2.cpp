class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int b = 0;
        int maxi = 0;
        int s = 1;

        while (s < prices.size()) {
            int profit = prices[s] - prices[b];
            if (profit >= 0) {
            maxi = max(maxi, profit);
            } else {
                b=s;
            }
            s++;
        }


        return maxi;
    }
};
