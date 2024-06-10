class Solution {
public:
    int dp[16][(1<<16)];
    int getsum(int mask, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) sum+=nums[i];
        }
        return sum;
    }
    bool fun(int i, int mask, int sum, int k, vector<int>& nums) {
        if(i==k){
            return dp[i][mask]=(getsum(mask, nums) == sum);
        }
        if(dp[i][mask]  != -1) return dp[i][mask];
        
        bool ans = false;
        for(int submask = mask; submask; submask = (submask-1)&mask) {
            if(getsum(submask, nums) == sum) {
                ans |= fun(i+1, mask ^ submask, sum, k, nums);
            }
        }
        return dp[i][mask]=ans;  
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        int sum=0;
        for(auto &i: nums) sum += i;
        if(sum % k) return false;
        int n = nums.size();
        return fun(1, (1<<n)-1, sum/k, k, nums);
    }
};