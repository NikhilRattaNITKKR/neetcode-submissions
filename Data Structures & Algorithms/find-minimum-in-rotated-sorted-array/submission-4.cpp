class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // no rotation case
        if (nums[0] <= nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        int mini = nums[0];
        while (l <= r) {
            if (nums[l] <= nums[r]) {
                mini = min(nums[l], mini);
                l=r+1;
            } else {
                int mid = l + (r - l) / 2;

                mini = min(nums[mid], mini);

                if (nums[l] <= nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid-1;
                }
            }
        }

        return mini;
    }
};
