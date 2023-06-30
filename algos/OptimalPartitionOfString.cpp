class Solution {
public:
    int partitionString(string s) {
        int l=0;int r=s.length();
        set<char>se;
        string temp="";
        int count=1;
        while(l<r){
            if(se.find(s[l])!=se.end()){
                se.clear();
                count++;
            }
            se.insert(s[l++]);
        }
        return count;
    }
};