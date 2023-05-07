class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>se;
        se.insert('a');
        se.insert('e');
        se.insert('i');
        se.insert('o');
        se.insert('u');
        int count=s.length()-k+1;
        int i=0;
        int result=INT_MIN;
        string temp=s.substr(i,k);
        int num=0;
        for(int j=0;j<temp.length();j++){
            if(se.find(temp[j])!=se.end())
            num++;
        }
        result=max(result,num);
        while(count--){
            if(se.find(s[i])!=se.end()){
                num--;
            }
            i++;
            if(se.find(s[i+k-1])!=se.end()){
                num++;
            }
            result=max(result,num);
        }
        return result;
    }
};