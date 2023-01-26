class Solution {
public:
        // Approach - 1 DP Memory Limit Exceeded
        if(nums[0]==0&&nums.size()==1)
        return 0;
        int product=nums[0];
        int maxproduct=product;
        int s=nums.size();
        vector<vector<int>> dp(s,vector<int> (s));
        for(int i=0;i<s;i++){
            dp[i][i]=nums[i];
            maxproduct=max(maxproduct,dp[i][i]);
        }
        for(int i=0;i<s-1;i++){
            for(int j=i+1;j<s;j++){
                dp[i][j]=dp[i][j-1]*nums[j];
                maxproduct=max(maxproduct,dp[i][j]);
            }
        }
        return maxproduct;
        // Approach -2 DP but we store maxarr and minarr till every position
        if(nums[0]==0&&nums.size()==1)
        return 0;
        int res=nums[0];
        int curmax=1;int curmin=1;
        for(int i=0;i<nums.size();i++){
            int temp=curmax*nums[i];
            curmax=max(nums[i]*curmax,nums[i]*curmin);
            curmax=max(curmax,nums[i]);
            curmin=min(temp,nums[i]*curmin);
            curmin=min(curmin,nums[i]);
            res=max(res,curmax);
        }
        return res;
    }
};
