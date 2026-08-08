class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (auto& str : strs) {
            res+=to_string(str.length());
            res+='#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
       
        int i=0;
        int j=0;

        while(i<s.size()){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            i=j+1;
            string temp=s.substr(i,length);
            res.push_back(temp);
            i=i+length;
        }

    
        return res;
    }
};
