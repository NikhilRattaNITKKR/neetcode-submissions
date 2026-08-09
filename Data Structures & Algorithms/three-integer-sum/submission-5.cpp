class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;
        set<vector<int>> resset;

        sort(nums.begin(), nums.end());

        for (int k = 0; k < n; k++) {
            set<vector<int>> tempres;
            int i = k+1, j = n - 1, target = -nums[k];
            while (i < j) {
                if (i == k) i++;
                if (j == k) j--;
                int sum = nums[i] + nums[j];
                if (sum < target)
                    i++;
                else if (sum > target)
                    j--;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    tempres.insert(temp);
                    i++;
                    j--;
                }
            }

            if (tempres.size()){ 
                for(auto &i:tempres)
                resset.insert(i);
            }
        }

        for (auto& i : resset) {
            res.push_back(i);
        }

        return res;
    }
};
