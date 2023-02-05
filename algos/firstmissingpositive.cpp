class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Approach -1 - O(nlogn) TC , O(1) SC
        // sort(nums.begin(),nums.end());
        // int result=1;
        // for(int i=0;i<nums.size();){
        //     if(nums[i]<=0){
        //         i++;
        //         continue;
        //     }
        //     else if(nums[i]==result){
        //         // To check if we are reaching the end of the array
        //         while(i<nums.size()&&nums[i]==result)
        //             i++;
        //         result++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return result;
        // Approach -2 - O(n) TC, O(n) SC
        set<int>s;
        for(auto ele: nums){
            s.insert(ele);
        }
        int result=1;
        int si=nums.size();
        for(int i=1;i<=si+1;i++){
            if(s.find(i)==s.end()){
                result=i;
                break;
            }
        }
        return result;
    }
};
