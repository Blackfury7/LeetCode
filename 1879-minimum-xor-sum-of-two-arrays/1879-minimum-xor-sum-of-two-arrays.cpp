class Solution {
public:
    
    int dp[20][(1<<20)];
    
    int solve(int i, int mask, int n, vector<int>& nums1, vector<int>& nums2) {
        if(i == n) return 0;
        
        if(dp[i][mask] != -1) return dp[i][mask];
        
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(mask & (1<<j)){
                ans = min(ans, solve(i+1, (mask ^ (1<<j)), n, nums1, nums2) + (nums1[i] ^ nums2[j]));
            }
        }
        return dp[i][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, (1<<n)-1, n, nums1, nums2);
    }
};