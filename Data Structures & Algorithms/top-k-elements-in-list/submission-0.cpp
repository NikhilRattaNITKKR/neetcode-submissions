class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for (auto& i : nums) {
            um[i]++;
        }

        vector<int> res;

        for (int i = 0; i < k; i++) {
            int maxi = 0;
            int keyed=0;
            for (auto& [key, value] : um) {
                if(value>maxi){
                    maxi=value;
                    keyed=key;
                }
            }
            res.push_back(keyed);
            um[keyed] = 0;
        }

        return res;
    }
};
