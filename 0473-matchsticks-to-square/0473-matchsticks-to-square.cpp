class Solution {
public:
    
    int dp[4][(1<<15)];
    int getsum(int mask, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) sum+=nums[i];
        }
        return sum;
    }
    bool fun(int i, int mask, int sum, vector<int>& nums) {
        if(i==3){
            return dp[i][mask]=(getsum(mask, nums) == sum);
        }
        if(dp[i][mask]  != -1) return dp[i][mask];
        
        bool ans = false;
        for(int submask = mask; submask; submask = (submask-1)&mask) {
            if(getsum(submask, nums) == sum) {
                ans |= fun(i+1, mask ^ submask, sum , nums);
            }
        }
        return dp[i][mask]=ans;  
    }
    
    
    bool makesquare(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(auto &i: nums) sum+=i;
        if(sum % 4)return false;
        int n = nums.size();
        return fun(0, (1<<n)-1, sum/4, nums);
    }
};