class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths are not same return false
        if(s.length()!=t.length())
            return false;
        map<char,char>ms;
        map<char,char>mt;
        string check="";
        for(int i=0;i<s.length();i++){
// Check whether the aplhabet in string "s" is already present in the map "ms" or if the aplhabet in string "t" is already present in map "mt"
            if(ms.find(s[i])!=ms.end()||mt.find(t[i])!=mt.end()){
// If aplhabet is present in map "ms", then check what value is stored corresponding to it in map "mt" and compare it with currect alphabet value in string "s"
                char temp=(*ms.find(s[i])).second;
                if((*mt.find(temp)).second!=s[i])
                {
                    return false;
                }
                // Creating check for cases like foo and bar
                char c=ms[s[i]];
                check+=c;
            }
            else{
                check+=t[i];
                ms[s[i]]=t[i];
                mt[t[i]]=s[i];
            }
        }
        if(check!=t)
            return false;
        return true;
    }
};