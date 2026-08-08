class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> ht;

        for (auto& num : nums) {
            ht[num]++;
        }

        int len = 0, maxi = 0;
        for (auto& entry : ht) {
            int key = entry.first;
            if (ht.count(key - 1) == 0) {
                len = 1;
                key++;
                while (ht.count(key)) {
                    len++;
                    key++;
                }
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};
