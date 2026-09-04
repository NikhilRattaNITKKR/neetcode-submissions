class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int countFleet = 1;
        int n = position.size();
        vector<pair<float, float>> postosp;
        vector<float> targetArr(n);
        for (int i = 0; i < n; i++) {
            postosp.push_back(make_pair(position[i], speed[i]));
        }

        sort(postosp.begin(), postosp.end());
        reverse(postosp.begin(), postosp.end());

        for (int i = 0; i < n; i++) {
            float pos = postosp[i].first;
            float sp = postosp[i].second;
            targetArr[i] = (target - pos) / sp;
        }

        float top = targetArr[0];
        for (int i = 1; i < n; i++) {
            float ele = targetArr[i];
            if (ele > top) {
                top = ele;
                countFleet++;
            }
        }
        return countFleet;
    }
};
