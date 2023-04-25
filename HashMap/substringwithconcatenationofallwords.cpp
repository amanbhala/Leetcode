class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        int total=words.size();
        int size=words[0].length();
        int length=total*size;
        if(length>s.length()) return {};
        for(int i=0;i<=s.length()-length;i++){
            unordered_map<string,int>m;
            for(auto element: words){
                m[element]++;
            }
            int t=0;
            for(t=0;t<total;t++){
                string temp=s.substr(i+t*size,size);
                if(m.find(temp)==m.end()){
                    break;
                }else{
                    if(m[temp]!=0){
                        m[temp]--;
                    }else{
                        break;
                    }
                }
            }
            if(t==total){
                result.push_back(i);
            }
        }
        return result;
    }
};