class Solution {
public:
    int rob(vector<int>& nums) {
        // Approach -1 O(n) TC , O(n) SC
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
        // Approach -2 O(n) TC, O(1) SC
        int prev1=0;
        int prev2=0;
        int s=nums.size();
        vector<int>dp(s,-1);
        for(int i=0;i<s;i++){
            int temp=prev1;
            prev1=max(prev2+nums[i],prev1);
            prev2=temp;
        }
        return prev1;
        // https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/
    }
};
