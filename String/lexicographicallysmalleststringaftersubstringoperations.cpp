class Solution {
public:
    string smallestString(string s) {
        int i=0;
        int n=s.length();
        if(s[i]!='a'){
            while(i<n&&s[i]!='a'){
                s[i]-=1;
                i++;
            }
            return s;
        }else{
            while(i<n&&s[i]=='a'){
                i++;
            }
            if(i==n){
                s[i-1]='z';
            }
            while(i<n){
                if(s[i]!='a'){
                    s[i]-=1;
                }else{
                    break;
                }
                i++;
            }
        }
        return s;
    }
};