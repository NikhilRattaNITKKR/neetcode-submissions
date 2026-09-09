class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalArea = 0;

        int maxl = height[0];
        vector<int> maxlArr(n, 0);
        for (int l = 1; l < n; l++) {
            maxl = max(maxl, height[l-1]);
            maxlArr[l]=maxl;
        }

        int maxr = height[n - 1];
        vector<int> maxrArr(n, 0);
        for (int r = n - 2; r >= 0; r--) {
            maxr = max(maxr, height[r+1]);
            maxrArr[r]=maxr;
        }

        for (int i = 0; i < n; i++) {
            int minH = min(maxlArr[i], maxrArr[i]);
            if (minH > height[i]) {
                totalArea += minH - height[i];
            }
        }

        return totalArea;
    }
};
