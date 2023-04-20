class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>stacks;
        stack<int>stackt;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                stacks.push(s[i]);
            }else{
                if(!stacks.empty())
                stacks.pop();
            }
        }
        string finals="";
        while(!stacks.empty()){
            finals+=stacks.top();
            stacks.pop();
        }
        for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                stackt.push(t[i]);
            }else{
                if(!stackt.empty())
                stackt.pop();
            }
        }
        string finalt="";
        while(!stackt.empty()){
            finalt+=stackt.top();
            stackt.pop();
        }
        return finals==finalt;
    }
};