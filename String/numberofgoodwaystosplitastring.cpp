class Solution {
public:
    int numSplits(string s) {
        if(s.length()<=1)
        return 0;
        if(s.length()==2&&s[0]==s[1])
        return 0;
        if(s.length()==2&&s[0]!=s[1])
        return 1;
        set<char>s1;
        set<char>s2;
        unordered_map<char,int>m;
        // Add only first character in s1
        s1.insert(s[0]);
        // Add all the other characters in s2
        // Also add the character count in map
        for(int i=1;i<s.length();i++){
            s2.insert(s[i]);
            m[s[i]]++;
        }
        //Iterate from second character till the end of the string,
        //If sizes of set are equal, then increase the count,
        //else check the frequency of character in map, if it is zero then remove it from s2
        //and always insert the character in s1
        int l=1;
        int count=0;
        if(s1.size()==s2.size())
            count++;
        while(l<s.length()-1){
            if(s1.size()==s2.size())
            count++;
            m[s[l]]--;
            if(m[s[l]]==0){
                s2.erase(s2.find(s[l]));
                s1.insert(s[l]);
            }else{
                s1.insert(s[l]);
            }
            l++;
        }
        return count;
    }
};
// Second approach
int numSplits(string s) {
    unordered_map<char, int> mp1, mp2;
    for(auto ch:s) {
        // Add all the chars to map
        mp1[ch]++;
    }
    int count = 0;
    for(int i=0;i < s.length();i++) {
        // Decrease count in left window
        mp1[s[i]]--;
        // check if current char no longer exist in left window if not then delete it from map
        if(mp1[s[i]] == 0) mp1.erase(s[i]);
        // Increase count in right window
        mp2[s[i]]++;
        // Check if size of both map is same meaning both window have equal unique chars
        if(mp2.size() == mp1.size()) count++;
    }
    return count;
}