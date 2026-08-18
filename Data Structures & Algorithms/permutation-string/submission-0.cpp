class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) {
            return false;
        }

        int l = 0, r = 0;
        unordered_map<char, int> um1, um2;
        for (auto& i : s1) {
            um1[i]++;
        }

        while (r < n2) {
            while (r < l + n1 && r < n2) {
                um2[s2[r]]++;
                r++;
            }
            if (um1 == um2) {
                return true;
            }
            um2[s2[l]]--;
            if (um2[s2[l]] == 0) {
                um2.erase(s2[l]);
            }
            l++;
        }

        return false;
    }
};
