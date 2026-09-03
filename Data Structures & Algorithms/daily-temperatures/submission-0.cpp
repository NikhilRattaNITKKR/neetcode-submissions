class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        st.push(make_pair(temperatures[0], 0));
        for (int i = 1; i < n; i++) {
            int ele = temperatures[i];
            pair<int, int> topPair = st.top();
            int topIndex = topPair.second;
            int top = topPair.first;
            while (ele > top && st.size()) {
                st.pop();
                ans[topIndex] = i - topIndex;
                if (st.size()) {
                    topPair = st.top();
                    topIndex = topPair.second;
                    top = topPair.first;
                }
            }
            st.push(make_pair(ele, i));
        }

    return ans;
    }

};
