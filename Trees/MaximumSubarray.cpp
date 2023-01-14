class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        int maxsum=nums[0];
        int cursum=0;
        for(int i=0;i<nums.size();i++){
            // We check if the subarray till now is negative or not. If it is negative then we will not add it as it is not going to have any positive effect.
            if(cursum<0){
                cursum=0;
            }
            // We check if the current sum is not negative then we can add current value and then update our maxsum value.
            cursum+=nums[i];
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
    }
};
