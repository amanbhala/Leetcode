class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current="";
        generateAll(current,n,n,result);
        return result;
    }
    
    void generateAll(string current, int open, int closed, vector<string>&result){
        if(open==0&&closed==0){
            result.push_back(current);
            return ;
        }
        if(open!=0){
            string output=current;
            output.push_back('(');
            generateAll(output,open-1,closed,result);
        }
        if(closed>open){
            string output=current;
            output.push_back(')');
            generateAll(output,open,closed-1,result);
        }
}
};
