class TimeMap {
   public:
    int bsearch(vector<pair<int, string>>& nums, int l, int r, int target) {
        int res = 0;
        int flag = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid].first == target) {
                return mid;
            } else if (nums[mid].first > target) {
                r = mid - 1;
            } else {
                if (nums[res].first <= nums[mid].first) {
                    res = mid;
                    flag = 1;
                }
                l = mid + 1;
            }
        }

        if (flag) return res;
        return -1;
    }
    unordered_map<string, vector<pair<int, string>>> tm;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (tm.count(key) > 0) {
            tm[key].push_back(make_pair(timestamp, value));
        } else {
            vector<pair<int, string>> temp;
            temp.push_back(make_pair(timestamp, value));
            tm[key] = temp;
        }
    }

    string get(string key, int timestamp) {
        if (tm.count(key) > 0) {
            int n = tm[key].size();
            int lastTimeStamp = (tm[key][n - 1]).first;

            if (lastTimeStamp <= timestamp) {
                string lastValue = (tm[key][n - 1]).second;
                return lastValue;
            } else {
                int res = bsearch(tm[key], 0, n - 1, timestamp);
                if (res == -1) return "";
                return (tm[key][res]).second;
            }

        } else {
            return "";
        }
    }
};
