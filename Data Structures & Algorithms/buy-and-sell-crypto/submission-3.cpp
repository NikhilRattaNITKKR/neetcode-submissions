class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int i = 0;

        int maxP=0,minB = prices[i];

        while (i < prices.size()) {
            minB=min(minB,prices[i]);
            maxP=max(maxP,prices[i]-minB);
            i++;
        }

        return maxP;
    }
};
