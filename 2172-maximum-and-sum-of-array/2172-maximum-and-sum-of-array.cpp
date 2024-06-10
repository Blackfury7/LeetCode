class Solution {
public:
    int dp[20][(1<<18)];
    int fun(int i, int mask, int n, int k, vector<int>&nums){
        if(i > 2*k )return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        
        int ans = 0;
        int slot = (i+1)/2;
        for(int j = 0; j < n; j++){
                if(mask & (1<<j)){
                    ans = max(ans, fun(i+1, mask ^ (1<<j), n, k, nums) + (slot & nums[j]));
                }   
        }
        ans = max(ans, fun(i+1, mask, n, k, nums));
        
        return dp[i][mask] = ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return fun(1, (1<<n)-1, n, numSlots, nums);
        
    }
};