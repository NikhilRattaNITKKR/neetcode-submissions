class Solution {
   public:
    bool isValid(string s) {
        // if(s.size()==1) return false;
        stack<int> st;
        int a=0,b=0,c=0,d=0,e=0,f=0;

        for (int i = 0; i < s.size(); i++) {
            int key = s[i];


            switch (key) {
                case '(':
                    st.push(key);a++;
                    break;
                case '[':
                    st.push(key);b++;
                    break;
                case '{':
                    st.push(key);c++;
                    break;
                case '}':
                    if (st.size() > 0) {
                        if (st.top() != '{') return false;
                        st.pop();
                    }
                    d++;
                    break;
                case ']':
                    if (st.size() > 0) {
                        if (st.top() != '[') return false;
                        st.pop();
                    }
                    e++;
                    break;
                case ')':
                    if (st.size() > 0) {
                        if (st.top() != '(') return false;
                        st.pop();
                    }f++;
                    break;
            }
        }

        if (st.size() || a!=f || b!=e || c!=d ) {
            return false;
        }
        return true;
    }
};
