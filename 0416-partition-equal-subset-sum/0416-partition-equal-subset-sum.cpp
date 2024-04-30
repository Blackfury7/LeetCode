class Solution {
public:
    int dp[205][20005];
    
    bool func(int sum, int ind, vector<int>& nums) {
        if(sum == 0) return true;
        if(ind < 0 ) return false;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool ans = func(sum, ind - 1, nums);
        
        if(sum >= nums[ind]){
            ans |= func(sum - nums[ind], ind - 1, nums);
        }
        
        return dp[ind][sum] = ans;
        
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)return false;
        memset(dp, - 1, sizeof(dp));
        sum >>= 1;
        
        return func(sum, nums.size() - 1, nums);
    }
};