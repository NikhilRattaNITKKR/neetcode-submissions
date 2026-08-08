class Solution {
   public:
    vector<int> lengths;

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& str : strs) {
            res += str;
            lengths.push_back(str.length());
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        for(auto &len:lengths){
           string temp= s.substr(i, len);      // "hello"       (5 chars starting at index 0)
           res.push_back(temp);
           i+=len;
        }
        return res;
    }
};
