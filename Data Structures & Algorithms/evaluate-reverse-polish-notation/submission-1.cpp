class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string ele = tokens[i];
            if (ele != "+" && ele != "-" && ele != "*" && ele != "/") {
                st.push(stoi(ele));
            } else {
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                int res = 0;

                if (ele == "+") {
                    res = ele2 + ele1;
                } else if (ele == "-") {
                    res = ele2 - ele1;
                } else if (ele == "*") {
                    res = ele2 * ele1;
                } else {
                    res = ele2 / ele1;
                }

                st.push(res);
            }
        }
    return st.top();

    }
};
