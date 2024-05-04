class Solution {
public:
    int n;
    int dp[105][2][2];
    int func(int ind, int isLastChoosen, int isFirstChoosen, vector<int>& v ){
        if(ind <0) return 0;
        if(dp[ind][isLastChoosen][isFirstChoosen] != -1) 
            return dp[ind][isLastChoosen][isFirstChoosen];
        
        int ans = 0;
        ans = func(ind - 1, 0, isFirstChoosen, v);
        if(!isLastChoosen)  {
            if(ind == n-1) isFirstChoosen = 1;
            if((ind != 0) or (ind == 0 and !isFirstChoosen))
            ans = max(ans, func(ind -1, 1, isFirstChoosen, v) + v[ind]);
        }
        return dp[ind][isLastChoosen][isFirstChoosen] = ans; 
    }
    
    int rob(vector<int>& nums) {
        
        n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 2; j++){
                dp[i][j][0] = dp[i][j][1] =-1;
            }
        }
        return func(n-1, 0, 0, nums);
    }
};