class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;
        int elei = heights[0];
        st.push(make_pair(0, elei));
        for (int i = 1; i < n; i++) {
            elei = heights[i];
            int toph = (st.top()).second;
            int topi = (st.top()).first;
            int lefti = i;
            while (toph > elei) {
                int w = i - topi;
                maxArea = max(maxArea, toph * w);
                lefti = topi;
                st.pop();
                if (!st.empty()) {
                    toph = (st.top()).second;
                    topi = (st.top()).first;

                } else {
                    toph = 0;
                }
            }
            st.push(make_pair(lefti, elei));
        }

        while (!st.empty()) {
            int toph = (st.top()).second;
            int topi = (st.top()).first;
            int lefti = n;
            int w = n - topi;
            maxArea = max(maxArea, toph * w);
            lefti = topi;
            st.pop();
            if (!st.empty()) {
                toph = (st.top()).second;
                topi = (st.top()).first;
            }
        }
        return maxArea;
    }
};
