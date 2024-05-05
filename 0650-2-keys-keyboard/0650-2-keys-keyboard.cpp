class Solution {
public:
    int N;
    int dp[1001][1001];
    int func(int ind, int copied) {
        if(ind == N) return 0;
        if(ind > N) return 1000;
        if(dp[ind][copied] != -1) return dp[ind][copied];
        
        int ans = 1e3;
        if(ind != copied)
        // copy
         ans = min(ans, func(ind, ind) + 1);
        
        // paste
        if(copied && ind + copied <= N)
        ans = min(ans, func(ind + copied, copied) + 1);
        
        return dp[ind][copied] = ans;
        
    }
    int minSteps(int n) {
        if(n==1) return 0;
        N = n;
        memset(dp, -1, sizeof(dp));
        
        return func(1 , 0);
        
    }
};