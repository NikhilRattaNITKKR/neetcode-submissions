class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0 || n == 1) return n;

        int maxi = 1;
        int l = 0, r = 1;
        unordered_set<char> hs;
        hs.insert(s[l]);
        while (r < n) {
            while (hs.count(s[r]) > 0) {
                hs.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l+1);
            hs.insert(s[r]);
            r++;
        }
        return maxi;
    }
};
