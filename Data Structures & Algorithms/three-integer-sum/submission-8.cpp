class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int k = 0; k < n; k++) {
            if (nums[k] > 0) break;
            // skip duplicates
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int l = k + 1, r = n - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else {
                    vector<int> temp;
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    l++;
                    r--;
                    while (l < r && nums[l - 1] == nums[l]) {
                        l++;
                    };

                    while (l < r && nums[r + 1] == nums[r]) {
                        r--;
                    };
                }
            }
        }

        return res;
    }
};
