class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for (auto& i : nums) {
            um[i]++;
        }

        vector<int> res;
        int n = nums.size();
        vector<vector<int>> occ(n + 1, res);

        for (auto& [key, value] : um) {
            occ[value].push_back(key);
        }

        for (int i = n; i >= 0; i--) {
            if (!occ[i].empty()) {
                int flag = 0;
                int s = occ[i].size();
                while (res.size() < k && !occ[i].empty()) {
                    res.push_back(occ[i].back());
                    occ[i].pop_back();
                }
            }
        }

        return res;
    }
};
