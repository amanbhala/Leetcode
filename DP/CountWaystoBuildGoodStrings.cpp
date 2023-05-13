class Solution {
    long long mod = 1000000007;
    int tab(int low,int high,int zero ,int one){
        
        vector<int> dp(high+1,0);

        for(int i=high;i>=0;i--){
            int result = 0;
            if(i>=low and i<=high) result+=1;

            int appendZero = (i+zero<=high) ? dp[i+zero]%mod : 0;
            int appendOne = (i+one<=high) ? dp[i+one]%mod : 0 ;

            result += (appendZero+appendOne)%mod;

            dp[i]=result%mod;
        }

        return dp[0];
    }
    int memo(int i,int low ,int high,int zero,int one , vector<int> &dp){
        
        if(i>high) return 0;

        if(dp[i]!=-1) return dp[i];

        int result = 0;
        if(i>=low and i<=high) result+=1;

        int appendZero = memo(i+zero,low,high,zero,one,dp)%mod;
        int appendOne = memo(i+one,low,high,zero,one,dp)%mod;

        result += (appendZero+appendOne)%mod;

        return dp[i]=result%mod;

    }
    int good(int i, int low, int high, int zero, int one){
        if(i>high) return 0;
        int result = 0;
        if(i>=low and i<=high) result+=1;

        int appendZero = good(i+zero,low,high,zero,one)%mod;
        int appendOne = good(i+one,low,high,zero,one)%mod;

        result += (appendZero+appendOne)%mod;

        return result%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // return good(0,low,high,zero,one);

        // vector<int> dp(high+1,-1);
        // return memo(0,low,high,zero,one,dp);

        return tab(low,high,zero,one);
    }
};