class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 1) return 1;

        int l = 0, r = 1;
        unordered_map<char, int> hm;
        hm[s[l]]++;
        int mfec = 1;
        int maxi = 1;
        while (r < n) {
            hm[s[r]]++;

            mfec = max(hm[s[r]], mfec);

            int lor = (r - l + 1) - mfec;
            if (lor <= k) {
                maxi = max(maxi, r - l + 1);
            } else {
                hm[s[l]]--;
                l++;
            }
            r++;
        }
        return maxi;
    }
};
