class Solution {
   public:
    int binarySearch(int l, int r, int target, vector<int>& nums) {
        if (l <= r) {
            int mid =l+ (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                return binarySearch(l, mid - 1, target, nums);
            else
                return binarySearch(mid + 1, r, target, nums);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(0,nums.size()-1,target,nums);
    }
};
