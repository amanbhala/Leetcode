class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length())
        return {};
        map<char,int>pmap;
        map<char,int>smap;
        for(int i=0;i<p.length();i++){
            pmap[p[i]]++;
            smap[s[i]]++;
        }
        vector<int> res;
        if(pmap==smap){
            res.push_back(0);
        }
        int l=0;
        for(int r=p.length();r<s.length();r++){
            smap[s[l]]--;
            if(smap[s[l]]==0){
                smap.erase(s[l]);
            }
            l++;
            smap[s[r]]++;
            if(smap==pmap){
                res.push_back(l);
            }
        }
        return res;
    }
};