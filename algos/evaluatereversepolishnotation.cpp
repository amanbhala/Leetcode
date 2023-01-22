class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int index=0;
        while(index<tokens.size()){
            if(tokens[index]!="+"&&tokens[index]!="-"&&tokens[index]!="*"&&tokens[index]!="/"){
                s.push(tokens[index]);
            }else{
                string operand2=s.top();
                s.pop();
                string operand1=s.top();
                s.pop();
                if(tokens[index]=="+"){
                    s.push(to_string(stoi(operand1)+stoi(operand2)));
                }else if(tokens[index]=="-"){
                    s.push(to_string(stoi(operand1)-stoi(operand2)));
                }else if(tokens[index]=="*"){
                    s.push(to_string(stoi(operand1)*stoi(operand2)));
                }else{
                    s.push(to_string(stoi(operand1)/stoi(operand2)));
                }
            }
            index++;
        }
        return stoi(s.top());
    }
};
