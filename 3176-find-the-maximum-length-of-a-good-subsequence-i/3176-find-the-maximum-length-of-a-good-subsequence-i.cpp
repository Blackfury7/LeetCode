class Solution {
public:
    
    
    int dp[501][503][26];
    int helper(int ind, int prev, int n, vector<int>& nums, int k){
        if(ind == n)
            return 0;
        if(dp[ind][prev][k] != -1)
            return dp[ind][prev][k];
        int maxi = 0;
        if(prev == 502 || (nums[ind] == nums[prev])){
            maxi = max(maxi, 1 + helper(ind + 1, ind, n, nums, k));
            maxi = max(maxi, helper(ind + 1, prev, n, nums, k));
        }
        else if(nums[ind] != nums[prev]){
            if(k > 0)
                maxi = max(maxi, 1 + helper(ind + 1, ind, n, nums, k - 1));
            maxi = max(maxi, helper(ind + 1, prev, n, nums, k));
        }
        return dp[ind][prev][k] = maxi;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 502, n, nums, k);
    }
    
//     int dp[505][505][26];
 
//     int fun(int i, int last, int k,vector<int>&nums){
//         if(i <0 or k<0){
//             return 0;
//         }
//         if(dp[i][last+1][k] != -1) return dp[i][last+1][k];
        
//         int ans=0;
//         if(last == -1) {
//             // starting
//             ans = max(ans,fun(i-1, i, k, nums)+1);
//             // not starting
//             ans = max(ans, fun(i-1, -1, k, nums));
//         }
//         else{
//             //case 1
//             if(nums[i] == nums[last])
//               ans = max(ans,fun(i-1, i, k,nums)+1);

//             //case 2
//                 if(nums[i] != nums[last] and k>0)
//                     ans = max(ans, fun(i-1, i, k-1, nums)+1);

//             // case 3
//             ans = max(ans, fun(i-1, last, k, nums));
//         }
        
//         return dp[i][last+1][k]=ans;
                
//     }
        
        
        
        
    
    
//     int maximumLength(vector<int>& nums, int k) {
//         int n = nums.size();
           
        
//         for(int i=0;i<505;i++){
//             for(int j=0;j<505;j++){
//                 for(int x=0; x<26;x++){
//                     dp[i][j][x]=-1;
//                 }
//             }
//         }
            
//          return fun(n-1,-1, k, nums);     
        
//     }
};