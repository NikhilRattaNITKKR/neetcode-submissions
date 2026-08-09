class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            int lh = heights[l], rh = heights[r];
            int area = (r - l) * min(rh, lh);
            maxi = max(maxi, area);

            if (lh < rh) {
                l++;
            } else if (lh > rh) {
                r--;
            } else if (heights[l + 1] > heights[r - 1]) {
                l++;
            } else {
                r--;
            }
        }
        return maxi;
    }
};
