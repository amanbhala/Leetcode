class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string output="";
        solve(result,s,output);
        return result;
    }
    void solve(vector<string>& result, string input, string output){
        if(input.length()==0){
            result.push_back(output);
            return ;
        }
        if(isalpha(input[0])!=0){
            string output1=output+char(tolower(input[0]));
            string output2=output+char(toupper(input[0]));
            input.erase(input.begin()+0);
            solve(result,input,output1);
            solve(result,input,output2);
        }else{
            string output1=output+input[0];
            input.erase(input.begin()+0);
            solve(result,input,output1);
        }
        return ;
    }
};
