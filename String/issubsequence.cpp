class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        for(i=0,j=0;i<s.length()&&j<t.length();j++){
            if(t[j]==s[i]){
                i++;
            }
        }
        if(j==t.length()&&i!=s.length()){
            return false;
        }
        return true;
    }
};