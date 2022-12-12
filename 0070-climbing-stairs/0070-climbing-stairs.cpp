class Solution {
public:
//         int fun(int n, vector<int> &dp){
//          if(n<=1)return dp[n]=1;
//         if(dp[n] != -1) return dp[n];
        
//         int one = fun(n-1, dp);
//         int two = fun(n-2,dp);
        
//         return dp[n] = one + two;
//     }
//     int climbStairs(int n) {
//        vector<int> dp(n+1,-1);
//          fun(n,dp);
//         return dp[n];
//     }
    
    
     int climbStairs(int n) {
        int ar[n+2];
        ar[0] = 1; ar[1] = 2;
        for(int i=2;i<n;i++){
            ar[i] = ar[i-1] +  ar[i-2];
        }
        
        return ar[n-1];
    }
};