// TLE
class Solution {
    int calculate(vector<vector<int>>& questions, int index){
        if(index>=questions.size())
        return 0;
        return max((questions[index][0]+calculate(questions,index+1+questions[index][1])),
        (calculate(questions,1+index)));
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return calculate(questions,0);
    }
};
// Recursice DP
class Solution {
    long long calculate(vector<vector<int>>& questions, int index, vector<long long>& dp){
        if(index>=questions.size())
        return 0;
        if(dp[index]!=0)
        return dp[index];
        return dp[index]=max((questions[index][0]+calculate(questions,index+1+questions[index][1],dp)),
        (calculate(questions,1+index,dp)));
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long > dp(questions.size(),0);
        return calculate(questions,0,dp);
    }
};
// DP
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        long long result=INT_MIN;
        vector<long long > dp(n,0);
        dp[n-1]=questions[n-1][0];
        result=max(result,dp[n-1]);
        for(int i=n-2;i>=0;i--){
            dp[i]=(max((questions[i][0]+((questions[i][1]+i+1<n)?dp[i+1+questions[i][1]]:0)),dp[i+1]));
            result=max(result,dp[i]);
        }
        return result;
    }
};