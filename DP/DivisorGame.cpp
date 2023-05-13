class Solution {
public:
    bool divisorGame(int n) {
        vector<bool>dp(n+1,false);
        dp[0]=false;
        dp[1]=false;
        dp[2]=true;
        dp[3]=false;
        for(int i=4;i<=n;i++){
            if(i%2!=0){
                dp[i]=!dp[i-1];
            }else{
                for(int j=1;j<=n/2;j++){
                    dp[i]=!dp[i-j];
                    if(dp[i]==true)
                    break;
                }
            }
        }
        return dp[n];
    }
};