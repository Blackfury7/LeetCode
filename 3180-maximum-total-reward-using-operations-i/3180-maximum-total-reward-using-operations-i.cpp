class Solution {
public:
    // max sum will be (1999 + 2000)
    
    int dp[2000][4000];
    int fun(int i, int sum, vector<int>&nums) {
        if(i== nums.size()) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = fun(i+1, sum, nums);
        
        if(sum < nums[i]) {
            ans = max(ans, nums[i] + fun(i+1, sum + nums[i], nums));
        }
        
        return dp[i][sum]=ans;
    }
    int maxTotalReward(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        return fun(0, 0, nums);
    }
};