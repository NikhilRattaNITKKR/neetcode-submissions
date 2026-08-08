class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            prefix[i] = product;
            product *= nums[i];
        }

        product = 1;

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = product;
            product *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            res.push_back(suffix[i] * prefix[i]);
        }

        return res;
    }
};
