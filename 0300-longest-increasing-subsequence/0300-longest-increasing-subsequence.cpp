class Solution {
public:
    
    int dp[2510];
    
    int lis(int i, vector<int>&a) {
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=0; j < i; j++) {
            if(a[i] > a[j])
                ans = max(ans, lis(j, a) + 1);
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans = max(ans, lis(i, a));
        }
        return ans;
    }
    
    
    
    
    // Binary Search approach
    // int lengthOfLIS(vector<int>& nums) {
    // vector<int> res;
    //     for(int i=0; i<nums.size(); i++) {
    //         auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    //         if(it==res.end()) res.push_back(nums[i]);
    //         else *it = nums[i];
    //     }
    //     return res.size();
    // }
    
    
    //***********************************************************************
    
    
    // Dp solution 
//     int lis(vector<int>&nums, int i, vector<int>&dp) {
//         if(dp[i] != -1) return dp[i];
//         int ans = 1;
//         for(int j = 0; j < i; j++) {
//             if(nums[i] > nums[j])
//                 ans = max(ans, lis(nums, j, dp) + 1);
//         }
//         return dp[i] = ans;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         vector<int>dp(n,-1);
        
//         for(int i = 0; i < n; i++) 
//             ans = max(ans, lis(nums, i, dp));
        
//         return ans;
//     }
};