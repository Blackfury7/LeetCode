class Solution {
public:
    int n;
    int dp[105][2];
    
    int func(int ind, int isFirstChoosen, vector<int>& v ){
        if(ind < 0) return 0;
        if(dp[ind][isFirstChoosen] != -1) 
            return dp[ind][isFirstChoosen];
        
        int ans = 0;
        // not choosing
        ans = func(ind - 1, isFirstChoosen, v);
        
        // choosing
        if(ind != 0 or !isFirstChoosen)  {
            if(ind == n-1) isFirstChoosen = 1; // for cyclic case - for last & first element
            
            ans = max(ans, func(ind -2, isFirstChoosen, v) + v[ind]);
        }
        return dp[ind][isFirstChoosen] = ans; 
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return func(n-1, 0, nums);
    }
};