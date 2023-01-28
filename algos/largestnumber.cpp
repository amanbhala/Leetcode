class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result="";
        sort(nums.begin(),nums.end(),compare);
        if(nums.size()==1&&nums[0]==0)
        return "0";
        // If 0 is the first value then all the values are going to be 0 only, so we return 0 as the answer.
        if(nums[0]==0){
            return "0";
        }
        for(int i=0;i<nums.size();i++){
            result+=to_string(nums[i]);
        }
        return result;
    }
    static bool compare(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
};
