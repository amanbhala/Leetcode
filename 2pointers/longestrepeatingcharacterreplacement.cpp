class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;int r=0;int result=0;int maxfrequency=0; map<char,int>m;
        // We iterate over the array
        for(int r=0;r<s.length();r++){
            // We update the map
            m[s[r]]++;
            // If we see that the frequency of an element has increased, then we update maxfrequency variable's value
            if(m[s[r]]>maxfrequency){
                maxfrequency=m[s[r]];
            }
            // If we see that total length of the substring minus maximum frequency of a variable is less than or equal to k, then we update the result  
            if((r-l+1)-maxfrequency<=k){
                result=r-l+1;
            }else{
                // else we will update the left pointer, remove the element pointed by the left pointer
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
        }
        return result;
    }
};