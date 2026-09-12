class Solution {
   public:
    int bsearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] > target) {
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {

            // Entire current range is sorted
            if (nums[l] <= nums[r]) {
                return bsearch(nums, l, r, target);
            }

            int m = l + (r - l) / 2;

            // Right half is sorted
            if (nums[m] <= nums[r]) {

                // Target lies inside sorted right half
                if (nums[m] <= target && target <= nums[r]) {
                    return bsearch(nums, m, r, target);
                }

                // Target must be in left half
                r = m - 1;
            }

            // Left half is sorted
            else {

                // Target lies inside sorted left half
                if (nums[l] <= target && target <= nums[m]) {
                    return bsearch(nums, l, m, target);
                }

                // Target must be in right half
                l = m + 1;
            }
        }

        return -1;
    }
};