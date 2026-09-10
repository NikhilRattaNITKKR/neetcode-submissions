class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int l = 0, r = total - 1;
        int mid = l + (r - l) / 2;

        while (l <= r) {
            int i = mid / n;
            int j = mid % n;
            int ele = matrix[i][j];

            if (ele == target) {
                return true;
            } else if (ele < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            mid = l + (r - l) / 2;
        }

        return false;
    }
};
