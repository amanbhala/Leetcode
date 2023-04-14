class Solution {
public:
    int climbStairs(int n) {
        // Recursion, TLE
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        else
            return climbStairs(n-1)+climbStairs(n-2);
        // If we create a 46 length vector, solution takes 2ms but if we create 45 length vector it takes 0ms
        // DP based solution
        vector<int> stairs(45,0);
        // stairs[0]=0;
        stairs[0]=1;
        stairs[1]=2;
        for(int i=2;i<n;i++){
            stairs[i]=stairs[i-1]+stairs[i-2];
        }
        return stairs[n-1];
    }
};