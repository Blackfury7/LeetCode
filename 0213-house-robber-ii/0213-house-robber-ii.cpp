class Solution {
public:
    int n;
    int dp[105][2][2];
    
    int func(int ind, int isLastChoosen, int isFirstChoosen, vector<int>& v ){
        if(ind < 0) return 0;
        if(dp[ind][isLastChoosen][isFirstChoosen] != -1) 
            return dp[ind][isLastChoosen][isFirstChoosen];
        
        int ans = 0;
        // not choosing
        ans = func(ind - 1, 0, isFirstChoosen, v);
        
        // choosing only if last was not choosen (also taken care of cyclic condition)
        if(!isLastChoosen and ((ind != 0) or (ind == 0 and !isFirstChoosen)))  {
            if(ind == n-1) isFirstChoosen = 1; // for cyclic case - for last & first element
            
            ans = max(ans, func(ind -1, 1, isFirstChoosen, v) + v[ind]);
        }
        return dp[ind][isLastChoosen][isFirstChoosen] = ans; 
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
                
        // filling dp array with -1
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j < 2; j++)
                dp[i][j][0] = dp[i][j][1] = -1;

        
        return func(n-1, 0, 0, nums);
    }
};