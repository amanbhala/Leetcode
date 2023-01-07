class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        int i=0;
        for(i=len-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }else{
                digits[i]=0;
            }
        }
        if(i==-1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
