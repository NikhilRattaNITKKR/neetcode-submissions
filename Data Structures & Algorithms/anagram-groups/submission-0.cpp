class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uom;

        for (string& str : strs) {
            vector<int> hash(26, 0);
            for (auto& a : str) {
                hash[a - 'a']++;
            }
            // key generation
            string key = to_string(hash[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(hash[i]);
            }
            uom[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& entry : uom) {
            res.push_back(entry.second);
        }

        return res;
    }
};
