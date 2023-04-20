class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string> result;
        result.push_back("");
        const vector<string> dig = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(auto digit: digits){
            vector<string> tmp;
            for(auto character: dig[digit-'0']){
                for(auto s: result){
                    tmp.push_back(s+character);
                }
            }
            result.swap(tmp);
        }
        return result;
        
   }
};