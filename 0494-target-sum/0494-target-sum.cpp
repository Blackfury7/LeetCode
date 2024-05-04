                                                                                            class Solution {
public:
    int dp[21][4005];                                                                                        
    int func(int ind, int target, vector<int>& nums) {
        if(ind < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[ind][target + 2001] != -1) return dp[ind][target + 2001];
        
        return dp[ind][target+2001] = func(ind-1, target - nums[ind], nums) + func(ind-1, target + nums[ind], nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return func(nums.size() -1, target, nums);
    }
};