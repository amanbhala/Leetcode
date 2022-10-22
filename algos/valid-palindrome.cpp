class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" "||s=="")
            return true;
        int i=0;
        int j=s.size();
        string res="";
        while(i<j){
            if(char(s[i])>=65&&char(s[i])<=90)
                s[i]=tolower(s[i]);
            if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9')
                res+=s[i];
            i++;
        }
        cout<<res<<'\n';
        string copy=res;
        reverse(res.begin(),res.end());
        cout<<res;
        if(res==copy)
            return true;
        return false;
    }
};
