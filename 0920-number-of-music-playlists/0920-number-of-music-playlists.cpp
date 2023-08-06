class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        
        dp[0] = 1;
        
        for (int i = 1; i <= goal; i++) {
            vector<long long> new_dp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                new_dp[j] = (dp[j-1] * (n-j+1) + dp[j] * max(j-k, 0)) % mod;
            }
            dp = new_dp;
        }
        
        return dp[n];
    }
};