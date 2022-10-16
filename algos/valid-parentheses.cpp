class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else if(s[i]==')'){
//    If stack is empty then return false, if stack is not empty and top element is not the correct pair then return false otherwise pop the element from stack
                if(st.empty()){
                    return false;
                }else if(!st.empty()&&st.top()!='('){
                    return false;
                }else{
                    st.pop(); 
                }   
            }else if(s[i]==']'){
                if(st.empty()){
                    return false;
                }else if(!st.empty()&&st.top()!='['){
                    return false;
                }else{
                    st.pop(); 
                }   
            }else if(s[i]=='}'){
                if(st.empty()){
                    return false;
                }else if(!st.empty()&&st.top()!='{'){
                    return false;
                }else{
                    st.pop(); 
                }   
            }   
        }
        
//         For inputs like "{" or "(" or "["
        if(st.empty())
            return true;
        else
            return false;
    }
};
