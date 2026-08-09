class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.size()-1;
        int j=n;
        while(i<j){
            while(!isalnum(s[i]) && i<=n)i++;
            while(!isalnum(s[j]) && j>=0)j--;

            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
    return true;
    }
};
