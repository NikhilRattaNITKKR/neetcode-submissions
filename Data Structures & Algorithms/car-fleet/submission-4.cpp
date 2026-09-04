class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<float, float>> postosp;
        for (int i = 0; i < n; i++) {
            postosp.push_back(make_pair(position[i], speed[i]));
        }

        sort(postosp.begin(), postosp.end());
        reverse(postosp.begin(), postosp.end());

        stack<float> st;

        for (int i = 0; i < n; i++) {
            float pos = postosp[i].first;
            float sp = postosp[i].second;
            float ele = (target - pos) / sp;
            if (st.empty()) {
                st.push((target - pos) / sp);
            } else {
                if (st.top() < ele) {
                    st.push(ele);
                }
            }
        }

        return st.size();
    }
};
