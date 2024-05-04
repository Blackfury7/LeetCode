class Solution {
public:

    int dp[105];
    
    int func(int ind, int last_index, vector<int>& v ){
        if(ind < last_index) return 0;
        if(dp[ind] != -1) return dp[ind];
        // max of two choices: choosing and not choosing
        return dp[ind] =  max(func(ind - 1, last_index, v), func(ind -2, last_index, v) + v[ind]) ; 
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        memset(dp, -1, sizeof(dp));
        
        // made two separate cases if last is choosen or not
        int ans = func(n-1, 1, nums);
        
        memset(dp, -1, sizeof(dp));
        
        return max(ans, func(n-2, 0, nums));
    }
    
 // ************************************************************************************************   
//     int n;
//     int dp[105][2];
    
//     int func(int ind, int isFirstChoosen, vector<int>& v ){
//         if(ind < 0) return 0;
//         if(dp[ind][isFirstChoosen] != -1) 
//             return dp[ind][isFirstChoosen];
        
//         int ans = 0;
//         // not choosing
//         ans = func(ind - 1, isFirstChoosen, v);
        
//         // choosing
//         if(ind != 0 or !isFirstChoosen)  {
//             if(ind == n-1) isFirstChoosen = 1; // for cyclic case - for last & first element
            
//             ans = max(ans, func(ind -2, isFirstChoosen, v) + v[ind]);
//         }
//         return dp[ind][isFirstChoosen] = ans; 
//     }
    
//     int rob(vector<int>& nums) {
//         n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return func(n-1, 0, nums);
//     }
};