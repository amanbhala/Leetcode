class Solution {
public:
    int longestPalindrome(string s) {
        // Base test cases
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        if(s.length()==2){
            if(s[0]==s[1]){
                return 2;
            }else{
                return 1;
            }
        }
        // Iterate and store count of each element in a map
        map<char,int>m;
        int result=0;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        bool ispresent=false;
        int odd=0;
        int count=0;
        // If the element is present even times then add it to the result directly
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second%2==0){
                result+=it->second;
            }else{
                odd=max(odd,it->second);
            }
        }
        // Check the number of times maximum odd value is present.
        // Example: aaabbbcc, then we can add 'a' 3times and 'b' 2times or 'a' 2times and 'b' 3times
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==odd){
                count++;
            }
        }
        // Iterate again and check if the value is odd then:
        // 1. Is it the max odd value
        //   1.1. Only one count left, then add the value directly 
        //   1.2. Multiple counts left, then add (value-1)
        // 2. If it is not the max value, then add (value-1) 
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second%2==1){
                if(it->second==odd&&count==1){
                    result+=it->second;
                }else if(it->second==odd&&count>1){
                    result+=(it->second-1);
                    count--;
                }else{
                    result+=(it->second-1);
                }
            }
        }
        return result;
    }
};