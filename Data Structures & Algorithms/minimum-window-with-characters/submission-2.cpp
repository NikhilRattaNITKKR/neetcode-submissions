class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) return "";

        // Required frequency
        vector<int> hmc(128, 0);

        // Current window frequency
        vector<int> hmt(128, 0);

        for (char c : t) {
            int key = (unsigned char)c;
            hmc[key]++;
        }

        int l = 0;
        int r = 0;

        int count = m;

        int mini = INT_MAX;

        string res = "";

        while (r < n) {
            // STEP 1: Expand until valid
            while (r < n && count > 0) {
                int key = (unsigned char)s[r];

                hmt[key]++;

                if (hmt[key] <= hmc[key]) {
                    count--;
                }

                r++;
            }

            // If we reached end without finding all characters
            if (count > 0) break;

            // STEP 2: Shrink unnecessary characters
            while (l < r) {
                int key = (unsigned char)s[l];

                if (hmc[key] == 0 || hmt[key] > hmc[key]) {
                    hmt[key]--;
                    l++;
                } else {
                    break;
                }
            }

            // STEP 3: Store minimum answer
            int len = r - l;

            if (len < mini) {
                mini = len;
                res = s.substr(l, len);
            }

            // STEP 4: Remove the required left character
            int key = (unsigned char)s[l];

            hmt[key]--;

            if (hmt[key] < hmc[key]) {
                count++;
            }

            l++;
        }

        return res;
    }
};