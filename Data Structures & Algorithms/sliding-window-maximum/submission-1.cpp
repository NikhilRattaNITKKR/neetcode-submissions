class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            maxHeap.push(make_pair(nums[i], i));
            if (i + 1 >= k) {
                int index = (maxHeap.top()).second;
                int ele = (maxHeap.top()).first;
                while (index < (i + 1 - k) && !maxHeap.empty()) {
                    maxHeap.pop();
                    if (!maxHeap.empty()) {
                        index = (maxHeap.top()).second;
                        ele = (maxHeap.top()).first;
                    }
                }
                if (index >= (i + 1 - k)) res.push_back(ele);
            }
        }

        return res;
    }
};
