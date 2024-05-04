class Solution {
public:
    int n;
    int dp[105][2][2];
    int func(int ind, int isLast, int isFirst, vector<int>& v ){
        if(ind <0) return 0;
        if(dp[ind][isLast][isFirst] != -1) return dp[ind][isLast][isFirst];
        
        int ans = 0;
        ans = func(ind - 1, 1, isFirst, v);
        if(isLast)  {
            if(ind == n-1) isFirst = 0;
            if((ind != 0) or (ind == 0 and isFirst))
            ans = max(ans, func(ind -1, 0, isFirst, v) + v[ind]);
        }
        return dp[ind][isLast][isFirst] = ans; 
    }
    
    int rob(vector<int>& nums) {
        
        n = nums.size();
        if(n==1) return nums[0];
        // memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 2; j++){
                dp[i][j][0] = dp[i][j][1] =-1;
            }
        }
        return func(n-1, 1, 1, nums);
    }
};