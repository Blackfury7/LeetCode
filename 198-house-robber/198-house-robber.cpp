class Solution {
public:
    int money(vector<int>& nums, int i, vector<int>& dp){
        if(nums.size()==1) nums[0];
        if(i >=nums.size() )return 0;
        
        if(dp[i] !=-1)return dp[i];
        
        int l =0;
        l= nums[i] + money(nums, i+2, dp);
        int r =0;
        if(i+1<nums.size())
        r = nums[i+1] + money(nums, i+3, dp);
        return dp[i] = max(l,r);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
         return money(nums,0,dp);
        // return max_element(dp.begin(), dp.end());
    }
};