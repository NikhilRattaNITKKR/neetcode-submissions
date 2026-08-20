class MinStack {
   public:
    vector<int> st;
    vector<int> mst;
    MinStack() {}

    void push(int val) {
        if (st.size()) {
            int t = getMin();
            int mini = min(t, val);
            mst.push_back(mini);
        } else {
            mst.push_back(val);
        }
        st.push_back(val);
    }

    void pop() {
        st.pop_back();
        mst.pop_back();
    }

    int top() {
        int n = st.size() - 1;
        return st[n];
    }

    int getMin() {
        int n = mst.size() - 1;
        return mst[n];
    }
};
