class Solution {
   public:
    int minEatingTime(int k, vector<int> piles, int h, int n) {
        int c = 0, i = 0;
        while (c <= h && i < n) {
            c += piles[i] / k;
            if (piles[i] % k > 0) {
                c++;
            }
            i++;
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // min eating speed=1;
        // max eating speed we know n<=h so it would max(piles)
        // then we just check using binary search from 1 to max(piles) and we got it

        int l = 1;
        int r = piles[0];
        int n = piles.size();

        for (int i = 1; i < n; i++) {
            r = max(r, piles[i]);
        }
        if (h == n) return r;

      
        int minES = r;
        while (l <= r) {
              int mid = l + (r - l) / 2;
            int minET = minEatingTime(mid, piles, h, n);
            if (minET <= h) {
                r = mid - 1;
                minES = min(minES, mid);
            } else if (minET > h) {
                l = mid + 1;
            }
        }

        return minES;
    }
};
