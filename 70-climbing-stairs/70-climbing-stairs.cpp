class Solution {
public:
        int fun(int n, vector<int> &dp){
         if(n<=1)return dp[n]=1;
        if(dp[n] != -1) return dp[n];
        
        int one = fun(n-1, dp);
        int two = fun(n-2,dp);
        
        return dp[n] = one + two;
    }
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
         fun(n,dp);
        return dp[n];
    }
};